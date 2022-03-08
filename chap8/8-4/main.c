#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);

pid_t fork(void);


#include <stdlib.h>

void exit(int status);

