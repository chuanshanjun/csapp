#include "young.h"

void snooze(unsigned int secs);

void snooze(unsigned int secs) {
    unsigned int rc;
    rc = sleep(secs);
    printf("slept for %d of %d\n", secs - rc, secs);
}

int main() {
    snooze(3);
}

