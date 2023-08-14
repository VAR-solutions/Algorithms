#include<stdio.h>
#include<math.h>

//hashing using prime no.
#define Prime 5039

int hashTable[100] = {0};
int hashTableSize = 23;

int hashfunct(int x){
    int index = Prime%x;
    return index;
}

void insert(int x){
    int index  = hashfunct(x);
    while(hashTable[index] != 0){
        index = (index + 1)%hashTableSize;
    }
    hashTable[index] = x;
    printf("\n%d is inserted at index %d",x,index);
}

void search(int x){
    int index  = hashfunct(x);
    while(hashTable[index] != x && hashTable[index] != 0){
        index = (index + 1)%hashTableSize;
    }
    if(x == hashTable[index]){
        printf("\n%d is at index %d in the hash table",x,index);
    }
    else{
       printf("\n%d is not in hash table",x);
    }
}

int main(){

   insert(9);
   insert(67);
   insert(32);
   insert(5);
   insert(56);
   insert(101);
   insert(27);
   insert(96);
   insert(11);
   insert(20);
   insert(99);

   

   search(9);
   search(67);
   search(101);
   search(32);
   search(5);
   search(96);
   search(56);
   search(20);
   search(11);
   search(27);
   search(99);
   search(54);
   search(7);
   search(100);
    return 0;
}

