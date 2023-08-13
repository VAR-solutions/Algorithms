
#include <stdio.h>
#include <stdlib.h>

typedef struct sNODE{
  int dado;
  struct sNODE *prox;
}lista;

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);
void inserir_ini(int dado);
void remover(int dado);
lista *buscar(int dado);

int obter(lista *node);
int tamanho();
void imprimir();
void apagar();

int main(){
    for (int i = 15; i > 0;i--){
        inserir_ini(i);
    }

    imprimir();
    inserir_ini(90);
    imprimir();
    inserir_ini(80);
    imprimir();
    system("pause");
  return 0;
}

void inserir(int dado){
  lista *novo = (lista*) malloc(sizeof(lista));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
	ini = fim = novo;
  else{
	fim->prox = novo;
	fim = novo;
  }
}

void inserir_ini(int dado){
    lista *novo = (lista*) malloc(sizeof(lista));
    novo->dado = dado;

    if (!ini){
        novo->prox = NULL;
        ini = fim = novo;
    }else{
        novo->prox = ini;
        ini = novo;
    }
}

lista *buscar(int dado){
  lista *aux = ini;

  while (aux){
	if (dado == aux->dado)
  	    return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(int dado){
  lista *aux = ini, *ant = NULL;

  while (aux){
	if (dado == aux->dado){
  	    if (aux == ini)
    	        ini = ini->prox;
  	    else if(aux == fim){
    	        ant->prox = NULL;
    	        fim = ant;
  	    } else
    	        ant->prox = aux->prox;
 	 
  	    free(aux);
  	    return;
	}
    
	ant = aux;
	aux = aux->prox;
  }
}

void apagar(){
  lista *aux = ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}

int obter(lista *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
}

int tamanho(){
  lista *aux = ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(){
  lista *aux = ini;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}
