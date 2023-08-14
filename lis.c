#include <stdio.h>
#define max(a, b) ((a > b) ? a : b)

int main(){
    int n, ans = 0;
    scanf("%d", &n);

    int v[n], length[n];

    for(int i = 0; i < n; i++){
        length[i] = 0;
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < n; i++) {
        length[i] = 1;
        for(int j = 0; j < i; j++) {
           if (v[j] < v[i]) {
               length[i] = max(length[i],length[j]+1);
           }
        } 
    }
    
    for(int i = 0; i < n; i++){
        if(length[i] > ans)
            ans = length[i];
    }

    printf("%d", ans);

    return 0;
}
