#include <stdio.h>
#include <stdlib.h>

#define RIGHE 3
#define COLONNE 4

int main(void) {

    int M[RIGHE][COLONNE];
    int somma_righe[RIGHE] = {0};
    int somma_colonne[COLONNE] = {0};

    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            printf("Inserisci la cifra nr. %d della riga %d: ", j+1, i+1);
            scanf("%d", &M[i][j]);

            somma_righe[i] += M[i][j];
            somma_colonne[j] += M[i][j];
        }

        printf("\n");
    }

    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }

    printf("\nSomma per righe\n");
    for (int i = 0; i < RIGHE; i++) {
        printf("Riga %d: %d\n", i + 1, somma_righe[i]);
    }

    printf("\nSomma per colonnen");
    for (int j = 0; j < COLONNE; j++) {
        printf("Colonna %d: %d\n", j + 1, somma_colonne[j]);
    }

    return 0;
}
