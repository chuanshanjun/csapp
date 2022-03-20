#include "stdio.h"

void swap(long *xp, long *yp);

int main(int argc, char **argv) {

    long z = 10;

    long *xp = &z;
    long *yp = &z;

    swap(xp, yp);

    printf("xp = %lu, up = %lu\n", *xp, *yp);
}

void swap(long *xp, long *yp) {
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}

