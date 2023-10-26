#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"
class Pila {
public:
    Pila();
    ~Pila();
    bool estaVacia();
    void push(Pedido* pedido);
    Pedido* pop();
    int longitud();
private:
    NodoPila* cima;
    /*NodoPila* frente;*/
};
#endif // PILA_HPP
