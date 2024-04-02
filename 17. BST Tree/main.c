#include <stdio.h>
#include <stdlib.h>

// Árvore Binária de Busca

typedef struct arvore {

    int info;
    struct No* esq;
    struct No* dir;

} Arvore;

Arvore* criarNo(int valor) {

    Arvore* novoN = (Arvore*) malloc (sizeof(Arvore));
    novoN->info = valor;
    novoN->esq = NULL;
    novoN->dir = NULL;

    return novoN;
}

Arvore* inserir(Arvore* raiz, Arvore* no) {

    if (raiz == NULL) {
        raiz = no;

    } else {
        if (no->info < raiz->info) {
            raiz->esq = inserir(raiz->esq, no);

        } else {
            raiz->dir = inserir(raiz->dir, no);

        }
    }

    return raiz;
}

void imprimir_pre_ordem (Arvore* raiz) {
    if (raiz != NULL) {

        printf("%d ", raiz->info);

        imprimir_pre_ordem(raiz->esq);

        imprimir_pre_ordem(raiz->dir);
    }
}

void imprimir_ordem (Arvore* raiz) {
    if (raiz != NULL) {

        imprimir_ordem(raiz->esq);

        printf("%d ", raiz->info);

        imprimir_ordem(raiz->dir);
    }
}

Arvore* remove_raiz (Arvore* raiz) {
    Arvore* p, *q;

    if (raiz == NULL) {
        return NULL;

    } else if (raiz->esq == NULL) {
        q = raiz->dir;
        free(raiz);
        return q;

    } else {
        p = raiz;
        q = raiz->esq;

        while (q->dir != NULL) {
            p = q;
            q = q->dir;

        }

        if (p != raiz) {
            p->dir = q->esq;
            q->esq = raiz->esq;

        }

        q->dir = raiz->dir;
        free(raiz);
        return q;
    }
}

Arvore* busca (Arvore* r, int k) {
    if (r == NULL || k == r->info) return r;

    if (r->info > k) return busca(r->esq, k);
    else return busca(r->dir, k);
}

void imprimirNo (Arvore* no) {
    printf("%d ", no->info);
}

int main(void) {

    Arvore* raiz = NULL;

    raiz = inserir(raiz, criarNo(15));
    raiz = inserir(raiz, criarNo(11));
    raiz = inserir(raiz, criarNo(23));
    raiz = inserir(raiz, criarNo(33));
    raiz = inserir(raiz, criarNo(2));
    raiz = inserir(raiz, criarNo(16));
    raiz = inserir(raiz, criarNo(45));

    imprimir_ordem(raiz);

    raiz = remove_raiz(raiz);

    printf("\n\n");

    imprimir_ordem(raiz);

    printf("\n\n");

    imprimirNo(busca(raiz, 45));

    return 0;
}
