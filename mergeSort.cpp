// Algoritmo de ordenação : Merge Sort
#include <bits/stdc++.h>

using namespace std;

// Funçao responsavel por ordenar a parte desejada de um array (ou string)
void merge(int *vetor,int inicio,int fim,int pivo){

	int aux[fim-inicio+1]; // Vetor auxiliar responsavel por armazenar os numeros ordenados
	int i,j,k,n,lim;

	lim = pivo+1; // Indice responsavel por pecorrer a segunda parte do vetor
	n = inicio; // Nao podemos perder o inicio da faixa do vetor a ser ordenada. Portanto, guardamos a variavel responsavel por pecorrer a primeira parte do vetor
	k = 0; // Indice do aux;

	// While responsavel por ordenar os lados enquanto houver elementos em ambos
	while(n<=pivo && lim<=fim){

		// Como desejamos uma lista em ordem crescente, usamos o operador '<='. De forma analoga, se quisermos uma lista em ordem decrescente, utilizariamos o operador '>='
		if(vetor[n] <= vetor[lim]){
			aux[k] = vetor[n]; // O vetor auxiliar recebe os numeros da lista de forma ordenada
			k++; // O indice do meu vetor auxiliar aumenta
			n++; // O indice da primeira parte do vetor a ser ordenado aumenta
		}
		else{
			aux[k] = vetor[lim]; // O vetor auxiliar recebe os numeros da lista de forma ordenada
			k++;  // O indice do meu vetor auxiliar aumenta
			lim++;  // O indice da primeira parte do vetor a ser ordenado aumenta
		}
	}

	// Caso nao exista mais elementos na segunda parte do vetor, repassamos todos os elementos da primeira
	while(n<=pivo){
		aux[k] = vetor[n];
		k++;
		n++;
	}
	// O mesmo ocorre na situacao inversa
	while(lim<=fim){
		aux[k] = vetor[lim];
		k++;
		lim++;
	}

	// Agora, tendo o vetor auxiliar com os elementos ordenados. Precisamos repassar esta ordem para meu vetor original
	for(i=0;i<k;i++){
		vetor[inicio] = aux[i];  // Aqui esta a importancia de guardar o inicio do vetor original em questao. Para podermos repassar os valores com seguranca
		inicio++;
	}
}

// Funcao responsavel por dividir o problema em subproblemas (dividir e conquistar)
void mergeSort(int *vetor,int inicio,int fim){

	int pivo;  // Variavel responsavel por saber a posicao de quebra do vetor
	if(fim>inicio){  // Verificacao de caso base.
		pivo = (inicio+fim)/2;
		mergeSort(vetor,inicio,pivo); // Ordena a primeira parte do vetor
		mergeSort(vetor,pivo+1,fim); // Ordena a segunda parte do vetor
		merge(vetor,inicio,fim,pivo); // Ordena as duas partes do vetor em conjunto
	}
}

int main(){

	int tam,i;
	int *lista;

	printf("Digite a quantidade de numeros da lista:");
	scanf("%d",&tam);

	lista = (int *) malloc(tam*sizeof(int));

	printf("Agora digite %d numeros separados por espacos:",tam);
	for(i=0;i<tam;i++){
		scanf("%d",&lista[i]);
	}

	// Chamada da funcao de ordenamento
	mergeSort(lista,0,tam-1);

	printf("Lista ordenada:\n");
	for(i=0;i<tam;i++){
		printf("%d ",lista[i]);
	}
	printf("\n");

	free(lista);

	return 0;
}
