#include <stdio.h>

enum year {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};



int main(void) {
    int i;

    // stamperà da 0 a 11
    for (i=Jan; i<=Dec; printf("%d ", i++));

    return 0;
}
