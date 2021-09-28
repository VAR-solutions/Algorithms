//Kumar Ankit
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
    int data[MAX];
    int top;
}STACK;

//Note: When *S is used in a function, (*S).top is same as S->top

int push(STACK *S, int v){
    if(S->top == MAX-1){
        printf("Overflow\n");
        return 1;
    }
    S->top++;
    S->data[S->top] = v;
    return 0;
}

int pop(STACK *S, int *v){
    if(S->top == -1){
        printf("Underflow\n");
        return 1;
    }
    *v = S->data[S->top];
    S->top--;
    return 0;
}

void display(STACK *S){//using recursion
    if(S->top == -1) return;
    int u;
    pop(S, &u);
    printf("%d ", u);
    display(S);
    push(S, u);
}

int main(){
    int m;
    STACK S1;
    S1.top = -1;
    int k = push(&S1, 15);
    display(&S1);
    int q = pop(&S1, &m);
    return 0;
}
