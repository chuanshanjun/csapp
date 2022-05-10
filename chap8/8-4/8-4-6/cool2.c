#include <stdio.h>

int main() {

    int c = 0;
    FILE *fp = fopen("./test.txt", "r");
    while (!feof(fp)) {
        int c = fgetc(fp);
        printf("%c: %x \n", c, c);
    }

    // int c;
    // FILE *fp = fopen("./test.txt", "r");
    // c = fgetc(fp);
    // while(!feof(fp)) {
    //     printf("%c : %x \n", c, c);
    //     c = fgetc(fp);
    // }
}