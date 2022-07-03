#include "young.h"

void handler(int sig) {
    int olderrno = errno;
    // 错误用法

    while (waitpid(-1, NULL, 0) > 0) {
        Sio_puts("reaped child\n");
    }

    if (errno != ECHILD) {
        sio_error("waitpid error");
    }

    errno = olderrno;

    Sleep(1);
}

int main() {
    int i, n;
    char buf[MAXBUF];

    // install signal func
    if (signal(SIGCHLD, handler) == SIG_ERR) {
        unix_error("signal error");
    }

    /* Parent creates children */
    for (i = 0; i < 3; i++) {
        if (Fork() == 0) { // child
            printf("hello from child %d\n", (int)getpid());
            exit(0);
        }
    }

    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) {
        unix_error("read");
    }

    printf("parent processing input\n");

    while(1)
        ;

    exit(0);
}