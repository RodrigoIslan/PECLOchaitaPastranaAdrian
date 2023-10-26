/*#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include "Pedido.hpp"
#include <queue>
class Cola {
public:
    Cola();
    ~Cola();
    void encolar(Pedido* pedido);
    Pedido* desencolar();
    bool estaVacia();
private:
    std::queue<Pedido*> cola;
    pnodoCola primero,ultimo;
    int longitud;
    NodoCola* cima;
};

#endif // COLA_HPP*/
#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola {
public:
    Cola();
    ~Cola();
    void encolar(Pedido* pedido);
    Pedido* desencolar();
    bool estaVacia();
    int longitud();
private:
    NodoCola* frente;
    NodoCola* fin;
};

#endif

