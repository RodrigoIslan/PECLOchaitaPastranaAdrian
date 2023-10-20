#include "Cola.hpp"

Cola::Cola() : frente(nullptr), final(nullptr) {}

void Cola::encolar(const Pedido& pedido) {
    NodoCola* nuevoNodo = new NodoCola(pedido);
    if (final == nullptr) {
        frente = nuevoNodo;
        final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
}

void Cola::desencolar() {
    if (frente != nullptr) {
        NodoCola* nodoAEliminar = frente;
        frente = frente->siguiente;
        delete nodoAEliminar;
    }
    if (frente == nullptr) {
        final = nullptr;
    }
}

Pedido Cola::frentePedido() const {
    if (frente != nullptr) {
        return frente->pedido;
    }
    return Pedido();
}

bool Cola::estaVacia() const {
    return frente == nullptr;
}

