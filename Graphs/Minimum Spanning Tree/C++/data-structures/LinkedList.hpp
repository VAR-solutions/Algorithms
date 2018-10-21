#ifndef MST_LINKEDLIST_HPP_
#define MST_LINKEDLIST_HPP_

#include "LinkedListElement.hpp"

template<typename T>
class LinkedList {
	
private:
	LinkedListElement<T> * firstElement;
	LinkedListElement<T> * lastElement;
	int size;
	
public:
	LinkedList();
	~LinkedList();
	
	int getSize();
	T get(int index);
	bool contains(T const value);
	void add(T const value, int index);
	void add(T const value);
	void addStart(T const value);
	void addEnd(T const value);
	void removeAt(int index);
	void removeFirst();
	void removeLast();
	void remove(T const value);
	void print();
	void print(bool biDirectional);
	
protected:
	void remove(LinkedListElement<T>* element);
	
};

#endif //MST_LINKEDLIST_HPP_
