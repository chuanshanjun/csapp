#include "young.h"
#define N 2

int main() {
    int status, i;
    pid_t pid;

    // 1 创建子进程并退出
    for (i = 0; i < N; i++) {
        // child 
        if ((pid = Fork()) == 0) {
            exit(100+i);
        }
    }

    // 2 父进程wait
    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("child pid = %d terminated normallu status = %d\n", pid, WEXITSTATUS(status));
        } else {
            printf("child pid = %d terminated abnormally\n", pid);
        }
    }    

    // 3 错误判断
    if (errno != ECHILD) {
        unix_error("waitpud error");
    }

    printf("end of pid = %d\n", pid);

    exit(0);
}