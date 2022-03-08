#include "young.h"
#define N 2

int main() {
    pid_t pid;
    int status, i;

    for (i = 0; i < N; i++) {
        if ((pid = Fork()) == 0) {
            exit(100+i);
        }
        printf("child pid = %d\n", pid);
    }    

    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("pid = %d termined with status %d\n", pid, WEXITSTATUS(status));
        } else {
            printf("pid = %d termined with unexpected status", pid);
        }
    }

    if (errno != ECHILD) {
        unix_error("waitpid error");
    }

    exit(0);
}