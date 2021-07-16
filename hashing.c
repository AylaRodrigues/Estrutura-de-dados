// Grupo: Ayla Rodrigues, Douglas Mareli, Sofia Kitaeva
// Exercicio de Hashing - Estrutura de dados

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct registro {
	
	int mat;
	char nome[20];
	char curso[50];
	int disponibilidade;
	
}registro;

int hash(int key, int size) {
	return key % size;
}

void inicializar(char *nomeArq) {
	FILE *arq = fopen(nomeArq, "wb");
	registro a;
	for(int i = 0; i < 20; i++) {
		fwrite(&a, sizeof(registro), 1, arq);
	}
	
	fclose(arq);
}

int main(){
	setlocale(LC_ALL, "");
	
	int opcao = 0;
	
	inicializar("alunos.bin");
	
	while(opcao!=4)
	{
		printf("O que deseja fazer?\n 1.Inserir novo aluno\n 2.Impremir as informa��es de um determinado aluno\n 3.Imprimir tabela Hash\n 4.Sair\n>");
		scanf("%d", &opcao);
		printf("\n");
		
		if (opcao==1)//inserir elemento
		{
			
		}
		else if(opcao==2)//remover elemento
		{
			
			
		}
		else if(opcao==3)//imprimir heap
		{
			
		}
		else if(opcao == 4) {
			opcao = 4;
		}
		
		printf("\n\n");
		system("pause");
		system("cls");
	}
		
		printf("O usu�rio saiu!\n");
		
	return 0;
}
