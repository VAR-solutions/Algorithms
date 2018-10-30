#include "LinkedGraphEdge.hpp"
#include "LinkedListElement.hpp"

template <typename T>
LinkedListElement<T>::LinkedListElement(T const value) {
	this->value = value;
	this->previous = nullptr;
	this->next = nullptr;
}

template <typename T>
LinkedListElement<T>::LinkedListElement(T const value, LinkedListElement * previous, LinkedListElement * next) {
	this->value = value;
	this->previous = previous;
	this->next = next;
}

template <typename T>
T LinkedListElement<T>::getValue() {
	return this->value;
}

template <typename T>
LinkedListElement<T> * LinkedListElement<T>::getPreviousElement() {
	return this->previous;
}

template <typename T>
LinkedListElement<T> * LinkedListElement<T>::getNextElement() {
	return this->next;
}

template <typename T>
void LinkedListElement<T>::setPreviousElement(LinkedListElement * element) {
	this->previous = element;
}

template <typename T>
void LinkedListElement<T>::setNextElement(LinkedListElement * element) {
	this->next = element;
}

template class LinkedListElement<LinkedGraphEdge*>;
