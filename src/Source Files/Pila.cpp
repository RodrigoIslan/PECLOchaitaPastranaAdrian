// Pila.cpp
#include "Pila.hpp"
#include "NodoPila.hpp"


Pila::Pila() : cima(nullptr), tamano(0) {}

Pila::~Pila() {
    while (!isEmpty()) {
        pop();
    }
}

void Pila::push(Pedido pedido) {
    NodoPila* nuevoNodo = new NodoPila(pedido);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
    tamano++;
}

void Pila::pop() {
    if (!isEmpty()) {
        NodoPila* nodoAEliminar = cima;
        cima = cima->siguiente;
        delete nodoAEliminar;
        tamano--;
    }
}

Pedido Pila::top() {
    if (!isEmpty()) {
        return cima->pedido;
    }
    // Debes manejar el caso de una pila vacía
    // Podrías lanzar una excepción aquí o tomar otro enfoque.
    // Aquí, simplemente devolvemos un Pedido vacío.
    return Pedido();
}

bool Pila::isEmpty() {
    return tamano == 0;
}

int Pila::size() {
    return tamano;
}


