#include <stdio.h>
#include <iostream>

using namespace std;

/**
 *  Algoritmo recursivo de Flavious Josephus
 *  @author: Mateus Tranquilino
 * */
 
/**
 * Calcula o sobrevivente no problema de Flavious Josephus
 * em um circulo de N pessoas e de salto K.
 * */
int josephus(int n, int k){
    if(n==1) return 1;
    return ( ( ( josephus(n-1, k) + k-1) % n ) + 1);
}

int main(){
    unsigned int n, k;
    int x;
    printf("Quantos casos de Testes? ");
    scanf("%d", &x);
    
    for (int i=0; i < x; i++){
    printf("O número de pessoas no circulo ");
    scanf("%d", &n);
    printf("O tamanho do salto ");
    scanf("%d", &k);
    printf("No caso %d a pessoa na posição %d termina viva\n", i+1, josephus(n,k));
	cout << endl;
	}
}
