#include "Pila.hpp"

Pila::Pila()
{
    cima = nullptr;
}
bool Pila::estaVacia() { 
    return cima == nullptr;
}
int Pila::longitud() {
    int count = 0;
    NodoPila* temp = cima;
    while (temp != nullptr) {
        count++;
        temp = temp->obtenerSiguiente();
    }
    return count;
}
void Pila::push(Pedido* pedido) {
    NodoPila* nuevoNodo = new NodoPila(pedido);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
    }
Pedido* Pila::pop() {
    if (estaVacia()) {
        return nullptr;
    }
    NodoPila* nodoPop = cima;
    cima = cima->siguiente;
    Pedido* pedido = nodoPop->getPedido();
    delete nodoPop;
    return pedido;
    }


Pila::~Pila(){
    while (!estaVacia()) {
    pop();
    }
}

