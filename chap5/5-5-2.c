/*
 * a0 + a1x + a2x2 + ... + anxn
 */

double poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xpwr = x;
    for (i = 0; i < degree; i++) {
        result += a[i] * x;
        xpwr = x * xpwr;
    }
    return result;
}