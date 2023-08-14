#include <stdio.h>
#define max(a, b) (a > b ? a : b)

int kadane(int *v, int n){
    int max_now = v[0], max_global = v[0];
    for(int i = 1; i < n; i++){
        max_now = max(max_now + v[i], v[i]);
        max_global = max(max_now, max_global);
    }
    return max_global;
}

int main(){
    int n;
    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    printf("%d", kadane(v, n));

}
