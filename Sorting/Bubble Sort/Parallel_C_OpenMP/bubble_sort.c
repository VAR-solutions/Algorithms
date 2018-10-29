#include <omp.h>
#include <stdio.h>
#define size 100000

int main(){
    omp_set_num_threads(2);
    double start = omp_get_wtime();
    int a[size];

    for(int i = 0; i < size; i++){
        a[i]  = size - i;
    }

    for(int i = 0; i < size; i++){
        if(i % 2 == 0){
            #pragma omp parallel for
            for(int j = 0; j < size; j+=2){
                if(a[j] > a[j+1]){
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        else{
            #pragma omp parallel for
            for(int j = 1; j < size; j+=2){
                if(a[j] > a[j+1]){
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }

    printf("Time required = %f\n", omp_get_wtime() -start);

}
