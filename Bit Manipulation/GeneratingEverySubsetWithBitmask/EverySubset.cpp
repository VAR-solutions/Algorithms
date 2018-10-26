#include <bits/stdc++.h>
using namespace std;
vector<int>Vector; int Size;
void Solve(){
    cout << "All possible subsets are:\n";
    int Index = 1;
    for (int i = 0; i < (1 << Size); i++){
        cout << Index << ") ";
        for (int j = 0; j < Size; j++){
            if (i & (1 << j)){
                cout  << Vector[j] << ' ';
            }
        }
        Index++;
        cout << '\n';
    }
}
int main(){
    cout << "Enter size of vector:\n";
    cin >> Size;
    cout << "Enter your vector elements:\n";
    for (int i = 0; i < Size; i++){
        int Element; cin >> Element;
        Vector.push_back(Element);
    }
    Solve();
	return 0;
}
