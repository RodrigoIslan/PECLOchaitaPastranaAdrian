#ifndef PEDIDO_HPP
#define PEDIDO_HPP
/*
* Cabecera de la clase Pedido: se decleran las cabeceras de las funciones y los atributos
*/
class Pedido{

public:
    Pedido();
    void mostrarPedido();
    bool getEsUrgente();
    void setId(int id);
    void setSeguimiento(int seguimiento);

private:
    int id;             // Se asigna durante el empaquetamente
    int seguimiento;    // Se asigna en el postempaquetada
    char dni[9];
    bool esUrgente;
    void generarPedidoAleatorio();
};


#endif // PEDIDO_HPP_INCLUDED