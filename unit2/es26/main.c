#include <stdio.h>

#define ZERO_N 0
#define DUE_N  2
#define NON_ACCETTABILE (-1)

int main() {
    int b;

    // Esempio di ciclo che funziona: da 2 a 0 decrescente
    printf("Ciclo for con costanti (funziona):\n");
    for (b = DUE_N; b >= ZERO_N; b--) {
        printf("b = %d\n", b);
    }

    // Esempio con valore non accettabile: ciclo non eseguito
    printf("\nCiclo con NON_ACCETTABILE (non entra nel ciclo):\n");
    for (b = NON_ACCETTABILE; b >= ZERO_N; b--) {
        printf("b = %d (non stampato)\n", b);
    }
    printf("Ciclo terminato senza iterazioni.\n");

    return 0;
}
