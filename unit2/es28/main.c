#include <stdio.h>

int main(void) {
    enum week {Mon, Tue, Wed, Thur, Fri, Sat, Sun};
    enum week day;

    day = Wed;

    // Stamperà 2
    printf("%d", day);

    return 0;
}
