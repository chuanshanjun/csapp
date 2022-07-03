#include "young.h"

void handler1(int sig) {
    // 信号处理函数中先保存errno
    int olderrno = errno;

    if ((waitpid(-1, NULL, 0)) < 0) {
        // 使用异步信号安全函数
        sio_error("waitpid error");        
    }   
    Sio_puts("Hanlder reaped child = %d\n");
    Sleep(1);
    // 在handler函数结束前 回复errno
    errno = olderrno;
}

int main() {
    int i, n;
    char buf[MAXBUF];

    // install signal handler func
    if (signal(SIGCHLD, handler1) == SIG_ERR) {
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
    if ((n = read(STDIN_FILENO, buf, sizeof(buf)) < 0)) {
        unix_error("read");
    }

    printf("Parent processing input\n");
    while (1)
        ;

    exit(0);
    
}