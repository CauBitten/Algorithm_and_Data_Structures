#include <stdio.h>
#include <stdlib.h>

struct lista {

int info;
struct lista* prox;

};

typedef struct lista Lista;

// Garantir que REF aponta para null quando não tem elementos na lista;
Lista* criaLista()
{
    return NULL;
}

// Inserindo elemento no inicio da lista
Lista* insere(Lista* ref, int valor)
{
    Lista* novaCelula = (Lista*) malloc(sizeof(Lista)); // Cria uma célula (nó)
    novaCelula->info = valor;   // Data
    novaCelula->prox = ref;     // Vira o primeiro elento da lista
    ref = novaCelula;           // Head (REF) aponta para o elemento adicionado
    return ref;
}

// Impressão dos elementos da lista (Imprime em ordem de trás para frente)
void impressao (Lista* ref) {
    Lista* p;
    if (ref == NULL) {
        printf("Lista vazia!");
    } else {

        for (p = ref; p != NULL; p = p->prox) {
            printf("%d ", p->info);
        }
    }
}

void imprimirOrdemInversa (Lista* ref) {
    Lista* p;

    int size = 0;

    if (ref == NULL) {
        printf("Lista vazia!");
    } else {
        for (p = ref; p != NULL; p = p->prox) {
            size++;
        }
    }

    int vet[size];

    if (size > 0) {

        p = ref;

        for (int i = size-1; i >= 0; i--) {
            vet[i] = p->info;
            p = p->prox;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", vet[i]);
    }
}

Lista* removes (Lista* ref, int elemBuscado) {
    Lista *ant = NULL;
    Lista *p = ref;

    while (p != NULL && p->info != elemBuscado)
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        printf("Elemento não encontrado!");

        // Primeiro elemento da lista a ser removido
    } else if (p == ref) {
        ref = p->prox;

        // Elemento encontrado
    } else {
        ant->prox = p->prox;
    }

    free(p);
    return ref;
}

/*
 *
 *  Agora irei implementar uma lista ligada dupla
 *
 * */

struct listaDupla {

    int info;
    struct listaDupla* ant;
    struct listaDupla* prox;

};

typedef struct listaDupla ListaDupla;

ListaDupla* criarListaDupla () {
    return NULL;
}

ListaDupla* inserirEl (ListaDupla* ref, int valor) {

    ListaDupla* novaCelula = (ListaDupla*) malloc(sizeof (ListaDupla*));

    if (ref == NULL) {
        novaCelula->ant = NULL;
        novaCelula->info = valor;
        novaCelula->prox = ref;
        ref = novaCelula;

    } else {
        ListaDupla* p;

        p = ref;

        while (p->prox != NULL) {
            p = p->prox;
        }

        novaCelula->ant = p;
        novaCelula->info = valor;
        novaCelula->prox = ref;
        ref = novaCelula;
    }

    return ref;
}

void imprimirListaDupla (ListaDupla* ref) {
    ListaDupla* p;

    p = ref;

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }
}

//void imprimirListaDuplaOrdemInversa (ListaDupla* ref) {
//    ListaDupla* p;
//
//    p = ref;
//
//    // Chega no ultimo elemento da lista
//    while (p->prox != NULL) {
//        p = p->prox;
//    }
//
//    for (; p != NULL; p = p->ant) {
//        printf("%d ", p->info);
//    }
//
//}

ListaDupla* removerEl (ListaDupla* ref, int valor) {
    ListaDupla* p;

    p = ref;

    if (p->info == valor) {
        ref = p->prox;
        free(p);
    } else {

        for (; p != NULL; p = p->prox) {

        }
    }
}

int main() {

    Lista* ref = criaLista();

    ref = insere(ref, 10);
    ref = insere(ref, 15);
    ref = insere(ref, 4);
    ref = insere(ref, 9);

    printf("Imprimindo a lista simples: ");
    impressao(ref);

    printf("\n\n");

    printf("Removendo o elemento 10: ");
    removes(ref, 10);
    impressao(ref);

    printf("\n\n");

    printf("Imprimindo na ordem de insercao (Inversa): ");
    imprimirOrdemInversa(ref);

    /*
     *
     *
     * */

    printf("\n\n");

    ListaDupla* head = criarListaDupla();

    head = inserirEl(head, 10);
    head = inserirEl(head, 5);
    head = inserirEl(head, 16);
    head = inserirEl(head, 65);

    imprimirListaDupla(head);

    printf("\n\n");

    return 0;
}
