#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include "Pedido.hpp"
class NodoPila {
public:
    NodoPila(Pedido* pedido);
    ~NodoPila();
    Pedido* getPedido();
    NodoPila* obtenerSiguiente();
    void establecerSiguiente(NodoPila* siguiente);

private:
    Pedido* pedido;
    NodoPila* siguiente;
    friend class Pila;
};

#endif // NODOPILA_HPP