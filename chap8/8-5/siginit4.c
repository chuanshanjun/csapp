#include "young.h"

void sigint_handler(int sig) { /* SIGINT handler */
    printf("Caught SIGINT!\n");
    exit(0);
}

int main() {
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        unix_error("signal error");
    
    pause(); /* Wait for the receipt of a signal */

    return 0;
}