#ifndef _EXEC_UTIL_H
#define _EXEC_UTIL_H

/*
    Copyright (C) 1995-2001 AROS - The Amiga Research OS
    $Id$

    Desc: Utility functions for exec.
    Lang: english
*/

#ifndef EXEC_TYPES_H
#   include <exec/types.h>
#endif

#ifndef EXEC_TASKS_H
struct Task;
#endif
#ifndef EXEC_LISTS_H
struct List;
#endif
#ifndef ETASK_H
struct IntETask;
#endif

/*
    Prototypes
*/
APTR Exec_AllocTaskMem (struct Task * task, ULONG size, ULONG flags, struct ExecBase *SysBase);
void Exec_FreeTaskMem (struct Task * task, APTR mem, struct ExecBase *SysBase);

void Exec_InitETask(struct Task *task, struct ETask *etask, struct ExecBase *SysBase);
struct Task *Exec_FindTaskByID(ULONG id, struct ExecBase *SysBase);
struct ETask *Exec_FindChild(ULONG id, struct ExecBase *SysBase);
struct IntETask *FindETask(struct List *, ULONG id, struct ExecBase *SysBase);

/*
 *  Pseudo-functions, including SysBase for nicer calling...
 */
#define AllocTaskMem(t,s,f) Exec_AllocTaskMem(t,s,f,SysBase)
#define FreeTaskMem(t,m)    Exec_FreeTaskMem(t,m,SysBase)
#define FindTaskByID(i)	    Exec_FindTaskByID(i,SysBase)
#define FindChild(i)	    Exec_FindChild(i,SysBase)
#define FindETask(l,i)	    Exec_FindETask(l,i,SysBase)
#define InitETask(t,e)	    Exec_InitETask(t,e,SysBase)

#endif /* _EXEC_UTIL_H */
