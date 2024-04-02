#include <stdio.h>

#define MAX 10

//int topo = -1;
//
//void push (int data[], int valor) {
//    if (topo+1 < MAX) {
//        topo++;
//        data[topo] = valor;
//    } else {
//        printf("A pilha esta cheia\n\n");
//    }
//}
//
//int pop (int data[]) {
//    int valor = 0;
//
//    if (topo >= 0) {
//        valor = data[topo];
//        topo--;
//    } else {
//        printf("A pilha ja esta vazia\n\n");
//    }
//
//    return valor;
//}
//
//void imprimir (int data[]) {
//    for (int i = 0; i <= topo; i++) {
//        printf("%d ", data[i]);
//    }
//    printf("\n");
//}

typedef struct pilha {
    int topo;
    int data[MAX];
} Pilha;

void inicializa (Pilha* pi) {
    pi->topo = -1;
}

void push (Pilha* pi, int valor) {
    if (pi->topo + 1 == MAX) {
        printf("Pilha cheia!");
    } else {
        pi->topo++;
        pi->data[pi->topo] = valor;
    }
}

int pop (Pilha* pi) {
    if (pi->topo >= 0) {
        pi->topo--;
        return pi->data[pi->topo+1];
    } else {
        printf("Pilha já está vazia!");
    }
    return -1;
}

void imprimirPilhaStruct (Pilha* pi) {
    for (int i = pi->topo; i >= 0; i--) {
        printf("%d ", pi->data[i]);
    }
}

int main(void) {

    int data[MAX];

//    push(data, 10);
//    push(data, 25);
//
//    imprimir(data);
//
//    pop(data);
//
//    imprimir(data);
//
//    int ret = pop(data);
//
//    imprimir(data); // Pilha já vazia
//    printf("Valor retirado do ultimo pop valido: %d\n\n", ret);
//
//    pop(data); // Não foi possível retirar elemento de pilha vazia

//    push(data, 10);
//    push(data, 25);
//    push(data, 33);
//    push(data, 212);
//    push(data, 80);
//    push(data, 99);
//    push(data, 69);
//    push(data, 45);
//    push(data, 11);
//    push(data, 144);
//
//    imprimir(data);
//
//    printf("\n");
//
//    push(data, 10);

    Pilha pi;
    inicializa(&pi);

    push(&pi, 15);
    push(&pi, 23);
    push(&pi, 55);
    imprimirPilhaStruct(&pi);

    int removido = pop(&pi);

    printf("\nElem. removido: %d\n", removido);

    imprimirPilhaStruct(&pi);

    return 0;
}
