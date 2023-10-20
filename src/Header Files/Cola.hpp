#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"

class Cola {
private:
    NodoCola* frente;
    NodoCola* final;

public:
    Cola();

    void encolar(const Pedido& pedido);
    void desencolar();
    Pedido frentePedido() const;
    bool estaVacia() const;
};

#endif  // COLA_HPP
