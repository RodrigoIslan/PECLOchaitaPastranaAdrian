#include "NodoLista.hpp"
#include "Pedido.hpp"

typedef struct NodoLista {
    Pedido pedido;
    struct NodoLista* siguiente;
} NodoLista;


