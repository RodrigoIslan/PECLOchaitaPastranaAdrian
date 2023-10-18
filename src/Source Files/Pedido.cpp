#include "Pedido.hpp"
#include <ctime>
#include <iostream>
#include <string.h>
using namespace std;

/*
* Implementacion de la clase Pedido: se implementan(de completan)
* las funciones definidas en la cabecera
*/
Pedido::Pedido(){
    generarPedidoAleatorio();
}

void Pedido::mostrarPedido(){
    cout << "ID Pedido " << this->id << endl;
    cout << "Seguimiento " << this->seguimiento << endl;
    cout << "DNI " << this->dni << endl;
    if(esUrgente){
         cout << "Pedido URGENTE" << endl;
    }else{
        cout << "Pedido STANDAR" << endl;
    }
}

bool Pedido::getEsUrgente(){
    return this->esUrgente;
}

void Pedido::setId(int id){
    this->id = id;
}

void Pedido::setSeguimiento(int seguimiento){
    this->seguimiento = seguimiento;
}


void Pedido::generarPedidoAleatorio(){
    this->id = 0;
    this->seguimiento = 0;

    char dni[][11] = {"123456789A" , "234567890B","345678901C"};
    srand(time(NULL));

    // Generamos numeros aleatorios
    int rDni = rand() % 3;
    int rEsUrgente = rand() % 2;

    strcpy(this->dni,dni[rDni]);
    this->esUrgente = rEsUrgente;
}

