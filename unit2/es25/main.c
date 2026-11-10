#include <stdio.h>

typedef enum { CUORI, QUADRI, FIORI, PICCHE } Seme;
typedef enum { CONFRONTO_MINORE = -1, CONFRONTO_UGUALE, CONFRONTO_MAGGIORE} Confronto;
typedef struct { int valore; Seme seme; } Carta;

static Carta leggi(void) {
    Carta c;
    int s;
    printf("Valore (1-13) e seme (0 cuori, 1 quadri, 2 fiori, 3 picche): ");
    if (scanf("%d %d", &c.valore, &s) != 2 || c.valore < 1 || c.valore > 13 || s < CUORI || s > PICCHE) {
        printf("Carta non valida\n");
        c.valore = 0;
        c.seme = CUORI;
        return c;
    }
    c.seme = (Seme)s;
    return c;
}

static Confronto confronta(Carta a, Carta b) {
    if (a.valore < b.valore) {
        return CONFRONTO_MINORE;
    }

    if (a.valore > b.valore) {
        return CONFRONTO_MAGGIORE;
    }

    return CONFRONTO_UGUALE;
}

static const char *nome_seme(Seme s) {
    switch (s) {
        case CUORI: return "cuori";
        case FIORI: return "fiori";
        case QUADRI: return "quadri";
        case PICCHE: return "picche";
    }

    return "?";
}

int main(void) {
    Carta a = leggi();
    Carta b = leggi();
    Confronto confronto;

    if (a.valore == 0 || b.valore == 0) {
        return 1;
    }

    printf("Prima carta: %d di %s\n", a.valore, nome_seme(a.seme));
    printf("Seconda carta: %d di %s\n", b.valore, nome_seme(b.seme));

    confronto = confronta(a, b);

    switch (confronto) {
        case CONFRONTO_MINORE:
            printf("la seconda carta ha valore maggiore.");
            break;
        case CONFRONTO_UGUALE:
            printf("le due carte hanno lo stesso valore.");
            break;
        default:
            printf("la prima carta ha valore maggiore.");
            break;
    }

    return 0;
}
