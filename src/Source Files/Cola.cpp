/*#include "Cola.hpp"

Cola::Cola()
{
    cima = nullptr;
}

bool Cola::estaVacia() {
    return cima == nullptr;
    }
void Cola::encolar(Pedido* pedido) {
    NodoCola* nuevoNodo = new NodoCola(pedido);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
    }
Pedido* Cola::desencolar() {
    if (estaVacia()) {
        return nullptr;
    }
    Pedido* pedido = cola.front();
    cola.pop();
    return pedido;
    }
Cola::~Cola()
{
}*/
#include "Cola.hpp"

Cola::Cola() {
    frente = fin = nullptr;
}

Cola::~Cola() {
    while (!estaVacia()) {
        desencolar();
    }
}

void Cola::encolar(Pedido* pedido) {
    NodoCola* nuevoNodo = new NodoCola(pedido);
    if (estaVacia()) {
        frente = fin = nuevoNodo;
    } else {
        fin->establecerSiguiente(nuevoNodo);
        fin = nuevoNodo;
    }
}
int Cola::longitud() {
    int count = 0;
    NodoCola* temp = frente;
    while (temp != nullptr) {
        count++;
        temp = temp->obtenerSiguiente();
    }
    return count;
}
Pedido* Cola::desencolar() {
    if (estaVacia()) {
        throw "La cola está vacía.";
    }

    NodoCola* nodoDesencolado = frente;
    Pedido* pedido = nodoDesencolado->obtenerPedido();
    frente = frente->obtenerSiguiente();
    delete nodoDesencolado;

    if (frente == nullptr) {
        fin = nullptr;
    }

    return pedido;
}

bool Cola::estaVacia() {
    return frente == nullptr;
}

