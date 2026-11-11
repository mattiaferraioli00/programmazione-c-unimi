#include <stdio.h>

#define R 2
#define C 4

int main(void) {
    int A[R][C];
    int V[R*C];

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            printf("Riga %d, inserisci elemento nr. %d: ", i, j);
            scanf("%d", &A[i][j]);
        }

        printf("\n");
    }

    // COPIO MATRICE A IN VETTORE V
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            V[i * C + j] = A[i][j];
        }
    }

    for (int k=0; k<(R*C); k++) {
        printf("V[%d] = %d (da A[%d][%d])\n", k, V[k], k / C, k % C);
    }

    return 0;
}
