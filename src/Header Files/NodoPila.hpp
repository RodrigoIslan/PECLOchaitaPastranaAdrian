#ifndef NODOPILA_HPP_INCLUDED
#define NODOPILA_HPP_INCLUDED

#include "Pedido.hpp"

class NodoPila{

    private:
        Pedido value;
        Pedido *next;

    public:
        NodoPila(Pedido value);
        Pedido getValue();
        Pedido* getNext();
        void setNext(Pedido *next);
};


#endif // NODOPILA_HPP_INCLUDED