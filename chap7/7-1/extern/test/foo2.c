#include <stdio.h>

void foo(void);

int x = 1;

int main(void) {
    foo();
    printf("x = %d\n", x);
    return 0;
}