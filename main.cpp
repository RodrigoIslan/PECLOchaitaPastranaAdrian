// main.cpp
#include <iostream>
#include "Gestor.hpp"

int main() {

    Gestor gestor;
    std::vector<Pedido> pedidos;

    char opcion;
    bool salir = false; // Variable para controlar la salida del bucle

    while (!salir) { // Bucle principal
        std::cout << "Menu:\n";
        std::cout << "A - Generar 12 pedidos aleatorios\n";
        std::cout << "Q - Salir\n";
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 'A':
            case 'a':
                pedidos = gestor.generar12PedidosAleatorios();
                std::cout << "Se han generado 12 pedidos aleatorios." << std::endl;
                // Imprimir información de los pedidos generados
                for (int i = 0; i < pedidos.size(); i++) {
                    std::cout << "Pedido " << i + 1 << ":\n";
                    std::cout << "ID: " << pedidos[i].id << "\n";
                    std::cout << "Numero de seguimiento: " << pedidos[i].seguimiento << "\n";
                    std::cout << "DNI del cliente: " << pedidos[i].dni << "\n";
                    std::cout << "Es urgente: " << (pedidos[i].esUrgente ? "Si" : "No") << "\n";
                    std::cout << "---------------------------------\n";
                }
                break;
            case 'Q':
            case 'q':
                std::cout << "Saliendo del programa." << std::endl;
                salir = true; // Establecer la variable de salida en verdadero
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    }

    return 0;
}
