#include "young.h"
#define N 2

int main() {
    int status, i;
    pid_t pid;

    // 1 创建进程
    for (i = 0; i < N; i++) {
        // child process
        if ((pid = Fork()) == 0) {
            exit(100 + i);
        }
    }

    // 2 wait 进程退出
    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("child %d terminated normally status %d\n", pid, WEXITSTATUS(status));
        } else {
            printf("child %d terminated abnormally\n", pid);
        }
    }
    
    // 3 错误检查
    if (errno != ECHILD) {
        unix_error("waitpid error");
    }

    exit(0);
}