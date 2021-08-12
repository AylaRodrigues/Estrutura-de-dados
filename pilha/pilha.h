#ifndef Pilha_H
#define Pilha_H

typedef struct pilha *Pilha;
int Push(Pilha p, int x);
int Pop(Pilha p, int *x);
void Imprimir(Pilha p);

Pilha Inicializar();
Pilha Destruir(Pilha p);

#endif

