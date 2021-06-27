#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, j;           // array indices
    int *prime_array;   // array to mark if index is a prime number
    int max = 100;      // max number to be tested

    prime_array = malloc(sizeof(int) * max);

    // explicitly stating that 0 & 1 are not prime numbers
    // implicitly false otherwise
    prime_array[0] = 0;
    prime_array[1] = 0;

    // setting all other numbers from 2 through 100 to true until determined
    for (i = 2; i < max; i++) {
        prime_array[i] = 1;
    }

    // elimination pass for all multiples of prime numbers
    for (i = 2; i < max; i++) {
        if (prime_array[i] == 1) {
            for (j = i; j * i < max; j++) {
                prime_array[j * i] = 0;
            }
        }
    }

    // print all prime numbers from 1 to 100
    printf("\nPrinting all prime numbers from 1 to 100:\n");

    for (i = 2; i < max; i++) {
        if (prime_array[i] == 1){
            printf("%d  ", i);
        }
    }

    printf("\n");

    return 0;
}
