#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 8192


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


void rio_readinitb(rio_t *rp, int fd); 
void Rio_readinitb(rio_t *rp, int fd);
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen); 
ssize_t Rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);
void Rio_writen(int fd, void *usrbuf, size_t n);
void Fputs(const char *ptr, FILE *stream);
char *Fgets(char *ptr, int n, FILE *stream);
int Open_clientfd(char *hostname, char *port);
void Fuck(); 
void Close(int fd); 