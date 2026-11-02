#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x;
    int y;

    printf("Inserisci la variabile x: ");
    scanf("%d", &x);

    printf("Inserisci la variabile y che deve essere minore di x: ");
    scanf("%d", &y);

    int r = x % y;

    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }

    printf("Il MCD è %d", y);

    return 0;
}