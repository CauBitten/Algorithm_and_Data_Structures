#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ajustar um sub-heap máximo
void max_heapify(int arr[], int n, int i) {
    int maior = i;                  // Inicialmente, considera o pai como o maior
    int filho_esq = 2 * i + 1;      // Índice do filho esquerdo
    int filho_dir = 2 * i + 2;      // Índice do filho direito

    // Se o filho esquerdo for maior que o pai
    if (filho_esq < n && arr[filho_esq] > arr[maior])
        maior = filho_esq;

    // Se o filho direito for maior que o pai
    if (filho_dir < n && arr[filho_dir] > arr[maior])
        maior = filho_dir;

    // Se o maior não for o pai, troca e ajusta o sub-heap
    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        max_heapify(arr, n, maior);
    }
}

// Função principal do Heapsort
void heapsort(int arr[], int n) {
    // Constrói o heap máximo
    for (int i = (n-1) / 2; i >= 0; i--)
        max_heapify(arr, n, i);

    // Extrai os elementos do heap um por um
    for (int i = n - 1; i >= 0; i--) {
        trocar(&arr[0],&arr[i]);        // Move a raiz (maior elemento) para o fim do array
        max_heapify(arr, i, 0);         // Chama max_heapify para o heap reduzido
    }
}

void printarVetor (int n, int* v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

int main() {

    int v[] = {10, 90, 23, 54, 5, 3, 9, 44, 32, 15};

    heapsort(v, 10);

    printarVetor(10, v);

    return 0;
}
