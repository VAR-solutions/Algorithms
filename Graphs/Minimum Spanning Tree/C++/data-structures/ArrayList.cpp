#include <iostream>
#include <stdexcept>
#include <string>
#include "LinkedList.hpp"
#include "LinkedGraphEdge.hpp"
#include "ArrayList.hpp"

template<typename T>
ArrayList<T>::ArrayList() {
	this->size = 0;
	this->array = new T[size];
}

template<typename T>
ArrayList<T>::~ArrayList() {
	delete[] array;
}

template<typename T>
int ArrayList<T>::getSize() {
	return this->size;
}

template<typename T>
T ArrayList<T>::get(int index) {
	if (index < this->size && index >= 0)
		return this->array[index];
	else
		throw std::out_of_range("Index out of bounds");
}

template<typename T>
bool ArrayList<T>::contains(const T value) {
	for (int i = 0; i < this->size; i++) {
		if (this->array[i] == value)
			return true;
	}
	return false;
}

template<typename T>
void ArrayList<T>::add(const T value, int index) {
	if (index <= this->size && index >= 0) {
		T *newArray = new T[++this->size];
		for (int i = 0; i < this->size; i++) {
			if (i < index)
				newArray[i] = this->array[i];
			else {
				if (i == index)
					newArray[i] = value;
				else
					newArray[i] = this->array[i - 1];
			}
		}
		delete[] this->array;
		this->array = newArray;
	}
	else
		throw std::out_of_range("Index out of bounds");
}

template<typename T>
void ArrayList<T>::add(const T value) {
	T *newArray = new T[++this->size];
	for (int i = 0; i < this->size; i++)
		newArray[i] = this->array[i];
	newArray[this->size - 1] = value;
	delete [] this->array;
	this->array = newArray;
}

template<typename T>
void ArrayList<T>::addStart(const T value) {
	add(value, 0u);
}

template<typename T>
void ArrayList<T>::addEnd(const T value) {
	add(value);
}

template<typename T>
void ArrayList<T>::removeAt(int index) {
	if (index < this->size && index >= 0) {
		T *newArray = new T[--this->size];
		for (int i = 0; i < this->size; i++) {
			if (i < index)
				newArray[i] = this->array[i];
			else
				newArray[i] = this->array[i + 1];
		}
		delete[] this->array;
		this->array = newArray;
	}
	else
		throw std::out_of_range("Index out of bounds");
}

template<typename T>
void ArrayList<T>::removeFirst() {
	removeAt(0u);
}

template<typename T>
void ArrayList<T>::removeLast() {
	removeAt(getSize() - 1);
}

template<typename T>
void ArrayList<T>::remove(const T value) {
	for (int i = 0; i < this->size; i++) {
		if (this->array[i] == value) {
			removeAt(i);
			return;
		}
	}
}

template<typename T>
void ArrayList<T>::print() {
	for (int i = 0; i < this->size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}

template class ArrayList<LinkedList<LinkedGraphEdge*>*>;
