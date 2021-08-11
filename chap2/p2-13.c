#include <stdio.h>

int bis(int x, int m);
int bic(int x, int m);

// 实现 x|y
int bool_or(int x, int y)
{
    int result = bis(x, y);
    return result;
}

// 实现 x^y
int bool_xor(int x, int y)
{
    int result = bis(bic(x, y), bic(y, x));
    return result;
}

int main()
{
}