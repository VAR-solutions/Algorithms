#include <stdio.h>
#include <malloc.h>

struct node{
    int valor;
    struct node * proximo;
};

typedef struct node no;

//Instanciando um no
no * criarno(int valor){
    no * inicio = (no *) malloc(sizeof(no));
    inicio->valor = valor;
    inicio->proximo = NULL;
	return inicio;
}

typedef struct{
	no* inicio;
	no* fim;
	int qtde;
}CircleLinkedList;

//instanciando uma lista
CircleLinkedList * criar(){
    CircleLinkedList * l = (CircleLinkedList*) malloc(sizeof(CircleLinkedList));
	l-> inicio = NULL;
	l-> fim = NULL;
	l->qtde = 0;
	return l;
}

//Inserir no fim
//Somente se a lista não for ordenada
int inserir_no_fim(CircleLinkedList* lista, int valor){
	no * novo = criarno(valor);
	
	if(lista->qtde == 0){
		lista->inicio = novo;
		lista->fim = novo;
		lista->qtde++;
		return 1;
	}
	
	lista->fim->proximo = novo;
	lista->fim = lista->fim->proximo;
	lista->fim->proximo = lista->inicio; 
	lista->qtde++;
	
	return 1;
}

//Inserir no inicio
//Somente se a lista não for ordenada
int inserir_no_inicio(CircleLinkedList* lista, int valor){
	 no * novo = criarno(valor);
	
	if(lista->qtde == 0){
		lista->inicio = novo;
		lista->fim = novo;
		lista->qtde++;
		return 1;
	}
	
	novo->proximo = lista->inicio;
	lista->inicio = novo;
	lista->qtde++;
	
	return 1;
}

int removerValor(CircleLinkedList * lista, int valor){
	if(lista->qtde == 0){
		return 0;
	}
	no* anterior = NULL;
	no* atual = lista->inicio;
	while((atual->valor != valor) && (atual->proximo != lista->inicio)){
		anterior = atual;
		atual = atual->proximo;
    }
	if(atual-> valor == valor){
		anterior->proximo = atual->proximo;
		free(atual);
		lista->qtde--;
		return 1;
	}else{
		return 0;
	}
}

int busca(CircleLinkedList * lista, int valor){
	if(lista->qtde == 0){
			return -1;
		}
	no* atual = lista->inicio;
	int pos = 0;
	while((atual-> valor != valor) && (atual->proximo!=lista->inicio) ){
		atual = atual->proximo;
		pos++;
    }
	
	if(atual-> valor == valor){
		return pos;
	}else{
		return -1;
	}
}

int tamanho(CircleLinkedList * lista){
	return lista->qtde;
}

int destruir(CircleLinkedList * lista){
	if(lista->qtde == 0){
			free(lista);
			return 0;
		}
	no* atual = lista->inicio;
	no* proximo = atual->proximo; 
	while(atual->proximo!=lista->inicio){
		proximo = atual->proximo;
		free(atual);
		atual = proximo;
    }
	free(atual);
	
	return 1;
}

no* pegar_fim(CircleLinkedList* lista){
	return lista->fim;
}

no* pegar_inicio(CircleLinkedList* lista){
	return lista->inicio;
}

void removefim(CircleLinkedList* lista){
	no* pont = lista->inicio;
	no* anterior = NULL;
	
	while(pont->proximo != lista->inicio){
		anterior = pont;
		pont = pont->proximo;
	}
	
	if(lista->qtde == 1){
		free(pont);
		lista->qtde--;
		return;
	}
	
	free(pont);
	anterior->proximo = lista->inicio;
	lista->fim = anterior;
	lista->qtde--;
}

void toString(CircleLinkedList* lista){
	if(tamanho(lista) == 0){
			printf("\nlista vazia");
		return;
	}
	
	no* atual = lista->inicio;
	printf("\n");
	while(atual->proximo != lista->inicio){
		printf("[ %d ]->",atual->valor);
		atual = atual->proximo;
    }
    
	printf("[ %d ]",atual->valor);
}
