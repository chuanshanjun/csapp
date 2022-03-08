#include <stdio.h>
#define N 16
typedef int fix_matrix[N][N];

int main() {
    char A[12];
    char *B[8];
    int C[6];
    double *D[5];
    short **U[6];

    int a = 100;
    int *p1 = &a;
    int **p2 = &p1;
}

int fix_prod_ele(fix_matrix A, fix_matrix B, long i, long k) {
    long j;
    int result = 0;

    for (j = 0; j < N; j++) {
        result += A[i][j] * B[j][k]; 
    }

    return result;
}