#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("CHAR_MAX:\t%d\n", CHAR_MAX);
    printf("CHAR_MIN:\t%d\n", CHAR_MIN);
    printf("INT_MAX:\t%d\n", INT_MAX);
    printf("INT_MIN:\t%d\n", INT_MIN);

    printf("FLOAT_MAX:\t%e\n", FLT_MAX);
    printf("FLOAT_MIN:\t%e\n", -FLT_MAX);
    printf("DOUBLE_MAX:\t%e\n", DBL_MAX);
    printf("DOUBLE_MIN:\t%e", -DBL_MAX);
    return 0;
}
