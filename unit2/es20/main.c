#include <stdio.h>
#include <stdlib.h>

int main(void) {
    #define SOMMA 3 + 2;

    int a = 5 * SOMMA;

    printf("Somma: %d\n", a);

    #define SOMMA (3+2);

    a = 5 * SOMMA;

    printf("Somma: %d\n", a);

    return 0;
}
