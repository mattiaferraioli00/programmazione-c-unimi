#include <stdio.h>

int main(void) {
    int A, B;

    printf("Inserisci il dividendo: ");
    scanf("%d", &A);

    printf("Inserisci il divisore: ");
    scanf("%d", &B);

    if (B != 0) {
        const int R = A / B;
        printf("\nIl risultato di %d / %d è: %d\n", A, B, R);
    } else {
        printf("\nErrore: divisione per zero non consentita.\n");
    }


    return 0;
}
