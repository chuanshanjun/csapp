#include "young.h"

int main() {
    pid_t pid;

    /* Child process wait for kill */
    if ((pid = Fork()) == 0) {
        pause();
        printf("receive interupt form control + c\n");
        exit(0);
    }

    /* kill child pid */
    Kill(pid, SIGKILL);
    exit(0);
}