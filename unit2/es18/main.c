#include <stdio.h>

int main(void) {
    long i;
    short j = 5;

    printf("Valore iniziale di j: %hd\n\n", j);

    i = j * j;
    printf("1) i = j * j;\n");
    printf("   risultato assegnato a i = %ld\n\n", i);

    i = (long) j * j;
    printf("2) i = (long) j * j;\n");
    printf("   risultato assegnato a i = %ld\n\n", i);

    i = (long) (j * j);
    printf("3) i = (long) (j * j);\n");
    printf("   risultato assegnato a i = %ld\n", i);

    return 0;
}