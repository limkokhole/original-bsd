.\" Copyright (c) 1980, 1993
.\"	The Regents of the University of California.  All rights reserved.
.\"
.\" %sccs.include.redist.roff%
.\"
.\"	@(#)appen.C	8.1 (Berkeley) 06/08/93
.\"
.ie t .oh '\*(Ln Appendix A''PS1:19-%'
.eh 'PS1:19-%''\*(Ln Appendix A'
.el .he ''\fIAppendix A\fR''
.bp
.(x
.ti 0
.b "Appendix A"
.)x
.sh 1 "Examples" 1
.pp
Here we present a few examples
of how to use the package.
They attempt to be representative,
though not comprehensive.  Further examples can be found in the games section
of the source tree and in various utilities that use the screen such as 
.i systat(1) .
.sh 2 "Screen Updating"
.pp
The following examples are intended to demonstrate
the basic structure of a program
using the screen updating sections of the package.
Several of the programs require calculational sections
which are irrelevant of to the example,
and are therefore usually not included.
It is hoped that the data structure definitions
give enough of an idea to allow understanding
of what the relevant portions do.
.sh 3 "Simple Character Output"
.pp
This program demonstrates how to set up a window and output characters to it.
Also, it demonstrates how one might control the output to the window.  If
you run this program, you will get a demonstration of the character output
chracteristics discussed in the above Character Output section.
.(l I
.so t2.gr
.)l
.sh 3 "A Small Screen Manipulator"
.pp
The next example follows the lines of the previous one but extends then to 
demonstrate the various othe uses of the package.  Make sure you understand 
how this program works as it encompasses most of anything you will
need to do with the package.
.(l I
.so t3.gr
.)l
.sh 3 "Twinkle"
.pp
This is a moderately simple program which prints
patterns on the screen.
It switches between patterns of asterisks,
putting them on one by one in random order,
and then taking them off in the same fashion.
It is more efficient to write this
using only the motion optimization,
as is demonstrated below.
.(l I
.so twinkle1.gr
.)l
.sh 3 "Life"
.pp
This program fragment models the famous computer pattern game of life
(Scientific American, May, 1974).
The calculational routines create a linked list of structures
defining where each piece is.
Nothing here claims to be optimal,
merely demonstrative.
This code, however,
is a very good place to use the screen updating routines,
as it allows them to worry about what the last position looked like,
so you don't have to.
It also demonstrates some of the input routines.
.(l I
.so life.gr
.)l
.sh 2 "Motion optimization"
.pp
The following example shows how motion optimization
is written on its own.
Programs which flit from one place to another without
regard for what is already there
usually do not need the overhead of both space and time
associated with screen updating.
They should instead use motion optimization.
.sh 3 "Twinkle"
.pp
The
.b twinkle
program
is a good candidate for simple motion optimization.
Here is how it could be written
(only the routines that have been changed are shown):
.(l
.so twinkle2.gr
.)l
