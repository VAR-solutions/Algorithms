#include <bits/stdc++.h>

using namespace std;

//Algoritmo de Busca Binária implementado de forma iterativa

int  binarySearch (int x, int tam, int* v) { 		//Recebe um valor a ser buscado (x)
													//Recebe o tamanho do vetor a ser analisado (tam)
													//Recebe o vetor a ser analisado (v)

   int inicio, meio, fim;
                              						//Inicio é setado para 0
   inicio = 0; fim = tam-1; 						//Fim é setado para (tam -1)
                           
   while (inicio <= fim) { 

      meio = (inicio + fim)/2;                      //O pivo (meio) será o elemento central no sub-vetor em questão
      													
      if (v[meio] == x) return meio; 				//Se o elemento na posição meio for igual ao elemento buscado, retorna-se o valor de "meio"

      if (v[meio] < x) inicio = meio + 1; 			//Se o elemento na posição meio for menor do que o elemento buscado, 
      												//o novo sub-vetor será será a parte direita do vetor anterior => inicio = meio + 1


      else fim = meio - 1;              			//Se o elemento na posição meio for maior do que o elemento buscado, 
      												//o novo sub-vetor será a parte esquerda do vetor anterior => fim = meio - 1 
   }                                         
   return -1; 
      												//Caso nenhuma condição seja satisfeita e o inicio do sub-vetor analisado seja > fim,
      												//o elemento buscado não está no vetor                                       
}

//Algoritmo de Busca Linear

int linearSearch(int x, int tam, int* v){			//Recebe um valor a ser buscado (x)
													//Recebe o tamanho do vetor a ser analisado (tam)
													//Recebe o vetor a ser analisado (v)
	int i;
	for(i=0 ; i<tam ; i++){							//Varre todas as posições do vetor 'v'
		if(v[i] == x){								//de i = 0 até i = tam -1, buscando o 
			return i;								//valor desejado (x)
		}
	}

	return -1;										//Caso não seja encontrado o valor, retorna-se '-1'


}

int main(){


	int* vetor = (int *) malloc(10*sizeof(int));
	int i;

	for(i=0 ; i<10 ; i++){
		vetor[i] = (i-1)*10;
	}

	int ans;

	ans = binarySearch(10, 10, vetor);

	if(ans != -1){
		printf("O valor 10 foi encontrado na posição %d pela Buscar Binária ;)\n", ans);
	}
	else{
		puts("O valor 10 não foi encontrado pela Busca Binária.. :(");
	}

	ans = linearSearch(5, 10, vetor);

	if(ans != -1){
		printf("O valor 5 foi encontrado na posição %d pela Buscar Linear ;)\n", ans);
	}
	else{
		puts("O valor 5 não foi encontrado pela Busca Linear.. :(");
	}

	free(vetor);

}
