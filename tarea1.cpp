#include <iostream>
using namespace std;

class MyClass {
private:
    int* myArray; // Puntero al array dinámico
    int size; // Tamaño del array

public:
    MyClass(int s) {
        size = s;
        myArray = new int[size]; // Reserva la memoria para el array
    }

    ~MyClass() {
        delete[] myArray; // Libera la memoria del array
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << myArray[i] << " ";
        }
        cout << "Size: " << size << endl; 
        cout << endl;
    }

    void setArray(int index, int value) {
        myArray[index] = value;
    }

    void push_back(int value) {
        int* tempArray = new int[size + 1]; // Reserva una nueva memoria para el array con tamaño +1
        for (int i = 0; i < size; i++) {
        tempArray[i] = myArray[i]; // Copia los elementos del array original al nuevo array
        }
        tempArray[size] = value; // Agrega el nuevo elemento al final del nuevo array
        delete[] myArray; // Libera la memoria del array original
        myArray = tempArray; // Asigna el nuevo array al puntero del array original
        size++; // Incrementa el tamaño del array
    }
    void removeElement(int index) {
        if (index < 0 || index >= size) { // Verifica si el índice está dentro del rango del array
            std::cout << "Índice inválido" << std::endl;
            return;
        }
        int* tempArray = new int[size - 1]; // Reserva una nueva memoria para el array con tamaño -1
        for (int i = 0; i < index; i++) {
            tempArray[i] = myArray[i]; // Copia los elementos del array original al nuevo array antes del índice especificado
        }
        for (int i = index + 1; i < size; i++) {
            tempArray[i - 1] = myArray[i]; // Copia los elementos del array original al nuevo array después del índice especificado
        }
        delete[] myArray; // Libera la memoria del array original
        myArray = tempArray; // Asigna el nuevo array al puntero del array original
        size--; // Reduce el tamaño del array
        }
    void insertElement(int index, int value) {
        if (index < 0 || index > size) { // Verifica si el índice está dentro del rango del array
            std::cout << "Índice inválido" << std::endl;
            return;
        }
        int* tempArray = new int[size + 1]; // Reserva una nueva memoria para el array con tamaño +1
        for (int i = 0; i < index; i++) {
            tempArray[i] = myArray[i]; // Copia los elementos del array original al nuevo array antes del índice especificado
        }
        tempArray[index] = value; // Agrega el nuevo elemento en la posición especificada
        for (int i = index + 1; i < size + 1; i++) {
            tempArray[i] = myArray[i - 1]; // Copia los elementos del array original al nuevo array después del índice especificado
        }
        delete[] myArray; // Libera la memoria del array original
        myArray = tempArray; // Asigna el nuevo array al puntero del array original
        size++; // Incrementa el tamaño del array
}
};

int main() {
    MyClass obj(5); // Crea un objeto con un array de tamaño 5
    for (int i = 0; i < 5; i++) {
        obj.setArray(i, i+1);
    }
    obj.push_back(12);
    obj.printArray(); // Imprime el contenido del array
    obj.removeElement(0);
    obj.printArray();
    obj.insertElement(1, 10);
    obj.printArray();

    return 0;
}