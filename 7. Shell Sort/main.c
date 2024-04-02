#include <stdio.h>

void shell_sort (int* v, int n) {
    int gap, i, j, temp;

    // Define o valor inicial do intervalo de gap
    for (gap = n/2; gap > 0; gap /= 2) {
        // Executa a inserção do intervalo de gap
        for (i = gap; i < n; i++) {
            temp = v[i];
            // Move os elementos anteriores do intervalo de gap, que são maiores que o elemento atual, para frente
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            // Insere o elemento atual no local correto no intervalo de gap
            v[j] = temp;
        }
    }
}

void printarr (int* v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

int main() {

    int A[10] = {73, 67, 56, 32, 52, 41, 83, 37, 32, 10};

    shell_sort(A, 10);

    printarr(A, 10);

    return 0;
}
