//Grupo: Ayla Rodrigues, Douglas Mareli, Sofia Kitaeva
//MinHeap- TAD

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Minheap.h"
#include <time.h>

void MenuOpcoes(){
	printf("O que deseja fazer?\n");
	printf(" 1.Inserir um elemento no heap.\n");
	printf(" 2.Remover um elemento do heap.\n");
	printf(" 3.Impimir o heap.\n");
	printf(" 4.Sair\n");	
}

int main() {
	setlocale(LC_ALL, "");
	
	printf("Digite o tamanho do Heap que deseja:\n");
	int tamanho;
	scanf("%d",&tamanho);
	
	Heap heap = Inicializar(tamanho);
	
	int opcao = 0;
	while(opcao!=4)  {
		MenuOpcoes();
		scanf("%d", &opcao);
		
		if(opcao == 1) //Inserir Elemento
		{
			//gerar chave aleatória
			srand(time(0));
			int chave = rand()%100;
			
			//exemplo
			char palavra[20];
			printf("Digite uma string:\n");
			scanf("%s", palavra);
			
			Inserir(heap, chave, &palavra, 20*sizeof(char));
			

		}else if(opcao == 2) //Remover Elemento
		{
			int chave;
			char palavra[20];
			int removeu = Remover(heap, &chave, &palavra, sizeof(int));
			printf("Chave %d\nObjeto: %s\n", chave, palavra);
			
	
		}else if(opcao == 3) 
		{
			Imprimir(heap);
			
		}else if(opcao == 4) {
			heap = Destruir(heap);
			printf("------------------\n");
			printf(" Heap destruitdo\n");
			printf("------------------\n");
		}
		
		printf("\n\n");	
	}
	
	printf("O usuário saiu!\n");
	return 0;
	
}
