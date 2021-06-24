//Ayla Rodrigues, Douglas Mareli, Sofia Kitaeva
//Questao 1- Listas recursivas

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct lista
{
	int info;
	struct lista *prox;

}lista;

lista *InserirFinal(lista *l, int x)
{
	if (l==NULL)
	{
		lista *no=(lista*)malloc(sizeof(lista));
		no->info=x;
		no->prox=NULL;
		printf("\nElemento %d inserido.\n\n", x);
		return no;
	}
	else
		l->prox=InserirFinal(l->prox,x);
	return l;
}

void SomarLista(lista *l, int ct){
	if(l == NULL){
		printf("\nAinda não há elementos na lista.\n\n");
	}else{
		ct = ct+ l->info;
		if(l->prox != NULL) SomarLista(l->prox, ct);
		else{
			printf("\nA Soma dos elementos da lista é: %d\n\n", ct);
			return;
		}
	}			
}

void listaRepetido(lista *l, int ct, int elemento){
	if(l == NULL){
		printf("\nAinda não há elementos na lista.\n\n");
	}else{
		if(l->info == elemento){
			ct++;
		}
		if(l->prox != NULL) listaRepetido(l->prox,ct,elemento);
		else{
			printf("\nO elemento %d aparece %d vez(es) na lista.\n\n", elemento, ct);
			return;
		}
	}
}
		
void removerElemento(struct lista **l, int elemento){
 	struct lista* ant = *l;
    struct lista* aux = ant->prox;
    
    if(ant->info == elemento){
        *l=aux;
        ant->prox = aux->prox;
        free(ant);
        return;
    }
    
    if(aux->info != elemento){
    	removerElemento(&ant->prox, elemento);
    	return;    
    }else if(ant->info == elemento){
        *l=aux;
        ant->prox = aux->prox;
        free(ant);
        return;
    }
    
    ant->prox = aux->prox;
    free(aux);
    return;
    }
    
void imprimirLista(lista *l){
	if(l == NULL) printf("\nAinda não há elementos na lista.\n\n");
	else{
		printf(" (%d) -",l->info);
		if(l->prox != NULL) imprimirLista(l->prox);
		else return;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	
	int opcao = 0;
	int elemento,somaLista, repetido;
	struct lista *l = NULL; //cria lista
		
	while(opcao!=6)
	{
		printf("O que deseja fazer?\n 1.Inserir elemento\n 2.Somar elementos da lista\n 3.Contar elemento repetido\n 4.Remover elemento\n 5.Imprimir elementos\n 6.Sair\n");
		scanf("%d", &opcao);
		
		if (opcao==1)//Inserir elemento
		{
			printf("Qual elemento deseja inserir?\n");
			scanf("%d", &elemento);
			l= InserirFinal(l, elemento);	
		}
		else if(opcao==2)//somar elementos da lista
		{
			SomarLista(l, 0);
				
		}
		else if(opcao==3)//contar elementos repetidos
		{
			if(l == NULL) printf("\nAinda não há elementos na lista.\n\n");
			else{
				printf("Qual elemento você deseja verificar? \n");
				scanf("%d",&elemento);
				listaRepetido(l,0,elemento);
			}
		}
		else if (opcao==4)//remover elemento da lista (admitir que o elemento que será removido é válido)
		{
				printf("\nQual elemento você deseja remover?\n");
				scanf("%d",&elemento);
				printf("\n");
				removerElemento(&l, elemento);
		}
		else if(opcao==5)//imprimir elementos
		{
				printf("\nLista:");
				imprimirLista(l);
				printf("\n\n");
		}
	}
		printf("\nO usuário saiu!\n");
	return 0;
}
