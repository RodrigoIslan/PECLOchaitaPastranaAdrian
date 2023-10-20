// Pedido.cpp (sin cambios en Pedido.cpp)

// NodoPila.hpp
#pragma once
#include "Pedido.hpp"

class NodoPila {
public:
    Pedido pedido;
    NodoPila* siguiente; //Esta línea declara una variable miembro de la clase NodoPila llamada siguiente, que es un puntero a otro objeto de tipo NodoPila

    NodoPila(Pedido p) : pedido(p), siguiente(nullptr) {} //se encarga de inicializar un nodo de la pila con un pedido y configurar su puntero siguiente
};