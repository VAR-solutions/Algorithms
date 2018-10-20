#ifndef MST_ARRAYLIST_HPP_
#define MST_ARRAYLIST_HPP_

template<typename T>
class ArrayList {
	
private:
	T *array;
	int size;
	
public:
	ArrayList();
	~ArrayList();
	
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
	
};

#endif //MST_ARRAYLIST_H
