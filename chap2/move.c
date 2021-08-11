#include <stdio.h>

int main()
{
    int lval = 0xFEDCBA98 << 32;
    int aval = 0xFEDCBA98 >> 36;
    unsigned uval = 0xFEDCBA98u >> 40;

    printf("%x\n", lval);
    printf("%x\n", aval);
    printf("%x\n", uval);
}