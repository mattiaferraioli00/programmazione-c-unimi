#include <stdio.h>

int main(void) {
    int x, y;

    printf("Inserire il valore di x: \n");
    scanf("%d", &x);

    printf("Inserire il valore di y (minore di x): \n");
    scanf("%d", &y);

    modulo:
        int r = x % y;

        if (r == 0) {
            goto fine_ciclo;
        }

        x=y;
        y=r;

        goto modulo;

    fine_ciclo:
        printf("Il MCD è: %d", y);
        return 0;
}
