#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int A, B;

    printf("=== Potenza come prodotto ripetuto ===\n");
    printf("Questo programma calcola A^B usando solo prodotti ripetuti.\n\n");

    printf("Inserisci la variabile a, intero e positivo: ");
    scanf("%d", &A);

    printf("Inserisci la variabile b, intero e positivo: ");
    scanf("%d", &B);

    int T = 0;
    int S = 0;
    int i = 1;

    ripeti:
        if (i > B) {
            goto fine_ciclo;
        }

        T = T + A;
        S = S + T;

        i = i + 1;

    goto ripeti;

    fine_ciclo:
        printf("La somma dei primi %d multipli di %d è: %d", B, A, S);

    return 0;
}