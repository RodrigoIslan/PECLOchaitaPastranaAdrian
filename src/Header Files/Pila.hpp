#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED
#include "NodoPila.hpp"
class Pila{

    public:
        Pila();
        void desapilar();
        void apilar();
        void cima();
        bool vacia();
    private:
        NodoPila *nodoCima;

};

#endif // PILA_HPP_INCLUDED
