/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)r_exp.c	5.1	06/07/85
 */

double r_exp(x)
float *x;
{
double exp();
return( exp(*x) );
}
