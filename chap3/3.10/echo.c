#include <stdio.h>


void echo() {
    char buf[8]; /* way too small */
    gets(buf);
    puts(buf);
}

int main() {
    echo();

    char arr[] = "meow";
    char ch;

    char *str = arr;

    ch = *str++;

    printf("ch val = %c\n", ch);

    printf("ch next val = %c\n", *str);

    *str++ = 'x';

    printf("ch next val = %c\n", *str);
}