#include <stdio.h>
#include <limits.h>

int main()
{
    printf("int min = %d \n", INT_MIN);
    printf("int max = %d \n", INT_MAX);
    printf("uint max = %u \n", UINT_MAX);

    short int v = -12345;
    unsigned short uv = (unsigned short) v;
    printf("v = %d, uv = %u\n", v ,uv);

    unsigned u = 4294967295u;
    int tu = (int) u;
    printf("u = %u, tu = %d\n", u, tu);

    int tx, ty;
    unsigned ux, uy;
    printf("sizeof(tx) = %lu\n", sizeof(tx));
    printf("sizeof(ux) = %lu\n", sizeof(ux));
    
    // 显示类型转换
    // tx = (int) ux;
    // uy = (unsigned) ty;

    // 隐示类型转换
    tx = ux; /* cast to signed */
    uy = ty; /* cast to unsigned */

    int x = -1;
    unsigned u2 = 2147483648u;

    printf("x = %u = %d \n", x, x);
    printf("u = %u = %d \n", u2, u2);

    // p2.21
    // 1 -2147483647-1 -> -2147483648
    // 2 -2147483648 -> 2147483648u
    // true
    if (-2147483647-1 == 2147483648u) {
        printf("-2147483647-1 == 2147483648u true\n");
    } else {
        printf("-2147483647-1 == 2147483648u false\n");
    }   

    // 1 -2147483647-1 -> -2147483648
    // 2 -2147483648 < 2147483647
    // 3 true
    if (-2147483647-1 < 2147483647) {
        printf("-2147483647-1 < 2147483647 true\n");
    } else {
        printf("-2147483647-1 < 2147483647 false\n");
    }

    // 1 -2147483647 -> 2147483649
    // 2 2147483649 - 1 -> 2147483648u
    // false
    if (-2147483647-1u < 2147483647) {
        printf("-2147483647-1u < 2147483647 true\n");
    } else {
        printf("-2147483647-1u < 2147483647 false\n");
    }

    // 1 -2147483647-1 -> -2147483648
    // true
    if (-2147483647-1 < -2147483647) {
        printf("-2147483647-1 < -2147483647 true\n");
    } else {
        printf("-2147483647-1 < -2147483647 false\n");
    }

    // -2147483647 -> 2147483649u
    // 2147483649 - 1u -> 2147483648u
    // -2147483647 -> 2147483649u
    // 2147483648u < 2147483649u
    if (-2147483647-1u < -2147483647) {
        printf("-2147483647-1u < -2147483647 true\n");
    } else {
        printf("-2147483647-1u < -2147483647 false\n");
    }
}