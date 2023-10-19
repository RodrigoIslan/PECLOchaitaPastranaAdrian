// Pedido.cpp (sin cambios en Pedido.cpp)

// NodoPila.hpp
#pragma once
#include "Pedido.hpp"

class NodoPila {
public:
    Pedido pedido;
    NodoPila* siguiente;

    NodoPila(Pedido p) : pedido(p), siguiente(nullptr) {}
};