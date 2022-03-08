#include <stdio.h>

long exchange(long *xp, long y) {
    long x = *xp;
    *xp = y;
    return x;
}

// movq (%rdi), %rax
// movq %rsi, (%rdi)

int main() {

    long x = 10;
    long *y = &x;
    printf("long *y = %ld\n", *y);

    long z = 12;

    *y = z;
    printf("long *y addr = %ld\n", *y);
    printf("long *y addr = %p\n", y);

    long zz = 13;
    y = &zz;
    printf("long *y addr = %ld\n", *y);
    printf("long *y addr = %p\n", y);

    printf("size_of(y) = %ld\n", sizeof(y));
}