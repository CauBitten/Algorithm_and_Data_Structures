#include <stdio.h>

int NOP;

int fibo_rec(int n) { // Recursiva

    if (n == 1) {
        return 0;
    }

    if (n == 2 || n == 3) {
        return 1;
    }

    NOP += 2;
    return fibo_rec(n - 1) + fibo_rec(n - 2);
}

int fibo_it(int n) { // Interativo
    int pen = 1, ult = 1, temp;

    NOP = 1;

    if (n == 1) {
        return 0;
    }

    for (int i = 4; i <= n; i++) {
        temp = ult;
        ult = pen + ult;
        pen = temp;
        NOP += 3;
    }

    return ult;
}

int main() {

    int n = 1;

    while (n != 0) {
        NOP = 0;
        printf(": ");
        scanf("%d", &n);
        getchar();

        if (n > 0) {
            printf("\n%d\n", fibo_it(n));
            printf("%d\n", fibo_rec(n));
            printf("NOP = %d\n", NOP);
        }
    }

    return 0;
}