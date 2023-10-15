#include "Pila.hpp"
#include "NodoPila.hpp"
#include "Pedido.hpp"

typedef struct {
    NodoPila* cima;
} Pila;

void inicializarPila(Pila* pila) {
    pila->cima = nullptr;
}

void pushPila(Pila* pila, Pedido pedido) {
    NodoPila* nuevoNodo = (NodoPila*)malloc(sizeof(NodoPila));
    if (nuevoNodo == NULL) {
        // Manejo de error, no se pudo asignar memoria
    } else {
        nuevoNodo->pedido = pedido;
        nuevoNodo->siguiente = pila->cima;
        pila->cima = nuevoNodo;
    }
}


Pedido popPila(Pila* pila) {
    Pedido pedidoExtraido;
    if (pila->cima != NULL) {
        NodoPila* nodoAEliminar = pila->cima;
        pedidoExtraido = nodoAEliminar->pedido;
        pila->cima = nodoAEliminar->siguiente;
        free(nodoAEliminar);
    } else {
        // Manejo de error, la pila está vacía
    }
    return pedidoExtraido;
}


