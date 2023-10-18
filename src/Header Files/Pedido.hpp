#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <string> // Incluye la biblioteca string

class Pedido {
public:
    Pedido();
    void mostrarPedido();
    bool getEsUrgente();
    void setId(int id);
    void setSeguimiento(int seguimiento);

private:
    int id;             // Se asigna durante el empaquetamiento
    int seguimiento;    // Se asigna en el postempaquetamiento
    std::string dni;    // Corregido para utilizar std::string
    bool esUrgente;
    void generarPedidoAleatorio();
};

#endif // PEDIDO_HPP