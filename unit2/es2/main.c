#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a;
    int b;
    int i;
    int p;

    printf("=== Prodotto come somma ripetuta ===\n");
    printf("Questo programma calcola A * B usando solo somme ripetute.\n\n");

    printf("Inserisci la variabile a: ");
    scanf("%d", &a);

    printf("Inserisci la variabile b: ");
    scanf("%d", &b);

    i = 0;
    p = 0;

    ripeti:

    p = p + a;
    i = i + 1;

    if (i >= b) {
        goto fine_ciclo;;
    }

    goto ripeti;

    fine_ciclo:

    printf("Il risultato di %d * %d è: %d", a, b, p);

    return 0;
}