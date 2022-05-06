#include <stdio.h>
#include <limits.h>

int fitsBits(int x, int n) {
    // 构建32-n(32 + ((~n) + 1)) 
    int c = 33 + (~n);
    int t = (x<<c)>>c;
    return !(x^t);
    
//   int c=33+~n;
//   int t=(x<<c)>>c;
//   return !(x^t);
}

int main() {
    
    int x = 0x988;
    int y = 0x99;

    printf("x>>8=%d\n", x>>8);

    printf("(x>>8)&0x1=%d\n", (x>>8)&0x1);

}