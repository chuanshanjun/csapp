#include "young.h"

int main() {
    pid_t pid;
    int status;

    printf("Hello\n");
    pid = Fork();
    printf("%d\n", !pid);
    if (pid != 0) {
        if (pid = waitpid(-1, &status, 0)) {
            if (WIFEXITED(status)) {
                printf("%d\n", WEXITSTATUS(status));
            }
        }
    }

    printf("Bye\n");
    exit(2);
}