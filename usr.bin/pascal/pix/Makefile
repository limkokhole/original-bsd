#	@(#)Makefile	8.1 (Berkeley) 06/06/93

PROG=	pix
SRCDIR=	${.CURDIR}/../src
SRCS=	pix.c
OBJS+=	config.o
CFLAGS+=-I${SRCDIR}
CLEANFILES+=config.c

WHOAMI=	pi

.include "${SRCDIR}/config.include"
.include <bsd.prog.mk>
