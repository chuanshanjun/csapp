#include <stdio.h>

unsigned long double2bits(double d) {
    union {
        double d;
        unsigned long u;
    } temp;
    temp.d = d;
    return temp.u;
};

double uu2double(unsigned word0, unsigned word1) {
    union {
        double d;
        unsigned u[2];
    } temp;

    temp.u[0] = word0;
    temp.u[1] = word1;
    return temp.d;
}

int main() {
    double d = 33.9;
    
    // 普通转换
    unsigned long ul1 = (unsigned long) d;
    
    printf("common cast ul1 = %ld\n", ul1);

    // 使用union 转换

    unsigned long ul2 = double2bits(d);
    printf("union cast ul2 = %ld\n", ul2);

    double end = uu2double(33, 22);
    printf("double end = %f\n", end);
}