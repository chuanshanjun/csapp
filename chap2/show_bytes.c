#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);

void show_int(int x);

void show_float(float x);

void show_pointer(void *x);

void test_show_bytes(int val);

int main()
{
    test_show_bytes(12345);

    // p2.5
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1); /* A. -> 小端 21; 大端 87 */
    show_bytes(valp, 2); /* B. -> 小端 21 43; 大端 87 65 */
    show_bytes(valp, 3); /* C. -> 小端 21 43 65; 大端 87 65 43 */
    show_bytes(valp, 4); /* D. -> 小端 21 43 65 87; 大端 87 65 32 21 */
    show_bytes(valp, 5); /* E. -> 小端 21 43 65 87 xx; 大端 */

    // p2.6
    // 0x00359141
    // 0000 0000 0011 0101 1001 0001 0100 0001
    int nval = 3510593;

    // 0x4a564504
    // 0100 1010 0101 0110 0100 0101 0000 0100
    float fnval = (float)nval;

    // 移动2位,有20位相匹配,浮点数的前9位后2位不匹配
    // 00000000001101011001000101000001
    //   01001010010101100100010100000100
    show_int(nval);
    show_float(fnval);

    char str[] = "12345";
    show_bytes(str, sizeof(str));

    // p2.7 输出 61 62 63 64 65 66
    const char *s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));
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