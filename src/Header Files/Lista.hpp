#ifndef LISTA_HPP
#define LISTA_HPP
#include "Pedido.hpp"
#include "NodoLista.hpp"
#include <list>
class Lista {
public:
    Lista();
    ~Lista();
    void insertarEnOrden(Pedido* pedido);
    void mostrarPedidos(Lista& lista);
    bool estaVacia();
    Pedido* pop();
    void push(Pedido* pedido);
    Pedido* encontrarPedidoUrgenteMenosPrioritario();
    Pedido* encontrarPedidoEstandarPrioritario();
    void limpiar();
    int longitud();
private:
    NodoLista* cima;
    NodoLista* fin;
    //std::list<Pedido*> lista;
};
#endif // LISTA_HPP
