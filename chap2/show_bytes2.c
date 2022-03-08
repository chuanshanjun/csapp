#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    printf("sizeof(int) = %ld\n", sizeof(x));
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    printf("sizeof(float) = %ld\n", sizeof(x));
    show_bytes((byte_pointer) &x, sizeof(x));
}

void show_pointer(void *x) {
    printf("sizeof(void *) = %ld\n", sizeof(x));
    show_bytes((byte_pointer) &x, sizeof(x));
}

int main() {
    int ival = 12345;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
    