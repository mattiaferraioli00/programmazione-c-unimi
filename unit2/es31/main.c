#include <stdio.h>

#define RIGHE 2
#define COLONNE 3

int main(void) {

    int A[RIGHE][COLONNE];

    for (int i = 0; i < RIGHE; i++) {
        for (int j=0; j < COLONNE; j++) {
            printf("Inserisci la cifra nr. %d della riga %d: ", j+1, i+1);
            scanf("%d", &A[i][j]);

            printf("\n");
        }
    }

    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
