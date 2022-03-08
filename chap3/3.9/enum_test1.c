#include <stdio.h>

/* 不使用枚举，使用define定义 */
#define MON 1
#define TUE 2

enum DAY {
    MON=1, TUE, WED
};

int main() {
    printf("macro MON=%d\n", MON);
    printf("enum WED=%d\n", WED);
}