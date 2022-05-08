#include "young.h"
#define N 3

int main() {
    int status, i;
    pid_t pid[N], retpid;

    for (i = 0; i < N; i++) {
        if ((pid[i] = Fork()) == 0) {
            exit(i+100);
        }
    }

    i = 0;
    while ((retpid = waitpid(pid[i++], &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("pid %d terminated bormally %d\n", retpid, WEXITSTATUS(status));
        } else {
            printf("pid %d terminated abnormally\n", retpid);
        }
    }

    if (errno != ECHILD) {
        unix_error("waitpid error");
    }

    exit(0);
}