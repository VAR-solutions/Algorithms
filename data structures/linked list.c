#include <stdio.h>
#include <stdlib.h>

struct SLLNode{
	int data;
	struct SLLNode *next;
};

typedef struct SLLNode SLL_NODE;

 SLL_NODE* makeNewSLLNode(int data){
	SLL_NODE *newSLLNode = (SLL_NODE *) calloc(1, sizeof(SLL_NODE));
	newSLLNode->data = data;
	return newSLLNode;
}

void SLLInsert(SLL_NODE **head, int data, int position){
	SLL_NODE *current = *head;
	int k = 1;
	
	SLL_NODE *newSLLNode = makeNewSLLNode(data);
	if(position == 1){
		newSLLNode->next = current;
		(*head) = newSLLNode;
		return;
	}
	
	while((k < position - 1) && (current->next !=NULL)){
		current = current->next;
		k++;
	}
	
	newSLLNode->next = current->next;
	current->next = newSLLNode;
	
}

void SLLDelete(SLL_NODE **head, int position){
	SLL_NODE *temp = *head;
	int k = 1;
	
	SLL_NODE *temp2;
	
	if(position == 1){
		(*head) = (*head)->next;
		free(temp);
		return;
	}
	
	while((k < position) && (temp != NULL)){
		temp2 = temp;
		temp = temp->next;
		k++;
	}
	
	temp2->next = temp->next;
	free(temp);
	
}

void deleteSingleLinkedList(SLL_NODE **head){
	SLL_NODE *current = *head;
	while(current != NULL){
		(*head) = (*head)->next;
		free(current);
		current = *head;
	}
}

void displaySLL(SLL_NODE *head){
	SLL_NODE* curr = head;
	printf("\nPrinting the list : ");
	while(curr != NULL){
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
}

void singlyLinkedList() {
	SLL_NODE *head = NULL;
	SLLInsert(&head, 7, 1);
	SLLInsert(&head, 6, 1); 
	SLLInsert(&head, 5, 1);
	SLLInsert(&head, 4, 1);
	SLLInsert(&head, 3, 1);
	SLLInsert(&head, 1, 1);
	SLLInsert(&head, 2, 2);
	displaySLL(head);
	
	SLLDelete(&head, 4);
	displaySLL(head);
	return 0;
}