long loop_while2(long a, long b) {
    long result = b;
    while (b > 0) {
        result = a * result;
        b = b - a;
    }
    return result;
}