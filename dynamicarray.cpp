#include "dynamicarray.hpp"
#include <iostream>

using namespace std;

template <typename T>
DynamicArray<T>::DynamicArray() {
    size = 0;
    capacity = 1;
    array = new T[capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}

template <typename T>
void DynamicArray<T>::insert(int index, const T& value) {
    if (index < 0 || index > size) {
        cout << "Índice fuera de rango." << endl;
        return;
    }
        
    if (size == capacity) {
        increaseCapacity();
    }

    for (int i = size - 1; i >= index; i--) {
        array[i + 1] = array[i];
    }

    array[index] = value;
    size++;
}

template <typename T>
void DynamicArray<T>::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Índice fuera de rango." << endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    size--;

    if (size <= capacity / 4) {
        decreaseCapacity();
    }
}

template <typename T>
void DynamicArray<T>::pushBack(const T& value) {
    insert(size, value);
}

template <typename T>
int DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
T DynamicArray<T>::getValue(int index) const {
    if (index >= 0 && index < size) {
        return array[index];
    } else {
        cout << "Índice fuera de rango." << endl;
        return T();
    }
}

template <typename T>
void DynamicArray<T>::increaseCapacity() {
    capacity *= 2;
    T* newArray = new T[capacity];

    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
}

template <typename T>
void DynamicArray<T>::decreaseCapacity() {
    capacity /= 2;
    T* newArray = new T[capacity];

    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
}