#include <stdio.h>

void permutation(char inputString[], int depthOfRecursion){
    static int fixedState[15] = {0}; // stores char's "fixed" state; we'll use a fixed size of 15 since the algorithm's run time is self limiting
    static char result[15] = {0};
    if(inputString[depthOfRecursion] == '\0'){
        result[depthOfRecursion] = '\0';
        printf("%s\n",result);
    }else{
        for(int i = 0; inputString[i] != '\0'; i++) {
            if(fixedState[i] == 0){
                result[depthOfRecursion] = inputString[i]; // add to result since it's fixed
                fixedState[i] = 1;
                permutation(inputString, depthOfRecursion + 1); // descend deeper
                fixedState[i] = 0; // "unfix" inputString[i], unwinding and cleaning up
            }
        }
    }
}

int main() {
    permutation("abc", 0);
    return 0;
}