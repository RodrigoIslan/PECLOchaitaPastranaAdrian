#include "Pila.hpp"
#include <iostream>

Pila::Pila(){
    this->nodoCima = NULL;
}

bool Pila::vacia(){
    // Si nodoCima no es NULL, contiene elementos
    return this->nodoCima == NULL;
}


