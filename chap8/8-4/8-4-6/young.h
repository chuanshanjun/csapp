#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 

void unix_error(char *msg);

void app_error(char *msg);

pid_t Fork(void);

unsigned int Sleep(unsigned int secs);

void Pause();

char *Fgets(char *ptr, int n, FILE *stream); 

/* Misc constants */
#define	MAXLINE	 8192  /* Max text line length */

/* External variables */
extern char **environ; /* Defined by libc */

