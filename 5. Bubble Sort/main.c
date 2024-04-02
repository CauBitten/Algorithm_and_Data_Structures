#include <stdio.h>
#include <time.h>

void bubble_sort (int* v, int f) {
    int temp;

    for (int i = 0; i < f-1; i++) {

        for (int j = i+1; j < f; j++) {
            if (v[j] < v[i]) {
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
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

    int A[10] = {9, 12, 1, 35, 88, 3, 10, 53, 20, 15};

    bubble_sort(A, 10);

    printar(A, 10);

    clock_t end = clock();
    tempo = (double) (end-begin) / CLOCKS_PER_SEC;

    printf("\nTempo bubble sort: %f", tempo);

    return 0;
}
