#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(void) {
    float num = FLT_MIN;

    printf("Num: %e\n", num);

    num = num / FLT_MAX;

    printf("Num diviso FLT_MAX: %e\n", num);

    return 0;
}
