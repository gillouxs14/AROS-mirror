/*
 * avoid conflicts between our __unused define and the ones that might come in
 * via sys/stat.h
 */
#undef __unused

#ifdef HOST_LONG_ALIGNED
#pragma pack(4)
#endif

#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

#pragma pack()

typedef int file_t;

#define INVALID_HANDLE_VALUE -1

#define LIBC_NAME   "libc.so.6"
#define DISK_DEVICE "/dev/hd%lc"
#define DISK_BASE   'a'

/* AROS includes don't define struct stat64, this shuts up warning when compiling host-independent part */
struct stat64;

struct HostInterface
{
    int            (*open)(char *path, int oflag, ...);
    int            (*close)(int filedes);
    ssize_t        (*read)(int fildes, void *buf, size_t nbyte);
    ssize_t        (*write)(int fildes, const void *buf, size_t nbyte);
    int            (*ioctl)(int d, int request, ...);
    int            (*fsync)(int filedes);
    signed long long (*lseek)(int fildes, signed long long offset, int whence);
    int           *(*__error)(void);
    int            (*__fxstat64)(int ver, int fd, struct stat64 *buf);
    #define fstat64(fd, buf) __fxstat64(_STAT_VER, fd, buf)
    int            (*stat64)(const char *path, struct stat64 *buf);

    /* For the AMP async IO we need some more clib functions here */
    int            (*sigprocmask)(int how, const sigset_t *set, sigset_t *oldset);
    int            (*sigsuspend)(const sigset_t *mask);
    int            (*sigaction)(int signum, const struct sigaction *act, struct sigaction *oldact);
    int            (*sigemptyset)(sigset_t *set);
    int            (*sigfillset)(sigset_t *set);
    int            (*sigaddset)(sigset_t *set, int signum);
    int            (*sigdelset)(sigset_t *set, int signum);
    int            (*clone)(int (*fn)(void *), void *child_stack, int flags, void *arg, ...);
    int            (*kill)(int pid, int sig);
    int            (*getppid)();
    int            (*prctl)(int option, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5);
    int            (*syscall)(int number, ...);
};

struct HostDiskBase;
struct DriveGeometry;

/* This routine is specific to a particular UNIX variant */
ULONG Host_DeviceGeometry(int file, struct DriveGeometry *dg, struct HostDiskBase *hdskBase);

#define SignalChild(PID)    hdskBase->iface->kill(PID, 12)
#define SignalParent(PID)   iface->syscall(SYS_kill, PID, 28)
