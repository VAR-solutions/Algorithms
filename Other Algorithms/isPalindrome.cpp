#include <iostream>
using namespace std;
int reverse_number(int x) {
	int rev_x = 0;

	while (x != 0) {
		rev_x = rev_x * 10 + x % 10;
		x = x / 10;
	}

	return rev_x;
}

int isPalindrome(int x) {
	return reverse_number(x) == x;
}
int main() {
	// your code goes here
	
	int x;
	cin>>x;
	
	cout<<isPalindrome(x)<<endl;
	return 0;
}
