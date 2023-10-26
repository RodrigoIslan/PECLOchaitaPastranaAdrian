#include "NodoLista.hpp"

NodoLista::NodoLista(Pedido* p){
    pedido = p;
    siguiente = nullptr;
}
Pedido* NodoLista::obtenerPedido() {
    return pedido;
}

NodoLista* NodoLista::obtenerSiguiente() {
    return siguiente;
}
void NodoLista::establecerSiguiente(NodoLista* siguiente) {
    this->siguiente = siguiente;
}
NodoLista::~NodoLista() {
}
