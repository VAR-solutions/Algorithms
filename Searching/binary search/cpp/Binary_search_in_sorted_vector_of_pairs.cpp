/*

Binary search in sorted vector of pairs
How to apply STL binary_search to vector of pairs(key, value), given that vector is sorted by its first value(key)

struct compare in the code contains two function which compares the key(searching element) with the first element in the vector

*/

/* C++ code to demonstrate how Binary Search 
   can be applied on a vector of pairs */
#include <algorithm> // binary search 
#include <iostream> 
#include <vector> 
using namespace std; 
  
struct compare { 
    bool operator()(const pair<int, int>& value,  
                                const int& key) 
    { 
        return (value.first < key); 
    } 
    bool operator()(const int& key,  
                    const pair<int, int>& value) 
    { 
        return (key < value.first); 
    } 
}; 
  
int main() 
{ 
    // intializing the vector of pairs 
    vector<pair<int, int> > vect; 
  
    // insertion of pairs (key, value) in vector vect 
    vect.push_back(make_pair(1, 20)); 
    vect.push_back(make_pair(3, 42)); 
    vect.push_back(make_pair(4, 36)); 
    vect.push_back(make_pair(2, 80)); 
    vect.push_back(make_pair(7, 50)); 
    vect.push_back(make_pair(9, 20)); 
    vect.push_back(make_pair(3, 29)); 
  
    // sorting the vector according to key 
    sort(vect.begin(), vect.end()); 
  
    // printing the sorted vector 
    cout << "KEY" << '\t' << "ELEMENT" << endl; 
    for (pair<int, int>& x : vect) 
        cout << x.first << '\t' << x.second << endl; 
  
    // searching for the key element 3 
    cout << "search for key 3 in vector" << endl; 
    if (binary_search(vect.begin(), vect.end(), 
                                  3, compare())) 
        cout << "Element found"; 
    else
        cout << "Element not found"; 
  
    return 0; 
}

/*
Output:
KEY    ELEMENT
1    20
2    80
3    29
3    42
4    36
7    50
9    20
search for key 3 in vector
Element found
The above binary_search operation has time complexity O(log n)
*/