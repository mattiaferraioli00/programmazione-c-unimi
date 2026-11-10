#include <stdio.h>

int main(void) {
    int a;

    printf("=== Lettura con valore sentinella ===\n");
    printf("Inserisci una sequenza di numeri interi, termina con 0.\n\n");

    scanf("%d", &a);

    ripeti:
        if (a == 0) {
            goto fine_ciclo;;
        }


    printf("Hai inserito: %d\n", a);
    scanf("%d", &a);

    goto ripeti;

    goto ripeti;

    fine_ciclo:
        printf("Termine del ciclo, è stato inserito il numero 0");
        return 0;
}
