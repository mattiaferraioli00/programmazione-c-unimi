#include <stdio.h>

enum giorno {LUN, MAR, MER, GIO, VEN, SAB, DOM};

int main(void) {
    enum giorno g;
    int n;

    printf("Inserisci un numero da 0 (lunedì) a 6 (domenica): ");

    if (scanf("%d", &n) != 1 || n < LUN || n > DOM) {
        printf("Valore non valido\n");
        return 1;
    }

    g = (enum giorno) n;

    switch (g) {
        case LUN:
            printf("Lunedì");
            break;
        case MAR:
            printf("Martedì");
            break;
        case MER:
            printf("Mercoledì");
            break;
        case GIO:
            printf("Giovedì");
            break;
        case VEN:
            printf("Venerdì");
            break;
        case SAB:
            printf("Sabato");
            break;
        case DOM:
            printf("Domenica");
            break;
        default:
            printf("Errore");
            break;
    }

    if (g == SAB || g == DOM) {
        printf(": weekend\n");
    } else {
        printf(": giorno feriale\n");
    }

    return 0;
}
