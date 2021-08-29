#ifndef Minheap_H
#define Minheap_H

typedef struct heap *Heap;

Heap Inicializar();
Heap Inserir(Heap h, int codigo, void *objeto, int sizeObj);
void Remover();
void Imprimir();
Heap DestroiHeap(Heap h);


#endif
