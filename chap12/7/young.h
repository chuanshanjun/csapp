#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <pthread.h>
#include <semaphore.h>

/* Persistent state for the robust I/O (Rio) package */
/* $begin rio_t */
#define RIO_BUFSIZE 8192
typedef struct {
    int rio_fd;                /* Descriptor for this internal buf */
    int rio_cnt;               /* Unread bytes in internal buf */
    char *rio_bufptr;          /* Next unread byte in internal buf */
    char rio_buf[RIO_BUFSIZE]; /* Internal buffer */
} rio_t;
/* $end rio_t */

/* External variables */
extern int h_errno;    /* Defined by BIND for DNS errors */ 
extern char **environ; /* Defined by libc */

/* Misc constants */
#define	MAXLINE	 8192  /* Max text line length */
#define MAXBUF   8192  /* Max I/O buffer size */
#define LISTENQ  1024  /* Second argument to listen() */


/* Simplifies calls to bind(), connect(), and accept() */
/* $begin sockaddrdef */
typedef struct sockaddr SA;
/* $end sockaddrdef */

typedef void handler_t(int);

int Open_listenfd(char *port); 
int Accept(int s, struct sockaddr *addr, socklen_t *addrlen);
void Getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host, 
                 size_t hostlen, char *serv, size_t servlen, int flags);
void Close(int fd);      
void Rio_readinitb(rio_t *rp, int fd);
ssize_t Rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
void Rio_writen(int fd, void *usrbuf, size_t n);   
int Open(const char *pathname, int flags, mode_t mode);
void *Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
void Munmap(void *start, size_t length);
pid_t Fork(void);
void Execve(const char *filename, char *const argv[], char *const envp[]);
int Dup2(int fd1, int fd2);
pid_t Wait(int *status); 
int Open_clientfd(char *hostname, char *port);
char *Fgets(char *ptr, int n, FILE *stream);
void Fputs(const char *ptr, FILE *stream);
handler_t *Signal(int signum, handler_t *handler);
int Select(int  n, fd_set *readfds, fd_set *writefds,
	   fd_set *exceptfds, struct timeval *timeout); 
void Pthread_cancel(pthread_t tid);
void Pthread_join(pthread_t tid, void **thread_return);
void Pthread_create(pthread_t *tidp, pthread_attr_t *attrp, 
		    void * (*routine)(void *), void *argp);
void Pthread_detach(pthread_t tid);
void *Malloc(size_t size); 
void Free(void *ptr);
void Pthread_exit(void *retval);
void Pthread_once(pthread_once_t *once_control, void (*init_function)());
void Sem_init(sem_t *sem, int pshared, unsigned int value);
void P(sem_t *sem);
void V(sem_t *sem);
void *Calloc(size_t nmemb, size_t size);
void Free(void *ptr); 
void Pthread_create(pthread_t *tidp, pthread_attr_t *attrp, void * (*routine)(void *), void *argp);
void Pthread_join(pthread_t tid, void **thread_return); 