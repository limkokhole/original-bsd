#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation, advertising
# materials, and other materials related to such redistribution and
# use acknowledge that the software was developed by the University
# of California, Berkeley.  The name of the University may not be
# used to endorse or promote products derived from this software
# without specific prior written permission.  THIS SOFTWARE IS PROVIDED
# ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
# WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND
# FITNESS FOR A PARTICULAR PURPOSE.
#
# @(#)Makefile	5.3 (Berkeley) 9/20/88
#

CFLAGS=	-O -DKERBEROS
LIBC=	/lib/libc.a
SRC1=	kpasswd.c
OBJ1=	kpasswd.o
SRC2=	kpasswdd.c
OBJ2=	kpasswdd.o
OBJS=	kpasswd.o kpasswdd.o
MAN=	kpasswd.0 kpasswdd.0

all: kpasswd kpasswdd

kpasswd: ${OBJ1} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJ1} -lutil -lkrb -ldes

kpasswdd: ${OBJ2} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJ2} -lutil -lkrb -lkdb -ldes

clean:
	rm -f ${OBJS} core kpasswd kpasswdd

cleandir: clean
	rm -f ${MAN} tags .depend

depend: ${SRC1} ${SRC2}
	mkdep -p ${CFLAGS} ${SRC1} ${SRC2}

#install: ${MAN}
install:
	install -s -o bin -g bin -m 755 kpasswdd ${DESTDIR}/usr/libexec/kpasswdd
	install -s -o bin -g bin -m 755 kpasswd ${DESTDIR}/usr/athena
	install -c -o bin -g bin -m 444 kpasswd.0 ${DESTDIR}/usr/man/cat1
#	install -c -o bin -g bin -m 444 kpasswdd.0 ${DESTDIR}/usr/man/cat8

lint: ${SRC1} ${SRC2}
	lint ${CFLAGS} ${SRC1} ${SRC2}

tags: ${SRC1} ${SRC2}
	ctags ${SRC1} ${SRC2}
