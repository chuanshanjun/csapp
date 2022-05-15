#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <setjmp.h>

/* Misc constants */
#define	MAXLINE	 8192  /* Max text line length */
#define MAXBUF   8192  /* Max I/O buffer size */
#define LISTENQ  1024  /* Second argument to listen() */

/* External variables */
extern char **environ; /* Defined by libc */

void unix_error(char *msg);

void app_error(char *msg);

pid_t Fork(void);

unsigned int Sleep(unsigned int secs);

void Pause();

char *Fgets(char *ptr, int n, FILE *stream); 

void Kill(pid_t pid, int signum);

void sio_error(char s[]);

ssize_t Sio_puts(char s[]);

ssize_t Sio_putl(long v);

pid_t Wait(int *status);

pid_t Waitpid(pid_t pid, int *ptr, int options);