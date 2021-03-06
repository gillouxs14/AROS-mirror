#include <clib/alib_protos.h>
#include <clib/asl_protos.h>
#include <clib/asl_protos.h>
#include <clib/commodities_protos.h>
#include <clib/diskfont_protos.h>
#include <clib/dos_protos.h>
#include <clib/exec_protos.h>
#include <clib/gadtools_protos.h>
#include <clib/graphics_protos.h>
#include <clib/icon_protos.h>
#include <clib/iffparse_protos.h>
#include <clib/intuition_protos.h>
#include <clib/keymap_protos.h>
#include <clib/locale_protos.h>
#include <clib/reqtools_protos.h>
#include <clib/timer_protos.h>
#include <clib/utility_protos.h>
#include <clib/wb_protos.h>
#include <ctype.h>
#include <dos/dostags.h>
#include <exec/execbase.h>
#include <exec/io.h>
#include <exec/memory.h>
#include <exec/types.h>
#include <graphics/displayinfo.h>
#include <graphics/gfxbase.h>
#include <graphics/gfxmacros.h>
#include <intuition/classes.h>
#include <intuition/classusr.h>
#include <intuition/gadgetclass.h>
#include <intuition/icclass.h>
#include <intuition/imageclass.h>
#include <intuition/intuition.h>
#include <intuition/intuitionbase.h>
#include <intuition/sghooks.h>
#include <libraries/asl.h>
#include <libraries/commodities.h>
#include <libraries/dos.h>
#include <libraries/gadtools.h>
#include <libraries/iffparse.h>
#include <libraries/locale.h>
#include <libraries/reqtools.h>
#include <pragmas/asl_pragmas.h>
#include <pragmas/commodities_pragmas.h>
#include <pragmas/diskfont_pragmas.h>
#include <pragmas/dos_pragmas.h>
#include <pragmas/exec_pragmas.h>
#include <pragmas/gadtools_pragmas.h>
#include <pragmas/graphics_pragmas.h>
#include <pragmas/icon_pragmas.h>
#include <pragmas/iffparse_pragmas.h>
#include <pragmas/intuition_pragmas.h>
#include <pragmas/locale_pragmas.h>
#include <pragmas/keymap_pragmas.h>
#include <pragmas/reqtools.h>
#include <pragmas/timer_pragmas.h>
#include <pragmas/utility_pragmas.h>
#include <pragmas/wb_pragmas.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <workbench/startup.h>
#include <workbench/workbench.h>
