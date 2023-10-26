#include "NodoPila.hpp"

NodoPila::NodoPila(Pedido* p) {
    pedido = p;
    siguiente = nullptr;
}

Pedido* NodoPila::getPedido() { 
    return pedido; 
}
NodoPila* NodoPila::obtenerSiguiente() {
    return siguiente;
}
void NodoPila::establecerSiguiente(NodoPila* siguiente) {
    this->siguiente = siguiente;
}
NodoPila::~NodoPila() {
}
