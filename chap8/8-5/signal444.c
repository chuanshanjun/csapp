#include "young.h"

void handler(int sig) {
    sigset_t sigset;
    
    int olderrno = errno;


    if (sigprocmask(0, NULL, &sigset) < 0) {
        sio_error("sigprocmask error");
    } else {
        Sio_puts("hello");
        if (sigismember(&sigset, SIGINT))
            Sio_puts("SIGINT");
        if (sigismember(&sigset, SIGCHLD))
            Sio_puts("SIGCHLD"); 
    }

    while (waitpid(-1, NULL, 0) > 0) {
        Sio_puts("Handler reaped child\n");
    }

    if (errno != ECHILD) {
        sio_error("waipid error");
    }

    Sleep(1);
    errno = olderrno;
}

int main() {
    int i, n;
    char buf[MAXBUF];
    
    signal(SIGCHLD, handler);

    for (i = 0; i < 3; i++) {
        if (Fork() == 0) { // child
            printf("hello from child %d\n", (int)getpid());
            exit(0);
        }
    }

    if (read(STDIN_FILENO, buf, sizeof(buf)) < 0) {
        unix_error("read");
    }

    printf("processing input");

    while (1)
        ;
    
    exit(0);
}