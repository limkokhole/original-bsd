/*-
 * Copyright (c) 1979, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#ifndef lint
static char sccsid[] = "@(#)TIME.c	8.1 (Berkeley) 06/06/93";
#endif /* not lint */

extern char *ctime();

TIME(alfap)

	register char *alfap;
{
	register char *ap, *cp;
	register int i;
	long a;

	time(&a);
	cp = ctime(&a);
	ap = alfap;
	for (cp = cp + 10, i = 10; i; *ap++ = *cp++, i--);
}
