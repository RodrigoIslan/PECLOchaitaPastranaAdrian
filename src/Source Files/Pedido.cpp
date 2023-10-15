#include "Pedido.hpp"

typedef struct {
    int id;
    int numeroSeguimiento;
    char dniCliente[15];
    int urgente; // 1 para urgente, 0 para estándar
} Pedido;


