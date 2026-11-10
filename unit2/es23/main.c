#include <stdio.h>
#include <stdlib.h>

#define ALIQUOTA_IVA 22.0

typedef double Euro;
typedef unsigned char Byte;

Euro con_iva(Euro netto) {
    Euro lordo = netto + ((netto * ALIQUOTA_IVA) / 100);

    return lordo;
}

int main(void) {

    Euro prezzo_netto;

    printf("Inserisci un prezzo (maggiore di 0): ");
    if (scanf("%lf", &prezzo_netto) != 1 || prezzo_netto <= 0) {
        printf("Errore: il prezzo inserito non è valido\n");
        return EXIT_FAILURE;
    }

    Euro prezzo_lordo = con_iva(prezzo_netto);

    printf("Prezzo con iva: %.2f euro\n", prezzo_lordo);

    printf("sizeOf(Euro): %zu\n", sizeof(Euro));
    printf("sizeOf(Euro): %zu\n", sizeof(Byte));

    return 0;
}
