/* Ugly numbers are numbers whose only
 prime factors are 2, 3 or 5. The sequence 
 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows 
 the first 11 ugly numbers. By convention,
 1 is included. 
 */

/*program to find n'th Ugly number */ 
# include<bits/stdc++.h> 
using namespace std; 
  
/* Function to get the nth ugly number*/
unsigned getNthUglyNo(unsigned n) 
{ 
    unsigned ugly[n]; 
    unsigned i2 = 0, i3 = 0, i5 = 0; 
    unsigned next_multiple_of_2 = 2; 
    unsigned next_multiple_of_3 = 3; 
    unsigned next_multiple_of_5 = 5; 
    unsigned next_ugly_no = 1; 
  
    ugly[0] = 1; 
    for (int i=1; i<n; i++) 
    { 
       next_ugly_no = min(next_multiple_of_2, 
                           min(next_multiple_of_3, 
                               next_multiple_of_5)); 
       ugly[i] = next_ugly_no; 
       if (next_ugly_no == next_multiple_of_2) 
       { 
           i2 = i2+1; 
           next_multiple_of_2 = ugly[i2]*2; 
       } 
       if (next_ugly_no == next_multiple_of_3) 
       { 
           i3 = i3+1; 
           next_multiple_of_3 = ugly[i3]*3; 
       } 
       if (next_ugly_no == next_multiple_of_5) 
       { 
           i5 = i5+1; 
           next_multiple_of_5 = ugly[i5]*5; 
       } 
    } 
    return next_ugly_no; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int n;
    cin >> n; 
    cout << getNthUglyNo(n); 
    return 0; 
} 
