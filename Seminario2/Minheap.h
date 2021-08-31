#ifndef Minheap_H
#define Minheap_H

typedef struct heap *Heap;

Heap Inicializar(int num);
Heap Destruir(Heap h);
void Inserir(Heap h, int codigo, void *objeto, int sizeObj);
void Imprimir(Heap h);
int Remover(Heap h,void *objeto, int sizeObj);


#endif
