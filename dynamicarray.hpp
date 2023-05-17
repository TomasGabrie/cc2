#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

template <typename T>
class DynamicArray {
private:
    T* array;
    int size;
    int capacity;

public:
    DynamicArray();
    ~DynamicArray();

    void insert(int index, const T& value);
    void remove(int index);
    void pushBack(const T& value);
    int getSize() const;
    T getValue(int index) const;

private:
    void increaseCapacity();
    void decreaseCapacity();
};
#include "dynamicarray.cpp"
#endif  // DYNAMICARRAY_HPP