#include <stdio.h>
#include <limits.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);

void show_int(int x);

void show_float(float x);

void show_pointer(void *x);

void test_show_bytes(int val);

int main()
{
    printf("int min = %d \n", INT_MIN);
    printf("int max = %d \n", INT_MAX);
    printf("uint max = %u \n", UINT_MAX);

    short int v = -12345;
    unsigned short uv = (unsigned short)v;
    printf("v = %d, uv = %u\n", v, uv);

    unsigned u = 4294967295u;
    int tu = (int)u;
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
    if (-2147483647 - 1 == 2147483648u)
    {
        printf("-2147483647-1 == 2147483648u true\n");
    }
    else
    {
        printf("-2147483647-1 == 2147483648u false\n");
    }

    // 1 -2147483647-1 -> -2147483648
    // 2 -2147483648 < 2147483647
    // 3 true
    if (-2147483647 - 1 < 2147483647)
    {
        printf("-2147483647-1 < 2147483647 true\n");
    }
    else
    {
        printf("-2147483647-1 < 2147483647 false\n");
    }

    // 1 -2147483647 -> 2147483649
    // 2 2147483649 - 1 -> 2147483648u
    // false
    if (-2147483647 - 1u < 2147483647)
    {
        printf("-2147483647-1u < 2147483647 true\n");
    }
    else
    {
        printf("-2147483647-1u < 2147483647 false\n");
    }

    // 1 -2147483647-1 -> -2147483648
    // true
    if (-2147483647 - 1 < -2147483647)
    {
        printf("-2147483647-1 < -2147483647 true\n");
    }
    else
    {
        printf("-2147483647-1 < -2147483647 false\n");
    }

    // -2147483647 -> 2147483649u
    // 2147483649 - 1u -> 2147483648u
    // -2147483647 -> 2147483649u
    // 2147483648u < 2147483649u
    if (-2147483647 - 1u < -2147483647)
    {
        printf("-2147483647-1u < -2147483647 true\n");
    }
    else
    {
        printf("-2147483647-1u < -2147483647 false\n");
    }

    short sx = -12345;
    unsigned uy2 = sx;

    printf("uy = %u\n", uy2);
    show_bytes((byte_pointer)&uy2, sizeof(uy2));

    unsigned x3 = 3;
    unsigned x4 = 4;
    printf("u = %u\n", x3 - x4);
}

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}