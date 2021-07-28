#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void ImprimirCombinacoes(int *vet, int pos, int cent, int* vetAux){
	int aux=0;
	
	if(pos==cent){
		for(int i=0; i<cent;i++)
			aux+=vet[i];
		if(aux==cent)
		{
			for(int i=0; i<cent;i++)
			{
				if(vet[i]!=0)
				{
					printf("%d ", vet[i]);
				}
				
			}printf("\n");

		}
	}
	else{
		for(int i=0;i<=5;i++)
		{
			vet[pos]=vetAux[i];
			ImprimirCombinacoes(vet,pos+1,cent,vetAux);
		}
	}
}

int main(){
	int cent;

	printf("Quantos centavos quer representar?\n>> ");
	scanf("%d", &cent);

	int* vet = (int*) malloc(sizeof(int)*cent);
	int* vetAux = (int*) malloc(sizeof(int)*6);	
	vetAux[0] = 1;
	vetAux[1] = 5;
	vetAux[2] = 10;
	vetAux[3] = 25;
	vetAux[4] = 50;
	vetAux[5] = 0;

	ImprimirCombinacoes(vet,0,cent,vetAux);

	return 0;
}
