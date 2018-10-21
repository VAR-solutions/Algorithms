#ifndef MST_LINKEDLISTELEMENT_HPP_
#define MST_LINKEDLISTELEMENT_HPP_

template <typename T>
class LinkedListElement {
	
private:
	T value;
	LinkedListElement<T> * previous;
	LinkedListElement<T> * next;
	
public:
	LinkedListElement(T const value);
	LinkedListElement(T const value, LinkedListElement * previous, LinkedListElement * next);
	~LinkedListElement() = default;
	
	T getValue();
	LinkedListElement<T> * getPreviousElement();
	LinkedListElement<T> * getNextElement();
	void setPreviousElement(LinkedListElement * element);
	void setNextElement(LinkedListElement * element);
	
};

#endif //MST_LINKEDLISTELEMENT_HPP_
