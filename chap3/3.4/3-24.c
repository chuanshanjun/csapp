long loop_while(long a, long b) {
    // a %rdi, b %rsi
    long result = 1; // %rax
    while (a < b) {
        result *= (a + b);
        a = a + 1;
    }
    return result;
}