#include <stdio.h>
#include <time.h>

void selection_sort (int* v, int size) {

    for (int i = 0; i < size-1; i++) {

        int i_menor = i;

        for (int j = i+1; j < size; j++) {

            if (v[j] < v[i_menor]) {
                i_menor = j;
            }

        }

        if (i_menor != i) {
            int temp = v[i];
            v[i] = v[i_menor];
            v[i_menor] = temp;
        }

    }

}

void printar (int* v, int f) {
    for (int i = 0; i < f; i++) {
        printf("%d ", v[i]);
    }
}

int main() {

    double tempo;
    clock_t begin = clock();

    int B[10] = {10, 20, 3, 99, 4, 74, 23, 33, 89, 7};

    selection_sort(B, 10);

    printar(B, 10);

    clock_t end = clock();
    tempo = (double) (end-begin) / CLOCKS_PER_SEC;

    printf("\nTempo selection sort: %f", tempo);

    return 0;
}
