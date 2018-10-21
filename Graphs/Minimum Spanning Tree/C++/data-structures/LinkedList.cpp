#include <iostream>
#include <stdexcept>
#include <string>
#include "LinkedGraphEdge.hpp"
#include "LinkedListElement.hpp"
#include "LinkedList.hpp"

template<typename T>
LinkedList<T>::LinkedList() {
	this->size = 0u;
	this->firstElement = nullptr;
	this->lastElement = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
	LinkedListElement<T>* element = firstElement;
	LinkedListElement<T>* nextElement = nullptr;
	while (element != nullptr) {
		nextElement = element->getNextElement();
		delete element;
		element = nextElement;
	}
}

template<typename T>
int LinkedList<T>::getSize() {
	return this->size;
}

template<typename T>
T LinkedList<T>::get(int index) {
	if (index < this->size && index >= 0) {
		if (index <= this->size >> 1) {
			LinkedListElement<T> *elementPointer = this->firstElement;
			for (int i = 0; i < index; i++)
				elementPointer = elementPointer->getNextElement();
			return elementPointer->getValue();
		}
		else {
			LinkedListElement<T> *elementPointer = this->lastElement;
			for (int i = this->size - 1; i > index; i--)
				elementPointer = elementPointer->getPreviousElement();
			return elementPointer->getValue();
		}
	}
	else
		throw std::out_of_range("Index out of bounds");
}

template<typename T>
bool LinkedList<T>::contains(const T value) {
	LinkedListElement<T> *elementPointer = firstElement;
	for (int i = 0; i < this->size; i++) {
		if (elementPointer->getValue() == value)
			return true;
		elementPointer = elementPointer->getNextElement();
	}
	return false;
}

template<typename T>
void LinkedList<T>::add(const T value, int index) {
	if (index <= this->size && index >= 0) {
		LinkedListElement<T> *newElement = new LinkedListElement<T>(value);
		if (index == 0u) {
			newElement->setNextElement(this->firstElement);
			if (this->firstElement != nullptr)
				this->firstElement->setPreviousElement(newElement);
			else
				this->lastElement = newElement;
			this->firstElement = newElement;
		}
		else {
			LinkedListElement<T> *elementBefore;
			if (index <= this->size >> 1) {
				elementBefore = this->firstElement;
				for (int i = 1; i < index; i++)
					elementBefore = elementBefore->getNextElement();
			}
			else {
				elementBefore = this->lastElement;
				for (int i = this->size; i > index; i--)
					elementBefore = elementBefore->getPreviousElement();
			}
			LinkedListElement<T> *elementAfter = elementBefore->getNextElement();
			newElement->setPreviousElement(elementBefore);
			newElement->setNextElement(elementAfter);
			elementBefore->setNextElement(newElement);
			if (elementAfter != nullptr)
				elementAfter->setPreviousElement(newElement);
			else
				this->lastElement = newElement;
		}
		this->size++;
	}
	else
		throw std::out_of_range("Index out of bounds");
}

template<typename T>
void LinkedList<T>::add(const T value) {
	LinkedListElement<T> *newElement = new LinkedListElement<T>(value, this->lastElement, nullptr);
	if (this->lastElement != nullptr)
		this->lastElement->setNextElement(newElement);
	else
		this->firstElement = newElement;
	this->lastElement = newElement;
	this->size++;
}

template<typename T>
void LinkedList<T>::addStart(const T value) {
	add(value, 0u);
}

template<typename T>
void LinkedList<T>::addEnd(const T value) {
	add(value);
}

template<typename T>
void LinkedList<T>::removeAt(int index) {
	if (index < this->size && index >= 0) {
		LinkedListElement<T> *elementPointer;
		if (index <= this->size >> 1) {
			elementPointer = this->firstElement;
			for (int i = 0; i < index; i++)
				elementPointer = elementPointer->getNextElement();
		}
		else {
			elementPointer = this->lastElement;
			for (int i = this->size - 1; i > index; i--)
				elementPointer = elementPointer->getPreviousElement();
		}
		remove(elementPointer);
	}
	else
		throw std::out_of_range("Index out of bounds");
}

template<typename T>
void LinkedList<T>::removeFirst() {
	if (getSize() > 0)
		remove(this->firstElement);
	else
		throw std::out_of_range("LinkedList is empty");
}

template<typename T>
void LinkedList<T>::removeLast() {
	if (getSize() > 0)
		remove(this->lastElement);
	else
		throw std::out_of_range("LinkedList is empty");
}

template<typename T>
void LinkedList<T>::remove(const T value) {
	LinkedListElement<T> *elementPointer = this->firstElement;
	for (int i = 0; i < this->size; i++) {
		if (elementPointer->getValue() == value) {
			remove(elementPointer);
			return;
		}
		elementPointer = elementPointer->getNextElement();
	}
}

template<typename T>
void LinkedList<T>::print() {
	print(false);
}

template<typename T>
void LinkedList<T>::print(bool biDirectional) {
	LinkedListElement<T> *element = this->firstElement;
	while (element != nullptr) {
		std::cout << element->getValue() << " ";
		element = element->getNextElement();
	}
	std::cout << "\n";
	if (biDirectional) {
		element = this->lastElement;
		while (element != nullptr) {
			std::cout << element->getValue() << " ";
			element = element->getPreviousElement();
		}
		std::cout << "\n";
	}
}

template<typename T>
void LinkedList<T>::remove(LinkedListElement<T>* element) {
	LinkedListElement<T> *elementBefore = element->getPreviousElement();
	LinkedListElement<T> *elementAfter = element->getNextElement();
	if (elementBefore != nullptr)
		elementBefore->setNextElement(elementAfter);
	else
		this->firstElement = elementAfter;
	if (elementAfter != nullptr)
		elementAfter->setPreviousElement(elementBefore);
	else
		this->lastElement = elementBefore;
	delete element;
	this->size--;
}

template class LinkedList<LinkedGraphEdge*>;
