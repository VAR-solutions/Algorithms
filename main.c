#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int i, c, first, middle, last, n, search, array[30];
	printf("ENTER THE NUMBER OF ELEMENTS: ");
	scanf("%d", &n);
	printf("\nENTER %d INTEGERS: \n", n);
	for(i=0; i<n; i++){
		scanf("%d", &array[i]);
	}
	printf("\nENTER THE VALUE TO FIND: ");
	scanf("%d", &search);
	first = 0;
	last = n-1;
	middle = (first+last)/2;
	while(first<=last){
		if(array[middle]<search){
			first=middle+1;
		}
		else if(array[middle==search]){
			printf("%d found at %d... \n", search, middle+1);
			break;		
		}
		else{
			last=middle+1;
		}
		middle = (first+last)/2;
	}
	if(first>last){
		printf("NOT FOUND...");
	}
	getch();
	return 0;
}
