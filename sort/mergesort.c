#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void merge(int a[], int inicio, int meio, int fim){
int *temp, p1, p2, tamanho, i, j, k;
int fim1 = 0, fim2 =0;
tamanho = fim-inicio+1;
p1 = inicio;
p2 = meio+1;
temp = (int*) malloc(tamanho*sizeof(int));
    if(temp!=NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(a[p1]<a[p2]){
                    temp[i]=a[p1++];
                }
                else{
                    temp[i]=a[p2++];
                }
                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1){
                    temp[i]=a[p1++];
                }else{
                    temp[i]=a[p2++];
                }
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++){
            a[k]=temp[j];
        }
    }
}
void mergeSort(int a[], int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio = floor((inicio+fim)/2);
        mergeSort(a, inicio, meio);
        mergeSort(a, meio+1, fim);
        merge(a, inicio, meio, fim);
    }
}
int main(){
    
   int vet[10000], n;
   scanf("%d", &n);
   for(int i=0; i<n; i++){
       scanf("%d", &vet[i]);
   }
   mergeSort(vet, 0, n-1);
   for(int i=0; i<n; i++){
       printf("%d ", vet[i]);
   }
    return 0;
}
