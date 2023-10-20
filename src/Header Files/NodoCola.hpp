#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "Pedido.hpp"

class NodoCola {
public:
    Pedido pedido;
    NodoCola* siguiente;

    NodoCola(const Pedido& p);
};

#endif  // NODOCOLA_HPP
