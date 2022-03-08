#include <stdio.h>

void my_fun() {
    int x = 0;
    static int y = 0;

    printf("x :%d, y: %d\n", x, y);

    x++;
    y++;
}

int main() {
    my_fun();
    my_fun();
    my_fun();
}