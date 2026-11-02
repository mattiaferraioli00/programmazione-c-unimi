#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, b;

    printf("=== Scambio del valore di due variabili ===\n");
    printf("Il programma legge due interi e ne scambia i valori.\n\n");

    printf("Inserire un numero: ");
    scanf("%d", &a);

    printf("Inserire un numero: ");
    scanf("%d", &b);


    printf("Valore di a: %d, Valore di b: %d\n", a, b);

    printf("Inverto i valori.. \n");

    int temp = a;

    a=b;
    b=temp;

    printf("Valore di a: %d, Valore di b: %d\n", a, b);

    return 0;
}
