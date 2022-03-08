// #define _GNU_SOURCE 1
#include <stdio.h>
#include <math.h>
#define POS_INFINITY 1e400
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0/POS_INFINITY)

int main()
{
    // f 3.4e38
    // d 1.8e308

    float f = 1e20;
    
    float fd = 1e20 + 1.0;

    printf("f = %f\n", f);
    printf("fd = %f\n", fd);
}



