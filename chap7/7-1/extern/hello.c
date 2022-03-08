#include <stdio.h>

char str[] = {"hello, world\n"};
const char *ptr;

void helloworld(void) {
    static int staticval;
    ptr = str;
    const char *local = ptr;
    printf("%s", ptr);
    printf("%s", local);
}