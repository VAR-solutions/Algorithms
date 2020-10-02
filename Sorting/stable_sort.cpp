#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
struct Employee
{
    int age;
    std::string name;  // Not included in comparison
};
 
bool operator<(const Employee & lhs, const Employee & rhs)
{
    return lhs.age < rhs.age;
}
 
int main()
{
    std::vector<Employee> v =
    { 
        {23, "Mary"},
        {43, "John"},
        {29, "Sue"},
    };  
 
    std::stable_sort(v.begin(), v.end());
 
    for (const Employee & e : v)
        std::cout << e.age << ", " << e.name << '\n';
}
