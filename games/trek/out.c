/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#ifndef lint
static char sccsid[] = "@(#)out.c	5.2 (Berkeley) 05/05/88";
#endif /* not lint */

# include	"trek.h"

/*
**  Announce Device Out
*/

out(dev)
int	dev;
{
	register struct device	*d;

	d = &Device[dev];
	printf("%s reports %s ", d->person, d->name);
	if (d->name[length(d->name) - 1] == 's')
		printf("are");
	else
		printf("is");
	printf(" damaged\n");
}
