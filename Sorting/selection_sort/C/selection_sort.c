/* Selection Sort implementation in C;
 * Author : Felipe Gabriel;
 * Input : Array lenght and elements;
 * Output : Sorted array elements;
*/

#include <stdio.h>

void selection_sort(int size, int *v){
  int i, j, min, aux;
  for (i = 0; i < (size-1); i++){
      min = i;
      for (j = (i+1); j < size; j++) {
          if(v[j] < v[min]){ 
              min = j;
          }
      }
     if (v[i] != v[min]) {
       aux = v[i];
       v[i] = v[min];
       v[min] = aux;
     }
  }
}

int main(){
    int size,j;
    scanf("%d",&size);
    int v[size];

    for(j = 0; j < size; j++){
        scanf("%d",&v[j]);
    }
    selection_sort(size,v);
    for(j = 0; j < size; j++){
        if(j != size-1){
            printf("%d ",v[j]); 
        }
        else{
            printf("%d\n",v[j]);
        }
    }
    return 0;
}
