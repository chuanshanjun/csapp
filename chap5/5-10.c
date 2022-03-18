void copy_array(long *src, long *dest, long n) {
    long i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}