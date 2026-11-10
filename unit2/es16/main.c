#include <stdio.h>
#include <limits.h>

int main(void) {
    int x = INT_MAX;

    printf("X: %d\n", x);

    x++;

    printf("X: %d", x);

    return 0;
}
