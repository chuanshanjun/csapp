long fun_a(unsigned long x) {
    long val = 0;
    while (x) {
        val = x ^ val; 
        x >>= 1;
    }
    return val & 0x1;
}