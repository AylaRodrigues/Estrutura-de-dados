#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Minheap.h"

#define N 20

typedef struct item {
	int chave;
	void *objeto;
}Item;

struct heap{
	int totalElementos;
	Item vet[N];
};

Heap Inicializar() {
	Heap h = (Heap)malloc(sizeof(Heap));
	for(int i = 0; i < N; i++) {
		h->vet[i].objeto = NULL;
	}
	h->totalElementos = 0;
	return h;
}

int IndiceFilhoEsq(Heap h, int x)
{
	int indice=(2*x)+1;
	if (x >= h->totalElementos || indice >= h->totalElementos)
	{
		return -1;
	}
	else
		return indice;
}

int IndiceFilhoDir(Heap h, int x)
{
	int indice = (2 * x) + 2;
	if (x >= h->totalElementos || indice >= h->totalElementos)
	{
		return -1;
	}
	else
		return indice;
}

int IndicePai(Heap h, int x)
{
	int indice = (int)floor((x - 1) / 2);
	if (x <= 0 || x > h->totalElementos)
	{
		return -1;
	}
	else
		return indice;
}

Heap AjustarSubindo(Heap h, int pos)
{
	if (pos != -1)
	{
		int pai = IndicePai(h, pos);
		if (pai != -1)
		{
			
			if (h->vet[pos].chave < h->vet[pai].chave)
			{
				Item aux = h->vet[pos];
				h->vet[pos] = h->vet[pai];
				h->vet[pai] = aux;
				h = AjustarSubindo(h, pai);
				
			}
		}
	}
	
	return h;
}

Heap Inserir(Heap h, int chave, void *objeto, int sizeObj) {

	h->vet[h->totalElementos].chave = chave;
	h->vet[h->totalElementos].objeto = (void *)malloc(sizeObj);
	memcpy(h->vet[h->totalElementos].objeto, objeto, sizeObj);
	
	h->totalElementos++;
	
	h = AjustarSubindo(h, h->totalElementos-1);
	
	return h;

}

