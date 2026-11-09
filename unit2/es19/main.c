#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int b1 = (1 ? 1 : 1);
    int b2 = (1 ? 0 : 0);

    int x = (b1 || b2) < b1 + 7;

    printf("(b1 || b2) < b1 + 7 = %d\n", x);

    int y = (b1 && b2) * b1;

    printf("(b1 && b2) * b1 = %d\n", y);

    int a = 4;

    int risultato = (a < 6) ? 1 : (a & 6);

    printf("(a < 6) ? 1 : (a & 6) = %d\n", risultato);


    return 0;
}
