/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)abs.s	5.1 (Berkeley) 05/30/85";
#endif not lint


/* abs - int absolute value */

#include "DEFS.h"

ENTRY(abs, 0)
	movl	4(ap),r0
	bgeq	1f
	mnegl	r0,r0
1:
	ret
