#include <stdio.h>

struct Punto2D {
    int x;
    int y;
};

#define N 5
#define C 2

int main(void) {
    struct Punto2D P[N];
    int vx[N];
    int vy[N];
    int M[N][C];

    for (int i=0; i<N; i++) {
        printf("Inserisci la coppia nr. %d: ", i);
        scanf("%d %d", &P[i].x, &P[i].y);
    }

    for (int i=0; i<N; i++) {
        vx[i] = P[i].x;
        vy[i] = P[i].y;
    }

    for (int i = 0; i < N; i++) {
        M[i][0] = vx[i];
        M[i][1] = vy[i];
    }

    printf("   x    y\n");
    for (int i = 0; i < N; i++) {
        printf("%4d %4d\n", M[i][0], M[i][1]);
    }

    return 0;
}
