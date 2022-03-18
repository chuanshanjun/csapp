/* Compute prefix sum of vector */
void psum1(float a[], float p[], long n) {
    long i;
    p[0] = a[0];
    for (i = 1; i < n; i++) {
        p[i] = p[i-1] + a[i];
    }
}

void psum2(float a[], float p[], long n) {
    long i;
    for (i = 0; i < (n - 1); i++) {
        p[i+1] = p[i] + a[i]; 
    }
}

void psum1a(float a[], float p[], long n) {
    long i;
    /* last_val holds p[i-1]; val holds p[i] */
    
}