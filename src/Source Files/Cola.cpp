#include "Cola.hpp"
#include "NodoCola.hpp"

typedef struct {
    NodoCola* frente;
    NodoCola* finalCola;
} Cola;


void inicializarCola(Cola* cola) {
    cola->frente = cola->finalCola = NULL;
}


void enqueueCola(Cola* cola, Pedido pedido) {
    NodoCola* nuevoNodo = (NodoCola*)malloc(sizeof(NodoCola));
    if (nuevoNodo == NULL) {
        // Manejo de error, no se pudo asignar memoria
    } else {
        nuevoNodo->pedido = pedido;
        nuevoNodo->siguiente = NULL;
        if (cola->finalCola == NULL) {
            cola->frente = cola->finalCola = nuevoNodo;
        } else {
            cola->finalCola->siguiente = nuevoNodo;
            cola->finalCola = nuevoNodo;
        }
    }
}

Pedido dequeueCola(Cola* cola) {
    Pedido pedidoExtraido;
    if (cola->frente != NULL) {
        NodoCola* nodoAEliminar = cola->frente;
        pedidoExtraido = nodoAEliminar->pedido;
        cola->frente = nodoAEliminar->siguiente;
        if (cola->frente == NULL) {
            cola->finalCola = NULL;
        }
        free(nodoAEliminar);
    } else {
        // Manejo de error, la cola está vacía
    }
    return pedidoExtraido;
}
