// C++ program to compute evaluation function for 
// Tic Tac Toe Game. 

#include<stdio.h> 
#include<algorithm> 
using namespace std; 

// Returns a value based on who is winning 
// b[3][3] is the Tic-Tac-Toe board 
int evaluate(char b[3][3]) 
{ 
	// Checking for Rows for X or O victory. 
	for (int row = 0; row<3; row++) 
	{ 
		if (b[row][0]==b[row][1] && b[row][1]==b[row][2]) 
		{ 
			if (b[row][0]=='x') 
			return +10; 
			else if (b[row][0]=='o') 
			return -10; 
		} 
	} 

	// Checking for Columns for X or O victory. 
	for (int col = 0; col<3; col++) 
	{ 
		if (b[0][col]==b[1][col] && b[1][col]==b[2][col]) 
		{ 
			if (b[0][col]=='x') 
				return +10; 
			else if (b[0][col]=='o') 
				return -10; 
		} 
	} 

	// Checking for Diagonals for X or O victory. 
	if (b[0][0]==b[1][1] && b[1][1]==b[2][2]) 
	{ 
		if (b[0][0]=='x') 
			return +10; 
		else if (b[0][0]=='o') 
			return -10; 
	} 
	if (b[0][2]==b[1][1] && b[1][1]==b[2][0]) 
	{ 
		if (b[0][2]=='x') 
			return +10; 
		else if (b[0][2]=='o') 
			return -10; 
	} 

	// Else if none of them have won then return 0 
	return 0; 
} 

// Driver code 
int main() 
{ 
	char board[3][3] = 
	{ 
		{ 'x', '_', 'o'}, 
		{ '_', 'x', 'o'}, 
		{ '_', '_', 'x'} 
	}; 

	int value = evaluate(board); 
	printf("The value of this board is %d\n", value); 
	return 0; 
} 

Output :

The value of this board is 10
