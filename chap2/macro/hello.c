#include <stdio.h>
#define newPI 3.14158
#define FORMAT "%f\n"

const double PI = 3.14159;

int main()
{
    printf("hello world!\n");
    printf("%f\n", 2*PI);
    printf(FORMAT, 2*newPI);
}


