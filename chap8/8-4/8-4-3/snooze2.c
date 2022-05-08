#include "young.h"

unsigned int snooze2(unsigned int secs);

unsigned int snooze2(unsigned int secs) {
    unsigned int rc = sleep(secs);

    printf("Slept for %d of %d secs. \n", secs-rc, secs);
    return rc;
}

