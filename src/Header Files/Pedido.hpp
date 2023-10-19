// Pedido.h
#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>

class Pedido {
public:
    int id;
    int seguimiento;
    std::string dni;
    bool esUrgente;

    Pedido();
    void mostrarPedido();
    bool getEsUrgente();
    void setId(int id);
    void setSeguimiento(int seguimiento);

private:
    void generarPedidoAleatorio();
};

#endi