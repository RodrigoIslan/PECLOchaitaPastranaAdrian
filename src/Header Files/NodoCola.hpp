/*#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "Pedido.hpp"

class NodoCola
{
public:
    NodoCola(Pedido* pedido, NodoCola* sig = NULL);
    ~NodoCola();
    Pedido* getPedido();
    NodoCola* getSiguiente();
private:
    Pedido* pedido;
    NodoCola* siguiente;
    friend class Cola;
};
typedef NodoCola* pnodoCola;
#endif // NODOCOLA_HPP*/
#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include "Pedido.hpp"

class NodoCola {
public:
    NodoCola(Pedido* pedido);
    Pedido* obtenerPedido();
    NodoCola* obtenerSiguiente();
    void establecerSiguiente(NodoCola* siguiente);

private:
    Pedido* pedido;
    NodoCola* siguiente;
};

#endif

