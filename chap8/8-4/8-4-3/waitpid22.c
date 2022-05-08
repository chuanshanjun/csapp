#include "young.h"
#define N 4

int main() {
    int status, i;
    pid_t pid[N], retpid;

    for (i = 0; i < N; i++) {
        // child
        if ((pid[i] = Fork()) == 0) {
            exit(i + 100);
        }
    }

    i = 0;
    while ((retpid = waitpid(pid[i], &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("pid %d terminated normally %d\n", pid[i], WEXITSTATUS(status));
        } else {
            printf("pid %d terminated abnormally\n", pid[i]);
        }

        i++;
    }
    
    // The only normal termination is if there are no more childre
    if (errno != ECHILD) {
        unix_error("waitpid error");
    }

    exit(0);
}