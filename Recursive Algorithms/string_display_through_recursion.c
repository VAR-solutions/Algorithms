#include<stdio.h>

void dis(char *a){
    if(a[0] == '\0') return;
    printf("%c ",a[0]);
    dis(a+1);
}

void dis_rev(char *a){
    if(a[0] == '\0') return;
    dis_rev(a+1);
    printf("%c ", a[0]);
}

void dis_both_dir(char *a){
    if(a[0] == '\0') return;
    printf("%c ", a[0]);
    dis_both_dir(a+1);
    printf("%c ", a[0]);
}

int main(){
    char x[] = "pqr";
    dis(x);
    printf("\n");
    dis_rev(x);
    printf("\n");
    dis_both_dir(x);
    return 0;
}
