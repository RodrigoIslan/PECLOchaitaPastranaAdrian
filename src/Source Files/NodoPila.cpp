#include "NodoPila.hpp"
#include <iostream>

NodoPila::NodoPila(Pedido value){
    this->value = value;
    this->next = NULL;
}

Pedido NodoPila::getValue(){
    return this->value;
}
Pedido* NodoPila::getNext(){
    return this->next;
}

void NodoPila::setNext(Pedido *next){
    this->next = next;
}

NodoPila::~NodoPila()
{
}
