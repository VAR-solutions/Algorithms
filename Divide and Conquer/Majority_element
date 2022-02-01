#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
  // std::cout << left << "," << right << "\n";
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];
  std::sort(a.begin(), a.end());
  int mid = left + (right - left) / 2;
  int majElement = a[mid];
  int count = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] == majElement)
      count++;
  }
  if (count > a.size() / 2)
  {
    return 1;
  }
  //write your code here
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
