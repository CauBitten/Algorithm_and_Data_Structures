#include <stdio.h>
#include <stdlib.h>

typedef struct lista {

    int valor;
    struct Lista *prox;

} Lista;

typedef struct fila {

    Lista *inicio;
    Lista *fim;

} Fila;

void inicializar (Fila* fi) {
    fi->inicio = NULL;
    fi->fim = NULL;
}

void inserir(Fila *f, int valor) {
    Lista *novaC = (Lista *)malloc(sizeof(Lista));
    novaC->valor = valor;
    novaC->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novaC;
    } else {
        f->fim->prox = novaC;
    }

    f->fim = novaC;
}

int remover(Fila* fi) {
    int valor = 0;
    if (fi->inicio != NULL) {
        Lista* li = fi->inicio;
        fi->inicio = li->prox;

        if (fi->inicio == NULL) {
            fi->fim = NULL;
        }

        valor = li->valor;

        free(li);

    } else {
        printf("Fila já está vazia!");
    }
    return valor;
}

void imprimir(Fila* fi) {
    Lista* li = fi->inicio;

    while(li != NULL) {
        printf("%d ", li->valor);
        li = li->prox;
    }
}

int main(void) {

    Fila fi;

    inicializar(&fi);

    inserir(&fi, 15);
    inserir(&fi, 10);
    inserir(&fi, 33);

    imprimir(&fi);

    printf("\n");

    remover(&fi);

    imprimir(&fi);

    return 0;
}