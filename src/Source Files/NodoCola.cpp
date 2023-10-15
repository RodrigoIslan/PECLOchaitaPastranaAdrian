#include "NodoCola.hpp"

typedef struct NodoCola {
    Pedido pedido;
    struct NodoCola* siguiente;
} NodoCola;


