void merge(long src1[], long src2[], long dest[], long n) {
    long i1 = 0;
    long i2 = 0;
    long id = 0;
    while (i1 < n && i2 < n) {
        dest[id++] = src1[i1++];
        long t = src1[i1] > src2[i2];
        if (t) {
            dest[id++] = src2[i2++];
        }
    }
}

void merge2(long src1[], long src2[], long dest[], long n) {
    long i1 = 0;
    long i2 = 0;
    long id = 0;
    while (i1 < n && i2 < n) {
        long v1 = src1[i1];
        long v2 = src2[i2];
        long take1 = v1 < v2;
        dest[id++] = take1 ? v1 : v2;
        i1 += take1;
        i2 += (1-take1);
    }
}

void merge(long src1[], long src[], long dest[], long n) {
    long i1 = 0;
    long i2 = 0;
    long id = 0;
    while (i1 < n && i2 < n) {
        long result = src1[i1] < src[i2];
        
    }
}