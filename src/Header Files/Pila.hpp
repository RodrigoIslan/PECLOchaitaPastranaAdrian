// Pila.hpp
#pragma once
#include "NodoPila.hpp"

class Pila {
private:
    NodoPila* cima;
    int tamano;

public:
    Pila();
    ~Pila();

    void push(Pedido pedido);
    void pop();
    Pedido top();
    bool isEmpty();
    int size();
	void ingresarPedidosEnEstaciones(Cola& estacionA, Cola& estacionB, Cola& estacionC, Cola& estacionD);
};
};
