#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int partition(long long int v[], int l, int r){
  long long int p = v[l];
  int i = l;
  int j = r+1;
  long long int swap;

do{
  do{
    i++;
  }while(!(v[i]>=p||i>=r));
  do{
    j--;
  }while(v[j]>p);
  swap = v[i];
  v[i] = v[j];
  v[j] = swap;
}while(i<j);
swap = v[i];
v[i] = v[j];
v[j] = swap;

swap = v[l];
v[l] = v[j];
v[j] = swap;
return j;
}
void quicksort(long long int v[], int l, int r){
  int s;
  if(l<r){
    s = partition(v, l, r);
    quicksort(v, l, s-1);
    quicksort(v, s+1, r);
  }
}
int main(){
    
   long long int vet[10000], n;
   scanf("%lld", &n);
   for(int i=0; i<n; i++){
       scanf("%lld", &vet[i]);
   }
   quicksort(vet, 0, n-1);
   for(int i=0; i<n; i++){
       printf("%lld ", vet[i]);
   }
    return 0;
}
