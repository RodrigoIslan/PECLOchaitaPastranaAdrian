#include "NodoPila.hpp"

typedef struct NodoPila {
    Pedido pedido;
    struct NodoPila* siguiente;
} NodoPila;


