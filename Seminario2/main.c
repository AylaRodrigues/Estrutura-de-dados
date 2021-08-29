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
	
	Heap heap = Inicializar();
	
	int opcao = 0;
	while(opcao!=4)  {
		MenuOpcoes();
		scanf("%d", &opcao);
		
		if(opcao == 1) //Inserir Elemento
		{
			// gerar chave aleatória
			//srand(time(0));
			//int chave = rand()%100;
			int chave;
			printf("Digite a chave:\n");
			scanf("%d", &chave);
			
			int num;
			printf("Digite um numero:\n");
			scanf("%d", &num);
			
			heap = Inserir(heap, chave, &num, sizeof(int));
			
			
		}else if(opcao == 2) //Remover Elemento
		{
			
	
		}else if(opcao == 3) {
		//retornar a chave e a estrutura do item removido?
		}
		
		else if(opcao == 4) {
			break;
		}
		
		printf("\n\n");
		system("pause");	
	}

	printf("O usuário saiu!\n");
	return 0;
	
}
