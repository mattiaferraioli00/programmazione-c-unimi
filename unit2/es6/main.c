#include <stdio.h>

int main(void) {
    int x, y;

    printf("Inserisci il dividendo: ");
    scanf("%d", &x);

    printf("Inserisci il divisore: ");
    scanf("%d", &y);

    if (y == 0) {
        printf("\nErrore: divisione per zero!\n");
        return 0;
    }

    int r = x;

    ripeti:
        if (r < y) {
            goto fine_ciclo;
        }

    r = r - y;

    goto ripeti;

    fine_ciclo:
        printf("\nIl resto di %d diviso %d e': %d\n", x, y, r);

    return 0;
}
