#include <stdio.h>
#include <stdlib.h>

static void merge (int Arr[], int p, int mid, int r) {
    int i = p, j = mid+1, k = p;
    int B[100];

    while (i <= mid && j <= r) {
        if (Arr[i] < Arr[j]) {
            B[k++] = Arr[i++];
        } else {
            B[k++] = Arr[j++];
        }
    }

    for (; i <= mid; i++) {
        B[k++] = Arr[i];
    }
    for (; j <= r; j++) {
        B[k++] = Arr[j];
    }
    for (i = 0; i <= r; i++) {
        Arr[i] = B[i];
    }
}

void mergesort (int Arr[], int p, int r) {
    if (p < r) {
        int mid = (r+p) / 2;
        mergesort(Arr, p, mid);
        mergesort(Arr, mid+1, r);
        merge(Arr, p, mid, r);
    }
}

int main() {

    int A[] = {14, 23, 3, 45, 29, 56, 33, 80, 69, 96};

    mergesort(A, 0, 9);

    for (int i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
