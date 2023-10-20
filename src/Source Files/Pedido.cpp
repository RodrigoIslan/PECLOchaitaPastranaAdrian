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
        std::cout << "Pedido URGENTE" << std::endl; // Pedido urgente
    }
    else {
        std::cout << "Pedido ESTANDAR" << std::endl; // Pedido Estandar
    }
}

void Pedido::generarPedidoAleatorio() {
    esUrgente = rand() % 2 == 1;  // Aleatoriamente si es urgente o no

    if (esUrgente) {
        id = 51 + (rand() % 49); // Genera un id entre 51 y 99 para pedidos urgentes
        seguimiento = 501 + (rand() % 499); // Genera un seguimiento entre 501 y 999 para pedidos urgentes
    } else {
        id = 1 + (rand() % 49); // Genera un id entre 1 y 49 para pedidos estándar
        seguimiento = 1 + (rand() % 499); // Genera un seguimiento entre 1 y 499 para pedidos estándar
    }

    // Generar un DNI aleatorio con 8 dígitos y una letra
    char letraDNI = 'A' + rand() % 26;  // Letra aleatoria (A-Z) para el DNI
    std::string numeroDNI = std::to_string(10000000 + (rand() % 90000000)); // Genera un número aleatorio de 8 dígitos para el DNI

    dni = numeroDNI + letraDNI; //Junta el numero aleatorio generado junto con la letra
}
