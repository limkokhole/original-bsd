/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#ifndef lint
static char sccsid[] = "@(#)cgetc.c	5.4 (Berkeley) 06/01/90";
#endif /* not lint */

# include	<stdio.h>

char	cgetc(i)
int	i;
{
	return ( getchar() );
}
