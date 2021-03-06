/* Prototypes for functions defined in
raw_usrreq.c
 */

void raw_init(void);
#ifndef AROS
int __stdargs raw_input(struct mbuf * m0,
#else
int raw_input(struct mbuf * m0,
#endif
			struct sockproto * proto,
			struct sockaddr * src,
			struct sockaddr * dst);

void raw_ctlinput(int cmd,
		  struct sockaddr * arg,
		  caddr_t arg2);

int raw_usrreq(struct socket * so,
               int req,
               struct mbuf * m,
               struct mbuf * nam,
               struct mbuf * control);

int rawintr(void);

