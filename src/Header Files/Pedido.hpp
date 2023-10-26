#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <iostream>
#include <string>
class Pedido {
public:
    Pedido(int id, int seguimiento, const std::string& dni, bool urgente);
    Pedido();
    ~Pedido();
    int getID();
    int getSeguimiento();
    void asignarNumeroSeguimiento(int numero);
    int getNumeroSeguimiento();
    std::string getDNI() const; 
    bool esUrgente(); 
    void reiniciarNumeroSeguimiento();

private:
    int id;
    int seguimiento;
    int numeroSeguimiento;
    std::string dni;
    bool urgente;
};

#endif // PEDIDO_HPP
