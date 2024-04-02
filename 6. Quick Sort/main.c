#include <stdio.h>

int partition(int* values, int left, int right) {

    int pivot = values[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (values[j] < pivot) {

            i++;

            int temp = values[i];
            values[i] = values[j];
            values[j] = temp;
        }
    }
    int temp = values[i+1];
    values[i+1] = values[right];
    values[right] = temp;

    return i+1;
}

void quickSort(int* values, int left, int right) {
    if (left < right) {
        int index_pivot = partition(values, left, right);
        quickSort(values, left, index_pivot - 1);
        quickSort(values, index_pivot + 1, right);
    }
}

void printar (int* v, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }
}

int main() {

    int A[10] = {12, 90, 77, 32, 27, 5, 1, 9, 55, 46};

    quickSort(A, 0, 9);

    printar(A, 10);

    return 0;
}
