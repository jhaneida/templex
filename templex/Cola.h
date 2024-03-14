#pragma once
#include <iostream>
    using namespace std;

template <typename T>
class Cola
{
private:
    T* elementos;
    int capacidad;
    int primero;
    int ultimo;
    int numElementos;

public:
    Cola(int tamano);
    ~Cola();
    void push(T dato);
    T pop();
    bool estaVacia();
    bool estaLlena();
    void imprimir();
};

template<typename T>
Cola<T>::Cola(int tamano) : capacidad(tamano), primero(0), ultimo(-1), numElementos(0) {
    elementos = new T[capacidad];
}

template<typename T>
Cola<T>::~Cola() {
    delete[] elementos;
}

template<typename T>
void Cola<T>::push(T dato) {
    if (!estaLlena()) {
        ultimo = (ultimo + 1) % capacidad;
        elementos[ultimo] = dato;
        numElementos++;
    }
    else {
        cout << "La cola está llena" << endl;
    }
}

template<typename T>
T Cola<T>::pop() {
    if (!estaVacia()) {
        T dato = elementos[primero];
        primero = (primero + 1) % capacidad;
        numElementos--;
        return dato;
    }
    else {
        cout << "La cola está vacía" << endl;
        return T();
    }
}

template<typename T>
bool Cola<T>::estaVacia() {
    return numElementos == 0;
}

template<typename T>
bool Cola<T>::estaLlena() {
    return numElementos == capacidad;
}

template<typename T>
void Cola<T>::imprimir() {
    if (estaVacia()) {
        cout << "La cola está vacía" << endl;
        return;
    }
    int i = primero;
    for (int j = 0; j < numElementos; j++) {
        cout << elementos[i] << " ";
        i = (i + 1) % capacidad;
    }
    cout << endl;
}

