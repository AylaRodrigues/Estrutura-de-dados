// Grupo: Ayla Rodrigues, Douglas Mareli, Sofia Kitaeva
// Exercicio de Hashing - Estrutura de dados

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define N 11

typedef struct registro {
	
	int mat;
	char nome[20];
	char curso[50];
	int disponibilidade;
	
}Registro;

int hash(int key, int size) 
{
	return key % size;
}

void inicializar(char *nomeArq) 
{
	FILE *arq = fopen("alunos.bin", "wb");
	Registro a;
	a.disponibilidade=1;
	for(int i = 0; i < 20; i++) {
		fwrite(&a, sizeof(Registro), 1, arq);
	}
	
	fclose(arq);
}

int AcharPosicao(char *nomeArq, int mat)
{
	int pos = hash(mat, N);

	Registro a;
	FILE *arq=fopen("alunos.bin","rb");
	fseek(arq, pos*sizeof(Registro),SEEK_SET);
	fread(&a,sizeof(Registro), 1, arq);

	while(a.disponibilidade == 0)
	{
		pos=(pos+1)%N;
		fseek(arq, pos*sizeof(Registro),SEEK_SET);
		fread(&a,sizeof(Registro), 1, arq);
	}
	fclose(arq);
	return pos;
}

void inserir(char *nomeArq, int mat, char *nome, char *curso) 
{
	int pos = AcharPosicao("alunos.bin", mat);

	FILE *arq = fopen("alunos.bin", "r+b");

	Registro a;
	a.mat = mat;
	strcpy(a.nome, nome);
	strcpy(a.curso, curso);
	a.disponibilidade=0;

	fseek(arq, pos*sizeof(Registro), SEEK_SET);
	fwrite(&a, sizeof(Registro), 1, arq);
	printf("Aluno inserido com sucesso\n\n");

	fclose(arq);
	Sleep(1000);
	system("cls");
}

void buscarAluno(char *nome)
{
	FILE *arquivo;

	Registro registro;

	arquivo=fopen("alunos.bin", "rb");

	if (arquivo == NULL)
	{
		printf("Problemas na leitura do arquivo\n");
	}
	else
	{
		while(fread(&registro, sizeof(Registro), 1, arquivo)==1)
		{
			if(nome == registro.nome)
			{
				//nao chega ate aqui
				printf("> Nome do aluno : %s\n", nome);
				printf("> Matricula do aluno : %s\n", registro.mat);
				printf("> Curso do aluno : %s\n", registro.curso);
			}
		}
	}

	Sleep(1000);
	system("cls");
	fclose(arquivo);
}

int main()
{
	setlocale(LC_ALL, "");
	
	int opcao = 0;
	int matricula;
	char nome[20];
	char curso[50];
	
	inicializar("alunos.bin");
	
	while(opcao!=4)
	{
		printf("O que deseja fazer?\n 1.Inserir novo aluno\n 2.Imprimir as informações de um determinado aluno\n 3.Imprimir tabela Hash\n 4.Sair\n\n>");
		scanf("%d", &opcao);
		printf("\n");
		
		if (opcao==1)//inserir novo aluno
		{
			printf("> Qual a matricula do aluno?\n");
			scanf("%d", &matricula);

			printf("> Qual o nome do aluno?\n");
			scanf("%s", &nome);

			printf("> Qual o curso do aluno?\n");
			scanf("%s", &curso);

			inserir("alunos.bin", matricula, nome, curso);

		}
		else if(opcao==2)//imprimir info
		{
			printf("> Qual o nome do aluno?\n");
			scanf("%s", &nome);

			buscarAluno(nome);
			
		}
		else if(opcao==3)//imprimir tabela de dispersao
		{
			
		}
		printf("\n\n");
		system("cls");
	}
	printf("O usuário saiu!\n");

	return 0;
}
