#include <iostream>

using namespace std;
//taking bitwise and for x and x-1 returns 0 for multiple of 2
bool is_power_of_2(int x) {
	return (x & (x - 1)) == 0;
}
int main() {
	int x;
        cin >> x;
	cout << is_power_of_2(x);
	return 0;
}
