#include "Lista.hpp"
#include "NodoLista.hpp"

typedef struct {
    NodoLista* cabeza;
} Lista;

void inicializarLista(Lista* lista) {
    lista->cabeza = NULL;
}

void insertarEnOrdenLista(Lista* lista, Pedido pedido) {
    NodoLista* nuevoNodo = (NodoLista*)malloc(sizeof(NodoLista));
    if (nuevoNodo == NULL) {
        // Manejo de error, no se pudo asignar memoria
        return;
    }
    nuevoNodo->pedido = pedido;
    nuevoNodo->siguiente = NULL;

    NodoLista* actual = lista->cabeza;
    NodoLista* anterior = NULL;

    while (actual != NULL && actual->pedido.id < pedido.id) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (anterior == NULL) {
        nuevoNodo->siguiente = lista->cabeza;
        lista->cabeza = nuevoNodo;
    } else {
        nuevoNodo->siguiente = actual;
        anterior->siguiente = nuevoNodo;
    }
}

