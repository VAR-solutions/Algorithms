#include <iostream>
#include <vector>
using namespace std;

// Top-down Recursive function to find all possible combinations by
// replacing key's digits with characters of the corresponding list
void findCombinations(auto const &keypad, auto const &input, 
						string res, int index)
{
	// if we have processed every digit of key, print result
	if (index == -1) {
		cout << res << " ";
		return;
	}

	// stores current digit
	int digit = input[index];

	// size of the list corresponding to current digit
	int len = keypad[digit].size();

	// one by one replace the digit with each character in the
	// corresponding list and recur for next digit
	for (int i = 0; i < len; i++) {
		findCombinations(keypad, input, keypad[digit][i] + res, index - 1);
	}
}

// main function
int main()
{
	// mobile keypad
	vector<char> keypad[] =
	{
		{}, {},		// 0 and 1 digit don't have any characters associated
		{ 'A', 'B', 'C' },
		{ 'D', 'E', 'F' },
		{ 'G', 'H', 'I' },
		{ 'J', 'K', 'L' },
		{ 'M', 'N', 'O' },
		{ 'P', 'Q', 'R', 'S'},
		{ 'T', 'U', 'V' },
		{ 'W', 'X', 'Y', 'Z'}
	};

	// input number in the form of an array (number can't start from 0 or 1)
	int input[] = { 2, 3, 4 };
	int n = sizeof(input)/sizeof(input[0]);

	// find all combinations
	findCombinations(keypad, input, string(""), n - 1);

	return 0;
}