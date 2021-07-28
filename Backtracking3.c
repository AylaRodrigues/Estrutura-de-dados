//Grupo: Ayla Rodrigues, Douglas Mareli, Sofia Kitaeva
//Backtracking exercício 3

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void ImprimirCombinacoes(int *vet, int pos, int cent, int* vetAux){
	int aux=0;
	
	if(pos==cent){
		int qtd1 = 0;
		int qtd5 = 0;
		int qtd10 = 0;
		int qtd25 = 0;
		int qtd50 = 0;
		
		for(int i=0; i<cent;i++){
			aux+=vet[i];
			switch(vet[i]){
					case 1: qtd1++; break;
					case 5: qtd5++; break;
					case 10: qtd10++; break;
					case 25: qtd25++; break;
					case 50: qtd50++; break;
			}	
		}
		if(aux==cent)
		{	
			if(qtd1 != 0){
				printf("%d moedas de 1 centavo; ", qtd1);
			}
			if(qtd5 != 0){
				printf("%d moedas de 5 centavo; ", qtd5);
			}
			if(qtd10 != 0){
				printf("%d moedas de 10 centavo; ", qtd10);
			}
			if(qtd25 != 0){
				printf("%d moedas de 25 centavo; ", qtd50);
			}
			if(qtd50 != 0){
				printf("%d moedas de 50 centavo; ", qtd50);
			}
			printf("\n");

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
