/*
* Title: Big Sorting
* Description: Given a list of numbers, which would even include numbers of some 20 digit numbers or so. And your task is to sort them.
* Author: Vanamala Srikanth
* GitHub: https://github.com/srikanth7785
*/

#include<iostream>
#include<vector>
#include<algorithm> //for sort()
using namespace std;

bool customSorting(string a, string b){
    //below, first two conditions, will check if one of the strings are having a `-ve`..
    // if only first string is `-ve`
    if(a[0] == '-' and b[0] != '-')
        return true;
    // if only second string is `-ve`
    if(a[0] != '-' and b[0] == '-')
        return false;
    //if both are negative
    if(a[0] == '-' and b[0] == '-'){
        if(a.length() == b.length())
            return a > b;
        return a.length() > b.length();
    }
    // below conditions will check only when both are `+ve`
    if(a.length() == b.length()) // if both the strings are of same length
        return a < b; // check if first string is less than the second string
    return a.length() < b.length(); // if both strings are of different length, then the one with smallest length will be the smallest number
}

int main(){
    int n;
    cin >> n;
    vector<string> numbers;//an array can also be used instead
    
    for(int i = 0;i < n; i++)
    {string temp; cin >> temp; numbers.push_back(temp);}
    
    sort(numbers.begin(),numbers.end(),customSorting); // this is an inbuilt method available in `algorithm`. it will call `customSorting()` for each comparision
    
    for(string num : numbers) //finally, print the output, which is sorted.
    cout << num << endl;
}
/*
-------------------------
Sample Input:                                                                                   Sample Output:
26
-29587466846                                                                                    -999999999999999999999999999
1                                                                                               -8461844655468628
5                                                                                               -8461844655468627
-3                                                                                              -8461844655468625
999999999999999999999999999                                                                     -8461844655468622
-999999999999999999999999999                                                                    -854551541265
56584811425369978558466998629                                                                   -29587466846
34183682863148623287364532568384314852                                                          -2184634134
55885698726558891335532227899                                                                   -245
55885698726558891335532227897                                                                   -3
54181768138176                                                                                  1
55885698726558891335532227895                                                                   5
8797879883232132154654                                                                          3242
55885698726558891335532227893                                                                   987456215
987563214569875                                                                                 6548965813654
55885698726558891335532227890                                                                   54181768138176
-854551541265                                                                                   987563214569875
-2184634134                                                                                     8797879883232132154654
-245                                                                                            999999999999999999999999999
3242                                                                                            55885698726558891335532227890
-8461844655468628                                                                               55885698726558891335532227893
-8461844655468627                                                                               55885698726558891335532227895
6548965813654                                                                                   55885698726558891335532227897
-8461844655468622                                                                               55885698726558891335532227899
987456215                                                                                       56584811425369978558466998629
-8461844655468625                                                                               34183682863148623287364532568384314852

*/
