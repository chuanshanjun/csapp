#include "young.h"

volatile sig_atomic_t pid;

void sigchld_handler(int sig) {
    int olderrno = errno;
    pid = waitpid(-1, NULL, 0);
    errno = olderrno;
}

void sigint_handler(int s) {

}

int main(int argc, char **argv) {
    sigset_t mask, prev;

    signal(SIGCHLD, sigchld_handler);
    signal(SIGINT, sigint_handler);
    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);

    while (1) {
        sigprocmask(SIG_BLOCK, &mask, &prev); /* Block SIGCHLD */
        if (fork() == 0) { /* child */
            exit(0);
        }

        /* Wait for SIGCHLD to be received */
        pid = 0;
        while (!pid) {
            sigsuspend(&prev);
        }

        /* Optionally block SIGCHLD */
        sigprocmask(SIG_SETMASK, &prev, NULL);

        /* Do some work after receiving SIGCHLD */
        printf(".");
    }
    exit(0);
}