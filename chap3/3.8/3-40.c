#include <stdio.h>
#define N 16
typedef int fix_matrix[N][N];

void fix_set_diag(fix_matrix A, int val) {
    int *Aptr = &A[0][0];
    int *Aend = &A[N][N];

    do {
        *Aptr = val;
        Aptr = Aptr + N + 1;
    } while (Aptr != Aend); 
}

void fix_set_diag_opt(fix_matrix A, int val) {
    int *Abase = &A[0][0];
    long i = 0;
    long iend = N*(N+1);
    do {
        Abase[i] = val;
        i += (N+1);
    } while (i != iend);
}

int main() {
    fix_matrix array = {0};
    fix_set_diag(array, 3);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // if (i == j) {
                printf("a[%d][%d]=%d ", i, j, array[i][j]);
            // }
        }
        printf("\n");
    }

    fix_set_diag_opt(array, 4);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // if (i == j) {
                printf("a[%d][%d]=%d ", i, j, array[i][j]);
            // }
        }
        printf("\n");
    }
}
