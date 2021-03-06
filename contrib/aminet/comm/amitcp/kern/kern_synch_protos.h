/* Prototypes for functions defined in
kern_synch.c
 */

#ifdef SPL0
#undef SPL0
#endif
#ifdef SPLSOFTCLOCK
#undef SPLSOFTCLOCK
#endif
#ifdef SPLNET
#undef SPLNET
#endif
#ifdef SPLIMP
#undef SPLIMP
#endif
#define SPL0         0
#define SPLSOFTCLOCK 1
#define SPLNET       2
#define SPLIMP       3


BOOL sleep_init(void);

void tsleep_send_timeout(struct SocketBase * , struct timeval const * );

void tsleep_abort_timeout(struct SocketBase * , struct timeval const * );

void tsleep_enter(struct SocketBase * , caddr_t , char * );

int tsleep_main(struct SocketBase * );

int tsleep(struct SocketBase * , caddr_t , char * , struct timeval const * );

void wakeup(caddr_t );

BOOL spl_init(void);

int spl_n(int );

