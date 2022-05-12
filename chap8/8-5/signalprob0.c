#include "young.h"

volatile long counter = 2;

void handler1(int sig) {
    sigset_t mask, prev_mask;

    sigfillset(&mask);
    sigprocmask(SIG_BLOCK, &mask, &prev_mask); /* Block sigs */
    Sio_putl(--counter);
    sigprocmask(SIG_SETMASK, &prev_mask, NULL); /* Restroe sigs */

    _exit(0);
}

int main() {
    pid_t pid;
    sigset_t mask, prev_mask;

    printf("%ld", counter);
    fflush(stdout);

    signal(SIGUSR1, handler1);
    if ((pid = Fork()) == 0) {
        while (1) {}
    }
    kill(pid, SIGUSR1);
    Waitpid(-1, NULL, 0);

    sigfillset(&mask);
    sigprocmask(SIG_BLOCK, &mask, &prev_mask);
    printf("%ld", ++counter);
    sigprocmask(SIG_SETMASK, &prev_mask, NULL);

    exit(0);
}