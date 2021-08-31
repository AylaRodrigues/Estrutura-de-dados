//Grupo: Ayla Rodrigues, Douglas Mareli, Sofia Kitaeva
//MinHeap- TAD

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Minheap.h"
#include <time.h>

typedef struct pessoa {
	char nome[30];
	int idade;
}Pessoa;

void MenuOpcoes(){
	printf("O que deseja fazer?\n");
	printf(" 1.Inserir um elemento no heap.\n");
	printf(" 2.Remover um elemento do heap.\n");
	printf(" 3.Impimir o heap.\n");
	printf(" 4.Sair\n");	
}

int PegaTamanhoHeap() {
	
	int tamanho; 
	printf("---- Digite o tamanho do Heap que deseja: ----\n");
	scanf("%d",&tamanho);
	
	return tamanho;
}

int main() {
	setlocale(LC_ALL, "");
	
	
	int tamanho = PegaTamanhoHeap();
	Heap heap = Inicializar(tamanho);
	
	printf("\n---- Heap Inicializado ----\n");
	
	int opcao = 0;
	printf("\n\n");
	while(opcao!=4)  {
		MenuOpcoes();
		scanf("%d", &opcao);
		
		printf("\n");
		if(opcao == 1) //Inserir Elemento
		{
			//gerar chave aleatória
			srand(time(0));
			int chave = rand()%100;
			
			//exemplo
			Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
			printf("Digite um nome:\n");
			fflush(stdin);
			scanf("%[^\n]s", p->nome);
			fflush(stdin);
			printf("Digite a idade: \n");
			scanf("%d", &p->idade);
			
			Inserir(heap, chave, &p, sizeof(Pessoa));
			
		}else if(opcao == 2) //Remover Elemento
		{
			
			Pessoa *p;
			int chave = Remover(heap, &p, sizeof(Pessoa));
			if(chave != 0) {
				printf("\n----------------\n");
				printf("Chave %d\n Objeto:\n -Nome:%s\n -Idade:%d\n", chave, p->nome, p->idade);
				printf("----------------\n");
			}
	
		}else if(opcao == 3) 
		{
			Imprimir(heap);
			
		}else if(opcao == 4) {
			heap = Destruir(heap);
			printf("------------------\n");
			printf(" Heap destruído\n");
			printf("------------------\n");
		}
		
		printf("\n\n");	
	}
	
	printf("O usuário saiu!\n");
	return 0;
	
}
