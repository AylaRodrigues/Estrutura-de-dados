#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Minheap.h"


typedef struct item {
	int chave;
	void *objeto;
}Item;

struct heap{
	int totalElementos;
	Item *vet;
};

Heap Inicializar(int num) {
	Heap h = (Heap)malloc(sizeof(Heap));
	h->vet = (Item *)malloc(num*sizeof(Item));
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

void AjustarSubindo(Heap h, int pos)
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
				AjustarSubindo(h, pai);
				
			}
		}
	}
	
}

void AjustarDescendo(Heap h, int pos)
{
	if (pos != -1 && IndiceFilhoEsq(h, pos) != -1)
	{
		int indiceMenorFilho = IndiceFilhoEsq(h, pos);
		if (IndiceFilhoDir(h, pos) != -1 && h->vet[IndiceFilhoDir(h, pos)].chave < h->vet[indiceMenorFilho].chave)
		{
			indiceMenorFilho = IndiceFilhoDir(h, pos);
		}

		if (h->vet[indiceMenorFilho].chave < h->vet[pos].chave)
		{
			Item aux = h->vet[pos];
			h->vet[pos] = h->vet[indiceMenorFilho];
			h->vet[indiceMenorFilho] = aux;
			AjustarSubindo(h, indiceMenorFilho);
		}
	}
	
}

void Inserir(Heap h, int chave, void *objeto, int sizeObj) {

	h->vet[h->totalElementos].chave = chave;
	h->vet[h->totalElementos].objeto = (void *)malloc(sizeObj);
	memcpy(h->vet[h->totalElementos].objeto, objeto, sizeObj);
	
	h->totalElementos++;
	AjustarSubindo(h, h->totalElementos-1);
	
}

int Remover(Heap h, int *chave, void *objeto, int sizeObj) {
	if(h->totalElementos == 0)
		return 0; // caso não encontre nada
	else {
		*chave = h->vet[0].chave;
		memcpy(objeto, h->vet[0].objeto, sizeObj);
		free(h->vet[0].objeto);
		h->vet[0] = h->vet[(h->totalElementos)-1];
		h->vet[(h->totalElementos)-1].objeto = NULL;
		h->totalElementos--;
		AjustarDescendo(h, 0);
		return 1;
	}
}

void Imprimir(Heap h) {
	
	if(h->totalElementos == 0) {
		printf("\n---- Não há elementos no heap ----\n");	
	}
	
	for(int i = 0; i < h->totalElementos; i++) {
		printf("- %d -", h->vet[i].chave);
	}
	printf("\n");
	
}

Heap Destruir(Heap h) {
	for(int i = 0; i < h->totalElementos; i++) {
		free(h->vet[i].objeto);
	}
	free(h->vet);
	free(h);
	
	return NULL;
}
