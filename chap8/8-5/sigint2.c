#include "young.h"

void sigint_handler(int sig) {
    printf("Caught SIGINT\n");
    exit(0);
}

int main() {
    /* Install sigint handler */

    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        unix_error("signal error");

    pause();

    return 0;
}   