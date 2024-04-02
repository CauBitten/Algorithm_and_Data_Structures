#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {

int valor;
struct No* direita;
struct No* esquerda;

} Arvore;

Arvore* criar (int valor, Arvore* esq, Arvore* dir) {
    Arvore* novoNo = (Arvore*) malloc (sizeof(Arvore));
  novoNo->valor = valor;
  novoNo->direita = dir;
  novoNo->esquerda = esq;

  return novoNo;
}

int altura (Arvore* r) {
  if (r == NULL) {
    return -1;
  }

  int h_esq = altura(r->esquerda);
  int h_dir = altura(r->direita);

  if (h_esq > h_dir) {
      return 1 + h_esq;
  } else {
      return 1 + h_dir;
  }
}

void red (Arvore* r) {
  if (r != NULL) {
    printf("   %d   \n", r->valor);
    red(r->esquerda);
    red(r->direita);
  }
}

void erd (Arvore* r) {
  if (r != NULL) {
    erd(r->esquerda);
    printf("   %d   \n", r->valor);
    erd(r->direita);
  }
}

void edr (Arvore* r) {
    if (r != NULL) {
        edr(r->esquerda);
        edr(r->direita);
        printf("%d ", r->valor);
    }
}

int main(void) {

    Arvore* x = criar(0, NULL, NULL);
    Arvore* y = criar(2, NULL, NULL);

    Arvore* a = criar(1, NULL, NULL);
    Arvore* b = criar(4, NULL, NULL);

    Arvore* c = criar(3, a, b);

    Arvore* z = criar(7, NULL, NULL);

    Arvore* d = criar(6, NULL, z);
    Arvore* e = criar(9, NULL, NULL);

    Arvore* f = criar(8, d, e);

  // Raiz da árvore
  Arvore* g = criar(5, c, f);

  erd(g);

  /*

                g                          ..0
        c             f                    ..1
    a       b     d       e                ..2
  x   y              z                     ..3

  */

  int alt = altura(g);
  printf("\nAltura da árvore: %d\n", alt);

  return 0;
}