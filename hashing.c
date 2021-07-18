// Ayla Rodrigues e Sofia Kitaeva
// Trabalho Indexacao - Programacao com arquivos

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct Palavra
{
    char letras[50];
    int qntOcorencias;
    int *linhas;
    struct Palavra *prox,*ant;

}Palavra;

Palavra *CriarLista()
{
    return NULL;
};

Palavra *CriarElemento(char letras[])
{
    struct Palavra *resp = (struct Palavra*) malloc(sizeof(struct Palavra));
    resp->qntOcorencias=1;

    strcpy(resp->linhas,letras);
    resp->prox=NULL;
    resp->ant=NULL;

    return resp;
};

Palavra *Buscar(struct Palavra *Lista)
{
    struct Palavra *aux1 = Lista->prox;
    struct Palavra *aux2 = Lista->prox->prox;

    while(aux1!=Lista)
    {
        while(aux2!=Lista)
        {
            if(strcmp(aux1->linhas, aux2->linhas)==0)
            {
                aux1->qntOcorencias++;
                aux2->prox->ant=aux2->ant;
                aux2->ant->prox=aux2->prox;
                free(aux2);
            }
        }
    }
};

void InserirElemento(struct Palavra *Lista, char letras[])
{
    struct Palavra *novo = CriarElemento(letras);
    struct Palavra *aux = Lista->prox;

    if(aux==Lista){
        novo->prox=Lista;
        novo->ant=Lista->ant;
        Lista->ant->prox=novo;
        Lista->ant = novo;
    }
    else
    {
        while(aux!=Lista){
            if(strcmp(novo->linhas,aux->linhas)<0){
                novo->prox=aux;
                novo->ant=aux->ant;
                aux->ant->prox=novo;
                aux->ant=novo;
                aux=Lista;
            }
            else
            {
                aux=aux->prox;
            }
        }

        if(novo->prox==NULL){
            novo->prox=Lista;
            novo->ant=Lista->ant;
            Lista->ant->prox=novo;
            Lista->ant = novo;
        }
    }
}

void ProcurarPalavra()
{
    FILE *arq;

    Lista = NULL;
    char arv[100];
    char letras[100];

    printf("Qual o nome do arquivo?\n");
    scanf("%s", arv);
    arq=fopen(arv,"rt");

    if (arq!=NULL)
    {
       Lista = CriarLista();

       while(fread(&palavra, sizeof(Palavra), 1, arq)==1)
       {
          if (strcmp(letras, lista.letras)==0)
          {
            lista.qntOcorencias++; 
          }
          else 
          {
            InserirElemento(Lista, letras);
          }
      }

    }
Sleep(1000);
system("cls");
fclose(arquivo);
}

void listar(struct Palavra *Lista)
{
    struct Palavra *aux = Lista;
    if (Lista ==NULL)
    {
       return;
   }
   do
   {
       printf("%s, %d", aux->letras, aux-> qntOcorencias);

   }while(aux!=Lista);
};


int main(){

    setlocale(LC_ALL, "");

    int opcao =0;
    struct Palavra *Lista;
    Lista=CriarLista();

    while (opcao!=3)
    {
       printf("O que deseja fazer?\n1.Criar um indice para um arquivo de texto.\n2.Utilizar um indice existente para realizar busca por palavras.\n3.Encerrar programa.\n");
       scanf("%d", &opcao);
       printf("\n");

       if (opcao==1)
       {
          ProcurarPalavra();
          listar(Lista);

      }

      else if(opcao==2)
      {

      }

      Sleep(5000);
      system("cls");
  }
  printf("O usu?io saiu!\n");

  return 0;
}
