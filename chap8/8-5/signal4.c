#include "young.h"

void handler(int sig) {
    // 保留旧的errno
    int olderrno = errno;

    pid_t pid;

    while ((pid = waitpid(-1, NULL, 0)) > 0) {
        char msg[30];
        sprintf(msg, "Handler reaped child pid = %d\n", pid);
        Sio_puts(msg);
    }

    if (errno != ECHILD) {
        sio_error("waitpid error");
    }
    Sleep(1);
    errno = olderrno;
}

int main() {
    int i, n;
    char buf[MAXBUF];

    if (signal(SIGCHLD, handler) == SIG_ERR) {
        unix_error("signal error");
    }

    /* Parent creates children */
    for (i = 0; i < 3; i++) {
        if (Fork() == 0) {
            printf("Hello from child pid = %d\n", getpid());
            exit(0);
        }
    }

    /* Parent waits for terminal input and then process it */
    if ((n = read(STDIN_FILENO, buf, sizeof(buf)) < 0)) {
        unix_error("read error");
    }

    printf("Parent processing input.\n");
    while (1) 
        ;
        
    exit(0);
}