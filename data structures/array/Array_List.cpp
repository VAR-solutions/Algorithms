#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions
#include <algorithm>  // c++ algorithms

namespace structures {
/** Class ArrayList */
template<typename T>
class ArrayList {
 public:
    ArrayList();  // constructor
    explicit ArrayList(std::size_t max_size);  // single parameter constructor
    ~ArrayList();
    void clear();  // limpa
    void push_back(const T& data);  // pushes a node at the end of the list
    void push_front(const T& data);  // pushes a node into the beginning of the list
    void insert(const T& data, std::size_t index);  // inserts a node at the given index
    void insert_sorted(const T& data);  // sorts the list and then pushes the node
    T pop(std::size_t index);  // remove and return node from given index
    T pop_back();  // remove and return node from the back of the list
    T pop_front();  // remove and return node from the beginning of the list
    void remove(const T& data);  // removes given data from the list
    bool full();  // true if the current list is full
    bool empty();  // empty if the current list is empty
    bool contains(const T& data);  // returns true if the list contains such data
    std::size_t find(const T& data);  // returns the index of given data
    std::size_t size();  // returns the current size of the list
    std::size_t max_size();  // returns the total size of the list
    T& at(std::size_t index);  // access object at given index
    T& operator[](std::size_t index);  // operator overloading

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    static const auto DEFAULT_MAX = 10u;
};

}  // namespace structures

#endif

template<typename T>
structures::ArrayList<T>::ArrayList() {
    size_= max_size_= 0;
    contents= new T[max_size_];
}

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size) {
    size_= 0;
    max_size_= max_size;
    contents= new T[max_size_];
}

template<typename T>
structures::ArrayList<T>::~ArrayList() {
    delete[] contents;
}

template<typename T>
void structures::ArrayList<T>::clear() {
    size_= 0;
}

template<typename T>
void structures::ArrayList<T>::push_back(const T& data) {
    if (full())
        throw std::out_of_range("LIST IS FULL!");
    contents[size_++]= data;
}

template<typename T>
void structures::ArrayList<T>::push_front(const T& data) {
    if (full()) {
        throw std::out_of_range("LIST IS FULL!");
    } else {
        for (int i= size_; i > 0; i--)
            std::swap(contents[i], contents[i - 1]);
    }
    contents[0]= data;
    size_++;
}

template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index) {
    if (full()) {
        throw std::out_of_range("LIST IS FULL!");
    } else if (index < 0 || index >= size_) {
        throw std::out_of_range("INDEX OUT OF BOUNDS");
    } else {
        for (int i= size_; i > index; i--)
            std::swap(contents[i - 1], contents[i]);
        contents[index]= data;
        size_++;
    }
}

template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
    contents[size_++]= data;
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < size_; j++) {
            if (contents[i] < contents[j])
                std::swap(contents[i], contents[j]);
        }
    }
}

template<typename T>
T structures::ArrayList<T>::pop(std::size_t index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("INDEX OUT OF BOUNDS");
    } else if (empty()) {
        throw std::out_of_range("LIST IS EMPTY!");
    } else {
        auto t= contents[index];
        for (int i= index; i < size_; i++) {
            contents[index]= contents[index + 1];
        }
        size_--;
        return t;
    }
}

template<typename T>
T structures::ArrayList<T>::pop_back() {
    if (empty())
        throw std::out_of_range("LIST IS EMPTY!");
    else
        return contents[--size_];
}

template<typename T>
T structures::ArrayList<T>::pop_front() {
    if (empty())
        throw std::out_of_range("LIST IS EMPTY!");
    auto t= contents[0];
    for (int i= 1; i < size_; i++)
        contents[i - 1]= contents[i];
    size_--;
    return t;
}

template<typename T>
void structures::ArrayList<T>::remove(const T& data) {
    int index= find(data);
    if (index > -1) {
        contents[index]= -1;
    for (int i= index; i < size_; i++)
        contents[i - 1]= 1;
    size_--;
    }
}

template<typename T>
bool structures::ArrayList<T>::full() {
    return size_ == max_size_;
}

template<typename T>
bool structures::ArrayList<T>::empty() {
    return size_ == 0;
}

template<typename T>
bool structures::ArrayList<T>::contains(const T& data) {
    if (empty()) {
        throw std::out_of_range("LIST IS EMPTY!");
    } else {
        for (int i= 0; i < size_; i++) {
            if (contents[i] == data)
                return true;
        }
        return false;
    }
}

template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) {
    if (empty()) {
        throw std::out_of_range("LIST IS EMPTY!");
    } else {
        for (int i= 0; i < size_; i++) {
            if (contents[i] == data)
                return i;
        }
        return size_;
    }
}

template<typename T>
std::size_t structures::ArrayList<T>::size() {
    return size_;
}

template<typename T>
std::size_t structures::ArrayList<T>::max_size() {
    return max_size_;
}

template<typename T>
T& structures::ArrayList<T>::at(std::size_t index) {
    if (index < 0 || index > size_ - 1) {
        throw std::out_of_range("INDEX OUT OF BOUNDS");
    } else {
        return contents[index];
    }
}

template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
    if (empty())
        throw std::out_of_range("LIST IS EMPTY");
    return contents[index];
}
