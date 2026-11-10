#include <stdio.h>

enum livello {BASSO = 10, MEDIO, ALTO = 50, CRITICO};

int main(void) {

    printf("Livello basso: %d\n", BASSO);
    printf("Livello medio: %d\n", MEDIO);
    printf("Livello alto: %d\n", ALTO);
    printf("Livello critico: %d", CRITICO);

    return 0;
}
