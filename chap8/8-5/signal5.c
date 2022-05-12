#include "young.h"

void handler(int sig) {
    int olderrno = errno;
    pid_t pid;

    while ((pid = waitpid(-1, NULL, 0)) > 0) {
        sio_error("Handler reaped child\n");
    }
    if (errno != ECHILD) {
        sio_error("waipid error");
    }

    Sleep(1);
    errno = olderrno;
}

int main() {
    int i,n ;
    char buf[MAXBUF];

    for (i = 0; i < 3; i++) {
        if (Fork() == 0) {
            printf("Hello from child %d\n", (int)getpid());
            exit(0);
        }
    }

    /* Parent waits for terminal input and the pricess it */
    if ((n = read(STDIN_FILENO, buf, sizeof(buf)))) {
        unix_error("read");
    }

    printf("Parent processing input\n");
    while (1) 
        ;
    exit(0);
}