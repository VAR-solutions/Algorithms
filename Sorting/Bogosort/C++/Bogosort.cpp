 #include <algorithm>
 #include <vector>
 
 template<class T>
 void bogosort(std::vector<T>& array)
 {
     while (! is_sorted(array))
         std::random_shuffle(array.begin(), array.end());
 }
 
 template<class T>
 bool is_sorted(const std::vector<T>& array)
 {
     for (typename std::vector<T>::size_type i = 1; i < array.size(); ++i)
         if (array[i] < array[i-1]) return false;
     return true;
 }