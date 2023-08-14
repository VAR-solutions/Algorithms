#include <iostream>
#include <climits>
using namespace std;

// Matrix-Chain-Multiplication Function for computing total calculations
int MatrixChainMultiplication(int dims[], int n){

    // creating a matrix[n + 1][n + 1] for storing values of " number of calculations" to be performed
	int c[n + 1][n + 1];

    // initializing diagonal componenets of matrix = 0, because cost is 0 when multiplying one matrix
	for (int i = 1; i <= n; i++)
		c[i][i] = 0;

    // first we will calculate min. operations for all chains of size 2, then for 3 and so on and then finally for the final chain i.e; n
	for (int len = 2; len <= n; len++){

        // i is the first matrix of the chain
		for (int i = 1; i <= (n - len + 1); i++){

            // j is the first matrix of the chain
			int j = i + len - 1;

            // for comparision, we let c[i][j] to be infinity
			c[i][j] = INT_MAX;

            /* now, divide the chain of matrices i....j into two sub-chains i...k and k+1...j and use the already computed results of these sub-chains to 
            compute the result of original chain */
			for (int k = i; k < j; k++){
				int cost = c[i][k] + c[k + 1][j] + dims[i - 1]*dims[k]*dims[j];

                // compairing the cost obtained, if less then it is stored otherwise neglected
				if (cost < c[i][j])
					c[i][j] = cost;
			}
		}
	}
    // returning the minimum number of calculation to be performed
	return c[1][n];
}

// main function 
int main(){

    // considering matrices are not more than 10
    int num =0, dims[10];

    // taking input of number of matrices to be multiplied
    cout << "Enter number of matrices: ";
    cin >> num;
    
    /* suppose there are 3 matrix and dimensions of matrix are of 2x5, 5x6, 6x8 then input should be given as 2, 5, 6, 8
    as d0 x d1, d1 x d2, d2 x d3.... be the matrices so, we take d0 = 2, d1 = 5, d2 = 6, d3 = 8 */
    cout << "Enter dimension of matrices in (d0xd1)*(d1xd2)... " << num + 1 << " inputs" << endl;
    for(int i = 0; i <= num; i++)
        cin >> dims[i];

    // Here cost is referred as minimum number of multiplications required
	cout << "Minimum cost is " << MatrixChainMultiplication(dims, num) << endl;

    // returning 0
	return 0;
}

// Main function ends


/* Output */

/*

Enter number of matrices: 4
Enter dimension of matrices in (d0xd1)*(d1xd2)... 5 inputs
10
20
60
5
30
Minimum cost is 8500

*/