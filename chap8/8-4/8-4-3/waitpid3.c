#include "young.h"
#define N 2

int main() {
    int status, i;
    pid_t pid[N], retpid;

    for (i = 0; i < N; i++) {
        if ((pid[i] = Fork()) == 0) {
            exit(100+i);
        }
        
        printf("child pid = %d\n", pid[i]);
    }

    i = 0;
    while ((retpid = waitpid(pid[i], &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("child pid = %d exit with status = %d\n", retpid, WEXITSTATUS(status));
        } else {
            printf("chind pid = %d exit abnormal\n", retpid);
        }
        
        i++;
    }

    if (errno != ECHILD) {
        unix_error("waitpid error");
    }

    exit(0);
}
