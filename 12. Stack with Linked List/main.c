#include <stdio.h>
#include <stdlib.h>

typedef struct lista {

float info;
struct lista* prox;

} Lista;

typedef struct pilha {

Lista* topo;

} Pilha;

void inicializa(Pilha* pilha) {
  pilha->topo = NULL;
}

void push(Pilha* pilha, float valor) {
  Lista* novaC = (Lista*) malloc (sizeof(Lista));
  novaC->info = valor;
  novaC->prox = pilha->topo;
  pilha->topo = novaC;
}

float pop(Pilha* pilha) {
  float valor = 0;

  if (pilha->topo != NULL) {
    Lista* li = pilha->topo;
    pilha->topo = li->prox;
    valor = li->info;
    free(li);

  } else {
    printf("Impossivel remover de uma pilha vazia!\n");
  }

  return valor;
}

void imprimir(Pilha* p) {
  if (p->topo != NULL) {
    for (Lista* li = p->topo; li != NULL; li = li->prox) {
      printf("%.2f ", li->info);
    }
  } else {
    printf("Pilha vazia!\n");
  }
}

int main(void) {

  Pilha pi;

  inicializa(&pi);

  push(&pi, 10.5);
  push(&pi, 15.7);
  push(&pi, 7.7);

  imprimir(&pi);

  pop(&pi);
  pop(&pi);
  pop(&pi);

  printf("\n\n");
  imprimir(&pi);

  pop(&pi);

  return 0;
}
