/*#include "NodoCola.hpp"

NodoCola::NodoCola(Pedido* p, NodoCola* sig)
{
    pedido = p;
    siguiente = sig;
}
Pedido* NodoCola::getPedido() { 
    return pedido; 
}

NodoCola* NodoCola::getSiguiente() {
    return siguiente; 
}
NodoCola::~NodoCola()
{
}*/
#include "NodoCola.hpp"

NodoCola::NodoCola(Pedido* pedido) {
    this->pedido = pedido;
    this->siguiente = nullptr;
}

Pedido* NodoCola::obtenerPedido() {
    return pedido;
}

NodoCola* NodoCola::obtenerSiguiente() {
    return siguiente;
}

void NodoCola::establecerSiguiente(NodoCola* siguiente) {
    this->siguiente = siguiente;
}

