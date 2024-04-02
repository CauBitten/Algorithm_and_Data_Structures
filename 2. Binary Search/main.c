#include <stdio.h>

int recursive_binary_search(int* vector, int begin, int end, int item)
{
    /* Índice representando o meio do sub-vetor begin->end */
    int i = (begin + end) / 2;

    if (begin > end) {  /* Ponto de parada. Item não está no vetor */
        return -1;
    }

    if (vector[i] == item) {  /* Item encontrado */
        return i;
    }

    if (vector[i] < item) {  /* Item está no sub-vetor à direita */
        return recursive_binary_search(vector, i + 1, end, item);


    } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
        return recursive_binary_search(vector, begin, i - 1, item);
    }
}

int iterative_binary_search(int* vector, int n, int item)
{
    int begin = 0;
    int end = n - 1;

    while (begin <= end) {  /* Condição de parada */

        int i = (begin + end) / 2;  /* Calcula o meio do sub-vetor */

        if (vector[i] == item) {  /* Item encontrado */
            return i;
        }

        if (vector[i] < item) {  /* Item está no sub-vetor à direita */
            begin = i + 1;
        } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
            end = i;
        }
    }

    return -1;
}

int main(void) {

    int array[] = {1, 3, 5, 9, 11, 12, 18, 22, 33, 50};

    printf("%d\n",recursive_binary_search(array, 0, 9, 5));

    printf("%d",iterative_binary_search(array, 10, 18));

    return 0;
}