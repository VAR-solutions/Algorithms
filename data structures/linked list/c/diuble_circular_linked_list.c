//Kumar Ankit
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void create(struct node **h, int n){
    struct node *curr, *ptr;
    for(int i=0; i<n; i++){
        curr = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &curr->data);
        curr->next = curr->prev = NULL;
        if(*h == NULL){
            *h = ptr = curr;
            curr->next = curr->prev = curr;
        }else{
            curr->prev = ptr;
            curr->next = ptr->next;
            ptr->next = curr;
            (*h)->prev = curr;
            ptr = ptr->next;
        }
    }
}

void display(struct node *h){
    struct node *ptr;
    for(ptr = h; ptr->next!=h; ptr=ptr->next){
        printf("%d ", ptr->data);
    }
    printf("%d\n", ptr->data);
}

void insert(struct node **h, int v, int p){
    struct node *curr, *ptr;
    curr = (struct node *)malloc(sizeof(struct node));
    curr->data = v;
    curr->next = curr->prev = NULL;
    if(*h == NULL){
        *h = curr;
        curr->next = curr->prev = curr;
    }else if(p==0){
        curr->next = *h;
        curr->prev = (*h)->prev;
        (*h)->prev->next = curr;
        (*h) = curr;
    }else{
        ptr = *h;
        int i = 1;
        while(i<p){ //((p-1)%4)+1 Try optimizing.
            ptr = ptr->next;
            i++;
        }
        curr->prev = ptr;
        curr->next = ptr->next;
        ptr->next->prev = curr;
        ptr->next = curr;
    }
}

void delete(struct node **h, int p){
    struct node *ptr;
    if(*h == NULL){
        printf("Empty Linked List\n");
    }else{
        ptr = *h;
        int i = 0; //for zero based indexing positions
        while(i<p && ptr->next!=(*h)){
            ptr = ptr->next;
            i++;
        }
        if(ptr->next == (*h) && i<p){
            printf("Node Not Found\n");
        }else if(ptr == (*h) && ptr->next == ptr){
            *h = NULL;
            free(ptr);
        }else if(ptr == *h){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            *h = (*h)->next;
            free(ptr);
        }else{
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
    }
}

int main(){
    struct node *head = NULL;
    printf("Enter Number of nodes: ");
    int n;
    scanf("%d", &n);
    create(&head, n);
    display(head);
    printf("Enter value to be inserted and position: ");
    int v, pos;
    scanf("%d %d", &v, &pos);
    insert(&head, v, pos);
    display(head);
    printf("Enter position to be deleted: ");
    scanf("%d", &pos);
    delete(&head, pos);
    display(head);
    return 0;
}
