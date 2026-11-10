#include <stdio.h>

enum State {WORKING = 0, FAILED, FREEZED};

enum State currState = 2;

int main(void) {
    // Stamperà NOT_WORKING
    (currState == WORKING) ? printf("WORKING") : printf("NOT WORKING");

    return 0;
}
