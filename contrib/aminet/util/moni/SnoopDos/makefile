###############################################################################
#
#       Makefile for SAS/C 6.51                                 vi:ts=8
#
#       SnoopDos 3.0 Copyright (c) Eddy Carroll, 1994. Freely distributable.
#
#       See the SCOPTIONS file in this directory for default compiler options.
#
###############################################################################

NAME    = snoopdos
#GST     = snoopdos.gst

PROFILE = # mysprofutil.o
PROFOPT = # profile
DEBUG   = # DEBUG=FULL

CFLAGS  = $(PROFOPT) $(DEBUG) # Most flags are set in SCOPTIONS
AFLAGS  = incdir=include:
SFLAGS  = sc sd noicons map ram:map h x s f l o nd
LIBS    = lib:sc.lib # removed now....: lib:amiga.lib lib:debug.lib
STARTUP = LIB:c.o

#
#       Default rules
#
.c.o:
        sc $(CFLAGS) $*.c
        copy $*(.c|.h|.o|.i|.asm|.a) to sd: clone

.a.o:
        sc $(AFLAGS) underscore $*.a    # Prefix all symbols with C-style _
        copy $*(.c|.h|.o|.i|.asm|.a) to sd: clone

.s.o:
        sc $(AFLAGS) $*.s               # Standard "pure" assembly
        copy $*(.c|.h|.o|.i|.asm|.a) to sd: clone

.cd.h:
        catcomp $*.cd cfile $*.h
#
# Makefile dependencies
#

all: $(NAME) TestCalls

OBJS    = patches.o buffer.o snoopdos.o language.o settings.o   \
          mainwin.o subwin.o miscwin.o  hotkey.o   patchcode.o $(PROFILE)

$(NAME): $(OBJS)
        slink from $(STARTUP) $(OBJS) to $(NAME) $(SFLAGS) lib $(LIBS)
        copy MakeFile to sd:
        copy SnoopDos to sd:

clean:
        delete $(OBJS)

#$(GST):         system.h
snooptext.h:    snooptext.cd
patchcode.o:    patchcode.s
buffer.o:       buffer.c        snooptext.h     #snoopdos.h
snoopdos.o:     snoopdos.c      snooptext.h     snoopdos.h
language.o:     language.c      snooptext.h     #snoopdos.h
#windows.o:     windows.c       snooptext.h     #snoopdos.h
miscwin.o:      miscwin.c       snooptext.h     #snoopdos.h     gui.h
mainwin.o:      mainwin.c       snooptext.h     #snoopdos.h     gui.h
subwin.o:       subwin.c        snooptext.h     #snoopdos.h     gui.h
settings.o:     settings.c      snooptext.h     #snoopdos.h
hotkey.o:       hotkey.c        snooptext.h     icon.h  #snoopdos.h
patches.o:      patches.c       snooptext.h     #snoopdos.h

TestCalls:      testcalls.o
        slink from $(STARTUP) testcalls.o to TestCalls $(SFLAGS) lib $(LIBS)

testcalls.o:    testcalls.c


blank:
        catcomp snooptext.cd ctfile snooptext.ct-blank

english:
        catcomp snooptext.cd translation snoop-english.ct catalog catalogs/english/snoopdos.catalog nooptim

