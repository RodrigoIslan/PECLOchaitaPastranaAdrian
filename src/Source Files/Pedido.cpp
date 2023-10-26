#include "Pedido.hpp"

Pedido::Pedido(const int id, int seguimiento, const std::string& dni, bool urgente)
    : id(id), seguimiento(seguimiento), dni(dni), urgente(urgente) {
}
int Pedido::getID() { 
    return id; 
    }
int Pedido::getSeguimiento() { 
    return seguimiento; 
    }
std::string Pedido::getDNI() const {
    return dni; 
    }
bool Pedido::esUrgente() {
    return urgente; 
    }
int Pedido::getNumeroSeguimiento() {
    return numeroSeguimiento;
    }
void Pedido::asignarNumeroSeguimiento(int numero) {
    numeroSeguimiento = numero;
}
void Pedido::reiniciarNumeroSeguimiento() {
    numeroSeguimiento = 0; // Reinicia el número de seguimiento a 0
    }
Pedido::~Pedido()
{
}


