/*
 * Copyright (c) 1988 University of Utah.
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * the Systems Programming Group of the University of Utah Computer
 * Science Department.
 *
 * %sccs.include.redist.c%
 *
 * from: Utah $Hdr: ite_gb.c 1.9 92/01/20$
 *
 *	@(#)ite_gb.c	7.3 (Berkeley) 06/18/92
 */

#include "samachdep.h"

#ifdef ITECONSOLE

#include "sys/param.h"

#include "hp/dev/itevar.h"
#include "hp/dev/itereg.h"
#include "../dev/grf_gbreg.h"

#define REGBASE     	((struct gboxfb *)(ip->regbase))
#define WINDOWMOVER 	gbox_windowmove

gbox_init(ip)
	register struct ite_softc *ip;
{
	REGBASE->write_protect = 0x0;
	REGBASE->interrupt = 0x4;
	REGBASE->rep_rule = RR_COPY;
	REGBASE->blink1 = 0xff;
	REGBASE->blink2 = 0xff;
	REGBASE->sec_interrupt = 0x01;

	/*
	 * Set up the color map entries. We use three entries in the
	 * color map. The first, is for black, the second is for
	 * white, and the very last entry is for the inverted cursor.
	 */
	REGBASE->creg_select = 0x00;
	REGBASE->cmap_red    = 0x00;
	REGBASE->cmap_grn    = 0x00;
	REGBASE->cmap_blu    = 0x00;
	REGBASE->cmap_write  = 0x00;
	gbcm_waitbusy(ip->regbase);
	
	REGBASE->creg_select = 0x01;
	REGBASE->cmap_red    = 0xFF;
	REGBASE->cmap_grn    = 0xFF;
	REGBASE->cmap_blu    = 0xFF;
	REGBASE->cmap_write  = 0x01;
	gbcm_waitbusy(ip->regbase);

	REGBASE->creg_select = 0xFF;
	REGBASE->cmap_red    = 0xFF;
	REGBASE->cmap_grn    = 0xFF;
	REGBASE->cmap_blu    = 0xFF;
	REGBASE->cmap_write  = 0x01;
	gbcm_waitbusy(ip->regbase);

	ite_fontinfo(ip);
	ite_fontinit(ip);

	/*
	 * Clear the display. This used to be before the font unpacking
	 * but it crashes. Figure it out later.
	 */
	gbox_windowmove(ip, 0, 0, 0, 0, ip->dheight, ip->dwidth, RR_CLEAR);
	tile_mover_waitbusy(ip->regbase);

	/*
	 * Stash the inverted cursor.
	 */
	gbox_windowmove(ip, charY(ip, ' '), charX(ip, ' '),
			ip->cblanky, ip->cblankx, ip->ftheight,
			ip->ftwidth, RR_COPYINVERTED);
}

gbox_putc(ip, c, dy, dx, mode)
	register struct ite_softc *ip;
        register int dy, dx;
	int c, mode;
{
	gbox_windowmove(ip, charY(ip, c), charX(ip, c),
			dy * ip->ftheight, dx * ip->ftwidth,
			ip->ftheight, ip->ftwidth, RR_COPY);
}

gbox_cursor(ip, flag)
	register struct ite_softc *ip;
        register int flag;
{
	if (flag == DRAW_CURSOR)
		draw_cursor(ip)
	else if (flag == MOVE_CURSOR) {
		erase_cursor(ip)
		draw_cursor(ip)
	}
	else
		erase_cursor(ip)
}

gbox_clear(ip, sy, sx, h, w)
	struct ite_softc *ip;
	register int sy, sx, h, w;
{
	gbox_windowmove(ip, sy * ip->ftheight, sx * ip->ftwidth,
			sy * ip->ftheight, sx * ip->ftwidth, 
			h  * ip->ftheight, w  * ip->ftwidth,
			RR_CLEAR);
}

#define	gbox_blockmove(ip, sy, sx, dy, dx, h, w) \
	gbox_windowmove((ip), \
			(sy) * ip->ftheight, \
			(sx) * ip->ftwidth, \
			(dy) * ip->ftheight, \
			(dx) * ip->ftwidth, \
			(h)  * ip->ftheight, \
			(w)  * ip->ftwidth, \
			RR_COPY)

gbox_scroll(ip, sy, sx, count, dir)
        register struct ite_softc *ip;
        register int sy;
        int dir, sx, count;
{
	register int height, dy, i;
	
	tile_mover_waitbusy(ip->regbase);
	REGBASE->write_protect = 0x0;

	gbox_cursor(ip, ERASE_CURSOR);

	dy = sy - count;
	height = ip->rows - sy;
	for (i = 0; i < height; i++)
		gbox_blockmove(ip, sy + i, sx, dy + i, 0, 1, ip->cols);
}

gbox_windowmove(ip, sy, sx, dy, dx, h, w, mask)
     register struct ite_softc *ip;
     int sy, sx, dy, dx, mask;
     register int h, w;
{
	register int src, dest;

	src  = (sy * 1024) + sx;	/* upper left corner in pixels */
	dest = (dy * 1024) + dx;

	tile_mover_waitbusy(ip->regbase);
	REGBASE->width = -(w / 4);
	REGBASE->height = -(h / 4);
	if (src < dest)
		REGBASE->rep_rule = MOVE_DOWN_RIGHT|mask;
	else {
		REGBASE->rep_rule = MOVE_UP_LEFT|mask;
		/*
		 * Adjust to top of lower right tile of the block.
		 */
		src = src + ((h - 4) * 1024) + (w - 4);
		dest= dest + ((h - 4) * 1024) + (w - 4);
	}
	FBBASE[dest] = FBBASE[src];
}
#endif
