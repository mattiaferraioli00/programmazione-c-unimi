#include <stdio.h>

#define N 3
int main(void) {

    int A[N][N];
    int B[N][N];

    int x;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Inserisci la cifra nr. %d della riga %d: ", j+1, i+1);
            scanf("%d", &A[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = A[i][j];
        }
    }

    printf("\nMatrice A\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }


    printf("\nMatrice B\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Riga %d, Colonna %d: %d\n", i+1, j+1, B[i][j]);

        }
        printf("\n");
    }

    return 0;
}
