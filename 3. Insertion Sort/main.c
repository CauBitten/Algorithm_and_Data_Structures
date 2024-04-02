#include <stdio.h>
  void insertionSort (int vetor[10]) {

    int i, key;

    for (int j = 1; j < 10; j++) {
        key = vetor[j];
        i = j - 1;

        while (i >= 0 && vetor[i] > key) {
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1] = key;
    }
}

void print (int vetor[10]) {
    for (int i = 0; i < 10; i++) {
        printf("%i ", vetor[i]);
    }
}

int main(void) {

    int vetor[10] = {5, 10, 3, 7, 8, 6, 1, 2, 9, 4};

    insertionSort(vetor);

    print(vetor);

    return 0;
}