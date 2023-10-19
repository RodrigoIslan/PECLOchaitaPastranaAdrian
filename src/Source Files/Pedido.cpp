// Pedido.cpp
#include "Pedido.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Pedido::Pedido() {
    generarPedidoAleatorio();
}

void Pedido::mostrarPedido() {
    std::cout << "ID Pedido " << id << std::endl;
    std::cout << "Seguimiento " << seguimiento << std::endl;
    std::cout << "DNI " << dni << std::endl;
    if (esUrgente) {
        std::cout << "Pedido URGENTE" << std::endl;
    }
    else {
        std::cout << "Pedido ESTANDAR" << std::endl;
    }
}

bool Pedido::getEsUrgente() {
    return esUrgente;
}

void Pedido::setId(int id) {
    this->id = id;
}

void Pedido::setSeguimiento(int seguimiento) {
    this->seguimiento = seguimiento;
}

void Pedido::generarPedidoAleatorio() {
    esUrgente = rand() % 2 == 1;  // Aleatoriamente es urgente o no

    if (esUrgente) {
        id = 51 + (rand() % 49); // Genera un número entre 51 y 99 para pedidos urgentes
        seguimiento = 501 + (rand() % 499); // Genera un número entre 501 and 999 para pedidos urgentes
    } else {
        id = 1 + (rand() % 49); // Genera un número entre 1 and 49 para pedidos estándar
        seguimiento = 1 + (rand() % 499); // Genera un número entre 1 and 499 para pedidos estándar
    }

    // Generar un DNI aleatorio con 8 dígitos y una letra
    char letraDNI = 'A' + rand() % 26;  // Letra aleatoria (A-Z)
    std::string numeroDNI = std::to_string(10000000 + (rand() % 90000000)); // Genera un número aleatorio de 8 dígitos

    dni = numeroDNI + letraDNI;
}


