/* WARING: This code is buggy! */

#include "young.h"

void handler1(int sig) {
    // 在信号处理程序中需要保护旧的errno
    int olderrno = errno;
    // 在信号处理程序中使用printf是不安全的所以需要使用write或
    if ((waitpid(-1, NULL, 0)) < 0) {
        sio_error("waitpid error");
    }
    Sio_puts("Handler reaped child\n");
    Sleep(1);
    errno = olderrno;
}

void handler2(int sig) {
    int olderrno = errno;

    while (waitpid(-1, NULL, 0) > 0) {
        Sio_puts("Handler reaped child.\n");
    }
    // 此处是不是可以说明errno被替换成ECHILD了
    if (errno != ECHILD) {
        sio_error("waitpid error");
    }
    Sleep(1);
    errno = olderrno;
}

int main() {
    int i, n;
    char buf[MAXBUF];

    if (signal(SIGCHLD, handler2) == SIG_ERR) {
        unix_error("signal error");
    }

    /* Parent creates children */
    for (i = 0; i < 3; i++) {
        if (Fork() == 0) {
            printf("Hello from child %d\n", (int)getpid());
            exit(0);
        }
    }

    /* Parent waits for terminal input and then processes it */
    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) {
        unix_error("read");
    }

    printf("Parent processing input\n");
    while (1)
        ;
    
    exit(0);
}