#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float a, b;

    printf("Inserire il primo numero: ");
    scanf("%f", &a);

    printf("Inserire il secondo numero: ");
    scanf("%f", &b);

    const float c = (a + b) / 2;

    printf("La media aritmetica tra %.2f e %.2f è: %.2f", a, b, c);

    return 0;
}
