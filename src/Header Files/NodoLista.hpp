#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Pedido.hpp"
class NodoLista {
public:
    NodoLista(Pedido* pedido);
    Pedido* obtenerPedido();
    NodoLista* obtenerSiguiente();
    void establecerSiguiente(NodoLista* siguiente);
    ~NodoLista();
private:
    Pedido* pedido;
    NodoLista* siguiente;
    friend class Lista;
};

#endif // NODOLISTA_HPP
