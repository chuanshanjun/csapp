
void movq(int a, int b, int *dest) {
    int x = a + b;
    *dest = x;
}

void movq2(long a, long b, long *dest) {
    long x = a + b;
    *dest = x;
}

void movq3(unsigned long a, unsigned b, unsigned long *dest) {
    unsigned long x = a + b;
    *dest = x;
}

void movq4(unsigned long a, unsigned b, unsigned long *dest) {
    a = 0x0011223344556677;
    unsigned long x = a + b;
    *dest = x;
}