#include <stdio.h>

typedef enum { ROSSO, GIALLO, VERDE} Semaforo;

Semaforo prossimo(const Semaforo s) {
    switch (s) {
        case ROSSO:  return VERDE;
        case VERDE:  return GIALLO;
        default:     return ROSSO;
    }
}

const char *nome(Semaforo s) {
    switch (s) {
        case ROSSO:
            printf(": Rosso\n");
            break;
        case GIALLO:
            printf(": Giallo\n");
            break;
        case VERDE:
            printf(": Verde\n");
            break;
    }

    return "?";
}

int main(void) {
    Semaforo s = ROSSO;

    for (int i = 0; i < 4; i++) {
        s = prossimo(s);
        printf("Stato attuale");
        nome(s);
    }

    return 0;
}
