#include "young.h"

void handler(int sig) {
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
    int n;
    char buf[MAXBUF];

    if (signal(SIGCHLD, handler) == SIG_ERR) {
        unix_error("signal error");
    }

    for (int i = 0; i < 3; i++) {
        if (Fork() == 0) {
            printf("Hello from child %d\n", (int)getpid());
            exit(0);
        }
    }

    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) {
        unix_error("read");
    }

    printf("Parent processing input\n");
    while (1) 
        ;

    exit(0);
}