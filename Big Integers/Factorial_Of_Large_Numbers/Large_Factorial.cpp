#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Maximum length of result in terms of number of digits
const int MAX_DIGIT_LENGTH = 200;

/**
 *
 * Displays the factorial of a given number N
 *
 */
void FactorialOfLargeNumber(const int N) {

    // Creates a vector of `MAX_DIGIT_LENGTH` elements, initialized to zero by default.
    vector<int> product(MAX_DIGIT_LENGTH);

    // Initialize default value as 1
    product[0] = 1;

    // Current size of the number stored in product
    int digitLength = 0;

    // Iterating from 1 till (N + 1)
    for (int i = 1; i < N + 1; ++i) {

        // Holds the carry bit
        int carry = 0;

        // Actual multiplication of numbers, digit by digit
        for (int j = 0; j <= digitLength; ++j) {

            // Multiply next digit
            product[j] *= i;

            // Add carry if any
            product[j] += carry;

            // Update carry bit
            carry = product[j] / 10;

            // If not a single digit, reduce product[j] to single digit
            product[j] %= 10;
        }

        // If carry exists, add it to the end of vector
        while (carry) {

            // Update digit length
            ++digitLength;
            
            // Add carry to the end of vector, digit by digit
            product[digitLength] = carry % 10;

            // Update carry bit
            carry /= 10;
        }   
    }
    
    // Output: Display all digits in reverse
    for (int i = digitLength; i >= 0; --i) {
        cout << product[i];
    }
    cout << endl;
}

// Driver function
int main() {
    int input;
    cin >> input;
    assert(("Input should be at least 0.", input >= 0));
    FactorialOfLargeNumber(input);
    return 0;
}

/*
Sample Input:
--------------------
30
Sample Output:
--------------------
265252859812191058636308480000000
 */
