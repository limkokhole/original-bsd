divert(0)dnl
#
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988 The Regents of the University of California.
# All rights reserved.
#
# %sccs.include.redist.sh%
#
#	@(#)cf.m4	2.5 (Berkeley) 10/02/91
#


######################################################################
######################################################################
#####
#####		SENDMAIL CONFIGURATION FILE
#####
define(`TEMPFILE', maketemp(/tmp/cfXXXXXX))dnl
syscmd(sh ../sh/makeinfo.sh > TEMPFILE)dnl
include(TEMPFILE)dnl
syscmd(rm -f TEMPFILE)dnl
#####
######################################################################
######################################################################

divert(-1)

define(`PUSHDIVERT', `pushdef(`__D__', divnum)divert($1)')
define(`POPDIVERT', `divert(__D__)popdef(`__D__')')
define(`OSTYPE', `include(../ostype/$1.m4)')
define(`MAILER', `PUSHDIVERT(7)include(../mailer/$1.m4)POPDIVERT`'')
define(`DOMAIN', `include(../domain/$1.m4)')
define(`FEATURE', `include(../feature/$1.m4)')
define(`HACK', `include(../hack/$1.m4)')
define(`VERSIONID', ``#####  $1  #####'')
define(`LOCAL_RULE_3', `divert(2)')
define(`LOCAL_RULE_0', `divert(3)')
define(`UUCPSMTP', `R DOL(*) < @ $1 .UUCP > DOL(*)	DOL(1) < @ $2 > DOL(2)')
define(`CONCAT', `$1$2$3$4$5$6$7')
define(`DOL', ``$'$1')
define(`SITECONFIG',
`ifelse($2, -, `dnl', `CONCAT(D, $3, $2)')
define(`SITE', CONCAT(C, $3, DOL(1)))dnl
sinclude(../siteconfig/$1.m4)')
define(`LOCAL_NAME', `PUSHDIVERT(5)CL$1
POPDIVERT`'dnl')

m4wrap(`include(`../m4/proto.m4')')

divert(0)dnl
