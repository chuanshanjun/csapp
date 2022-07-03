#include "young.h"

void sigint_handler(int sig) { /* SIGINT handler */
    printf("Caught SIGINT!\n");
    // exit(0);
    return;
}

int main() {
    /* Install the SIGINT handler */
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        unix_error("signal error");
    }

    pause(); /* Wait for the receipt of a signal */

    printf("after sigint_handler");

    return 0;
}