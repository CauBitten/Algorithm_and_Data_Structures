#include <stdio.h>
#define MAX 10

typedef struct fila {

  int inicio;
  int n_elem;
  int data[MAX];

} Fila;

void inicializar(Fila *f) {
  f->inicio = 0;
  f->n_elem = 0;
}

void inserir(Fila *f, int valor) {

  if (f->n_elem == MAX) {
    printf("A fila já está cheia!\n");

  } else {
    int fim = (f->inicio + f->n_elem) % MAX;
    f->n_elem++;
    f->data[fim] = valor;
  }
}

void remover(Fila *f) {
  if (f->n_elem > 0) {

    if (f->inicio == MAX - 1) {
      f->inicio = 0;
      f->n_elem--;

    } else {
      f->inicio++;
      f->n_elem--;
    }

  } else {
    printf("Não há elementos para remover!\n");
  }
}

void imprimir(Fila *f) {
  if (f->n_elem > 0) {

    int i = f->inicio;
    int cont = f->n_elem;

    while (cont > 0) {
      if (i == MAX) {
        i = 0;
      }

      printf("%d ", f->data[i]);
      i++;
      cont--;
    }
    printf("\n");
  } else {
    printf("Fila vazia!\n");
  }
}

int main(void) {

  Fila fila;

  inicializar(&fila);
  imprimir(&fila);

  inserir(&fila, 10);
  inserir(&fila, 70);
  inserir(&fila, 33);
  imprimir(&fila);

  remover(&fila);
  imprimir(&fila);

  inserir(&fila, 69);
  inserir(&fila, 10);
  inserir(&fila, 4);
  inserir(&fila, 57);
  imprimir(&fila);

  remover(&fila);
  imprimir(&fila);

  return 0;
}