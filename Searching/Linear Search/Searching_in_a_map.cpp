// author: Pratish Katiyar (https://github.com/pratishk28)
/*
Searching in a map using std::map functions in C++

Usually, main purpose of using map stl container is for efficient search operations and sorted order retrieval. As map stores key-value pair, all the search operations take “O(log(n))” time (n is size of map). Different types of search functions exists in C++ language, each having different functions. In the context of competitive programming, this turns out to be useful when search operations are required and performs better than other containers. Some search operations are discussed below.

std::map::find()

find() is used to search for the key-value pair and accepts the “key” in its argument to find it. This function returns the pointer to the element if the element is found, else it returns the pointer pointing to the last position of map i.e “map.end()” .
*/



// C++ code to demonstrate the working of find() 
  
#include<iostream> 
#include<map> // for map operations 
using namespace std; 
  
int main() 
{ 
    // declaring map 
    // of char and int 
    map< char, int > mp; 
      
    // declaring iterators 
    map<char, int>::iterator it ; 
    map<char, int>::iterator it1 ; 
      
    // inserting values  
    mp['a']=5; 
    mp['b']=10; 
    mp['c']=15; 
    mp['d']=20; 
    mp['e']=30; 
      
    // using find() to search for 'b'  
    // key found 
    // "it" has address of key value pair. 
    it = mp.find('b'); 
      
    if(it == mp.end()) 
        cout << "Key-value pair not present in map" ; 
    else
        cout << "Key-value pair present : " 
          << it->first << "->" << it->second ; 
      
    cout << endl ; 
      
    // using find() to search for 'm'  
    // key not found 
    // "it1" has address of end of map. 
    it1 = mp.find('m'); 
      
    if(it1 == mp.end()) 
        cout << "Key-value pair not present in map" ; 
    else
        cout << "Key-value pair present : " 
            << it1->first << "->" << it1->second ; 
      
} 

/*
Output:

Key-value pair present : b->10
Key-value pair not present in map
*/

/*
std::map::lower_bound()

lower_bound() is also used for the search operation but sometimes also returns a valid key-value pair even if it is not present in map . lower_bound() returns address of key value pair, if one is present in map, else returns the address to the smallest key greater than key mentioned in its arguments. If all keys are smaller than the key to be found, it points to “map.end()” .
// C++ code to demonstrate the working of lower_bound() 
  
#include<iostream> 
#include<map> // for map operations 
using namespace std; 
  
int main() 
{ 
    // declaring map 
    // of char and int 
    map< char, int > mp; 
      
    // declaring iterators 
    map<char, int>::iterator it ; 
    map<char, int>::iterator it1 ; 
    map<char, int>::iterator it2 ; 
      
      
    // inserting values  
    mp['a']=5; 
    mp['b']=10; 
    mp['c']=15; 
    mp['h']=20; 
    mp['k']=30; 
      
    // using lower_bound() to search for 'b'  
    // key found 
    // "it" has address of key value pair. 
    it = mp.lower_bound('b'); 
      
    if(it == mp.end()) 
        cout << "Key-value pair not present in map" ; 
    else
        cout << "Key-value pair returned : " 
            << it->first << "->" << it->second ; 
      
    cout << endl ; 
      
    // using lower_bound() to search for 'd'  
    // key not found 
    // "it1" has address of next greater key. 
    // key - 'h' 
    it1 = mp.lower_bound('d'); 
      
    if(it1 == mp.end()) 
        cout << "Key-value pair not present in map" ; 
    else
        cout << "Key-value pair returned : " 
            << it1->first << "->" << it1->second ; 
      
    cout << endl; 
      
    // using lower_bound() to search for 'p'  
    // key not found 
    // "it2" has address of next greater key. 
    // all keys are smaller, hence returns mp.end() 
    it2 = mp.lower_bound('p'); 
      
    if(it2 == mp.end()) 
        cout << "Key-value pair not present in map" ; 
    else
        cout << "Key-value pair returned : "
            << it2->first << "->" << it2->second ; 
      
} 


Output:

Key-value pair returned : b->10
Key-value pair returned : h->20
Key-value pair not present in map

std::map::upper_bound()

upper_bound() is also used for the search operation and never returns the key-value pair searched for . upper_bound() returns address of key value pair coming exactly next to the searched key, if one is present in map. If all keys are smaller than the key to be found, it points to “map.end()”
// C++ code to demonstrate the working of upper_bound() 
  
#include<iostream> 
#include<map> // for map operations 
using namespace std; 
  
int main() 
{ 
    // declaring map 
    // of char and int 
    map< char, int > mp; 
      
    // declaring iterators 
    map<char, int>::iterator it ; 
    map<char, int>::iterator it1 ; 
    map<char, int>::iterator it2 ; 
      
      
    // inserting values  
    mp['a']=5; 
    mp['b']=10; 
    mp['c']=15; 
    mp['h']=20; 
    mp['k']=30; 
      
    // using upper_bound() to search for 'b'  
    // key found 
    // "it" has address of key value pair next to 'b' i.e 'c'. 
    it = mp.upper_bound('b'); 
      
    if(it == mp.end()) 
        cout << "Key-value pair not present in map" ; 
    else
        cout << "Key-value pair returned : " 
            << it->first << "->" << it->second ; 
      
    cout << endl ; 
      
    // using upper_bound() to search for 'd'  
    // key not found 
    // "it1" has address of next greater key. 
    // key - 'h' 
    it1 = mp.upper_bound('d'); 
      
    if(it1 == mp.end()) 
        cout << "Key-value pair not present in map" ; 
    else
        cout << "Key-value pair returned : " 
        << it1->first << "->" << it1->second ; 
      
    cout << endl; 
      
    // using upper_bound() to search for 'p'  
    // key not found 
    // "it2" has address of next greater key. 
    // all keys are smaller, hence returns mp.end() 
    it2 = mp.upper_bound('p'); 
      
    if(it2 == mp.end()) 
        cout << "Key-value pair not present in map" ; 
    else
        cout << "Key-value pair returned : " 
            << it2->first << "->" << it2->second ; 
      
} 


Output:

Key-value pair returned : c->15
Key-value pair returned : h->20
Key-value pair not present in map

std::map::equal-range

Yet another function to search in map, it returns the range containing the searched key. As map contains unique elements, range returned contains at most 1 element. This function returns a iterator of pair, whose 1st element points to lower_bound() of the searched key pair, and second element points to the upper_bound() of the searched key. If key is not present, both first element and second element point to the next greater element.
// C++ code to demonstrate the working of equal_range() 
  
#include<iostream> 
#include<map> // for map operations 
using namespace std; 
  
int main() 
{ 
    // declaring map 
    // of char and int 
    map< char, int > mp; 
      
    // declaring iterators 
    pair<map<char, int>::iterator, map<char, int>::iterator> it; 
      
      
    // inserting values  
    mp['a']=5; 
    mp['b']=10; 
    mp['c']=15; 
    mp['h']=20; 
    mp['k']=30; 
      
    // using equal_range() to search for 'b'  
    // key found 
    // 1st element of "it" has the address to lower_bound (b) 
    // 2nd element of "it" has the address to upper_bound (c)  
    it = mp.equal_range('b'); 
      
    cout << "The lower_bound of key is : " 
        << it.first -> first << "->" << it.first -> second; 
    cout << endl; 
      
    cout << "The upper_bound of key is : " 
        << it.second -> first << "->" << it.second -> second; 
      
    cout << endl << endl ; 
      
    // using equal_range() to search for 'd'  
    // key not found 
    // Both elements of it point to next greater key 
    // key - 'h' 
    it = mp.equal_range('d'); 
      
    cout << "The lower_bound of key is : " 
        << it.first -> first << "->" << it.first -> second; 
    cout << endl; 
      
    cout << "The upper_bound of key is : " 
        << it.second -> first << "->" << it.second -> second; 
      
      
} 


Output:

The lower_bound of key is : b->10
The upper_bound of key is : c->15

The lower_bound of key is : h->20
The upper_bound of key is : h->20
*/


