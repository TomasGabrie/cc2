#include "dynamicarray.hpp"
#include <iostream>

using namespace std;
 
/*
class SimpleClass {
private:
    int value;

public:
    SimpleClass(int value) : value(value) {}

    int getValue() const {
        return value;
    }
}; */


int main() {
    DynamicArray<char> dynamicArray;

    dynamicArray.pushBack(1);
    dynamicArray.pushBack(2);
    dynamicArray.pushBack(3);

    cout << "El tamaño del array es: " << dynamicArray.getSize() << endl;
    cout << "Valores del arreglo: ";
    for (int i = 0; i < dynamicArray.getSize(); i++) {
        cout << dynamicArray.getValue(i) << " ";
    }
    cout << endl;

    dynamicArray.insert(0, 4);
    dynamicArray.insert(0, 5);

    cout << "Valores del arreglo después de la inserción: ";
    for (int i = 0; i < dynamicArray.getSize(); i++) {
        cout << dynamicArray.getValue(i) << " ";
    }
    cout << endl;

    dynamicArray.remove(2);

    cout << "Valores del arreglo después de la eliminación: ";
    for (int i = 0; i < dynamicArray.getSize(); i++) {
        cout << dynamicArray.getValue(i) << " ";
    }
    cout << endl;

    cout << "Probando con ints" << endl;

    DynamicArray<int> dynamicArray2;

    dynamicArray2.pushBack(1);
    dynamicArray2.pushBack(2);
    dynamicArray2.pushBack(3);

    cout << "El tamaño del array es: " << dynamicArray2.getSize() << endl;
    cout << "Valores del arreglo: ";
    for (int i = 0; i < dynamicArray2.getSize(); i++) {
        cout << dynamicArray2.getValue(i) << " ";
    }
    cout << endl;

    dynamicArray2.insert(0, 4);
    dynamicArray2.insert(0, 5);

    cout << "Valores del arreglo después de la inserción: ";
    for (int i = 0; i < dynamicArray2.getSize(); i++) {
        cout << dynamicArray2.getValue(i) << " ";
    }
    cout << endl;

    dynamicArray2.remove(2);

    cout << "Valores del arreglo después de la eliminación: ";
    for (int i = 0; i < dynamicArray2.getSize(); i++) {
        cout << dynamicArray2.getValue(i) << " ";
    }
    cout << endl;
    /*
    DynamicArray<SimpleClass> dynamicArray3;

    dynamicArray.pushBack(SimpleClass(1));
    dynamicArray.pushBack(SimpleClass(2));
    dynamicArray.pushBack(SimpleClass(3));

    for (int i = 0; i < dynamicArray3.getSize(); i++) {
        SimpleClass obj = dynamicArray3.getValue(i);
        int value = obj.getValue();
        std::cout << "Value: " << value << std::endl;
    }*/

    system("pause");
    return 0;
}