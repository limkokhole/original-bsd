/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * %sccs.include.redist.c%
 *
 *	@(#)hexdump.h	8.1 (Berkeley) 06/06/93
 */

typedef struct _pr {
	struct _pr *nextpr;		/* next print unit */
#define	F_ADDRESS	0x001		/* print offset */
#define	F_BPAD		0x002		/* blank pad */
#define	F_C		0x004		/* %_c */
#define	F_CHAR		0x008		/* %c */
#define	F_DBL		0x010		/* %[EefGf] */
#define	F_INT		0x020		/* %[di] */
#define	F_P		0x040		/* %_p */
#define	F_STR		0x080		/* %s */
#define	F_U		0x100		/* %_u */
#define	F_UINT		0x200		/* %[ouXx] */
#define	F_TEXT		0x400		/* no conversions */
	u_int flags;			/* flag values */
	int bcnt;			/* byte count */
	char *cchar;			/* conversion character */
	char *fmt;			/* printf format */
	char *nospace;			/* no whitespace version */
} PR;

typedef struct _fu {
	struct _fu *nextfu;		/* next format unit */
	struct _pr *nextpr;		/* next print unit */
#define	F_IGNORE	0x01		/* %_A */
#define	F_SETREP	0x02		/* rep count set, not default */
	u_int flags;			/* flag values */
	int reps;			/* repetition count */
	int bcnt;			/* byte count */
	char *fmt;			/* format string */
} FU;

typedef struct _fs {			/* format strings */
	struct _fs *nextfs;		/* linked list of format strings */
	struct _fu *nextfu;		/* linked list of format units */
	int bcnt;
} FS;

extern FS *fshead;			/* head of format strings list */
extern int blocksize;			/* data block size */
enum _vflag { ALL, DUP, FIRST, WAIT };	/* -v values */

void	 add __P((char *));
void	 addfile __P((char *));
void	 badcnt __P((char *));
void	 badconv __P((char *));
void	 badfmt __P((char *));
void	 badsfmt __P((void));
void	 bpad __P((PR *));
void	 conv_c __P((PR *, u_char *));
void	 conv_u __P((PR *, u_char *));
void	 display __P((void));
void	 doskip __P((char *, int));
void	 err __P((const char *, ...));
void	*emalloc __P((int));
void	 escape __P((char *));
u_char	*get __P((void));
void	 newsyntax __P((int, char ***));
int	 next __P((char **));
void	 nomem __P((void));
void	 oldsyntax __P((int, char ***));
void	 rewrite __P((FS *));
int	 size __P((FS *));
void	 usage __P((void));
