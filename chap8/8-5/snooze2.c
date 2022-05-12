#include "young.h"

unsigned int secs;

void snooze(unsigned int sleepSecs) {
    unsigned int remain = sleep(sleepSecs);

    printf("Slept for %u of %u secs\n", sleepSecs - remain, sleepSecs);
}

void sigint_handler(int sig) {
    return;
}

int main(int argc, char *argv[]) {
    unsigned int sleepSecs = atoi(argv[1]);

    printf("sleepSecs = %u\n", sleepSecs);

    if (sleepSecs == 0) {
        unix_error("could not give 0");
    }

    secs = sleepSecs;

    if ((signal(SIGINT, sigint_handler)) == SIG_ERR)
        unix_error("signal error");

    snooze(secs);

    // sleep(sleepSecs);

    return 0;
}