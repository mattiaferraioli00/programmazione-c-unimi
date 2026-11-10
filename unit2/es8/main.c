#include <limits.h>
#include <stdio.h>

int main(void) {
    /* Test 1: postfisso, restituisce il valore PRIMA dell'incremento */
    int a = 5;
    int r = a++;
    printf("Test 1: a = 5; r = a++  -> r = %d, a = %d\n", r, a);

    /* Test 2: prefisso, restituisce il valore DOPO l'incremento */
    a = 5;
    r = ++a;
    printf("Test 2: a = 5; r = ++a  -> r = %d, a = %d\n", r, a);

    /* Test 3: il confronto usa il valore vecchio (0), poi a diventa 1 */
    a = 0;
    r = (a++ > 0);
    printf("Test 3: a = 0; a++ > 0  -> %d (falso), a = %d\n", r, a);

    /* Test 4: INT_MAX + 1 e' overflow su intero con segno:
       comportamento non definito, quindi non lo eseguiamo */
    a = INT_MAX;
    printf("Test 4: a = INT_MAX = %d\n", a);
    printf("        a++ produrrebbe overflow: comportamento non definito in C\n");

    return 0;
}
