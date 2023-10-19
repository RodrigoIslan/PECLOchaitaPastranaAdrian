// main.cpp (extensión del código existente)
#include <iostream>
#include "Gestor.hpp"
#include "Pila.hpp"

int main() {
    Gestor gestor;
    Pila pilaPedidos; // Usamos la clase Pila en lugar de std::stack
    bool opcionAVisible = true; // Variable para controlar la visibilidad de la opción A

    char opcion;
    bool salir = false;

    while (!salir) {
        std::cout << "Menu:\n";
        if (opcionAVisible) {
            std::cout << "A - Generar 12 pedidos aleatorios\n";
        }
        std::cout << "B - Mostrar pedidos almacenados\n";
        std::cout << "C - Borrar todos los pedidos almacenados\n"; // Nueva opción
        std::cout << "Q - Salir\n";
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 'A':
            case 'a':
                if (pilaPedidos.size() >= 48) {
                    std::cout << "La pila de pedidos está llena (48 pedidos)." << std::endl;
                    opcionAVisible = false; // Ocultar la opción "A"
                } else {
                    std::vector<Pedido> nuevosPedidos = gestor.generar12PedidosAleatorios();
                    for (const Pedido& pedido : nuevosPedidos) {
                        pilaPedidos.push(pedido);
                    }
                    std::cout << "Se han generado 12 pedidos aleatorios." << std::endl;
                    if (pilaPedidos.size() >= 48) {
                        opcionAVisible = false; // Ocultar la opción "A" después de alcanzar el límite
                    }
                }
                break;
            case 'B':
            case 'b':
                std::cout << "Pedidos almacenados en la pila:\n";
                while (!pilaPedidos.isEmpty()) {
                    Pedido pedido = pilaPedidos.top();
                    pilaPedidos.pop();
                    // Mostrar información del pedido
                    std::cout << "ID: " << pedido.id << "\n";
                    std::cout << "Numero de seguimiento: " << pedido.seguimiento << "\n";
                    std::cout << "DNI del cliente: " << pedido.dni << "\n";
                    std::cout << "Es urgente: " << (pedido.esUrgente ? "Si" : "No") << "\n";
                    std::cout << "---------------------------------\n";
                }
                opcionAVisible = true; // Mostrar la opción "A" nuevamente
                break;
            case 'C':
            case 'c':
                while (!pilaPedidos.isEmpty()) {
                    pilaPedidos.pop();
                }
                std::cout << "Todos los pedidos han sido borrados." << std::endl;
                opcionAVisible = true; // Habilitar nuevamente la opción "A"
                break;
            case 'Q':
            case 'q':
                std::cout << "Saliendo del programa." << std::endl;
                salir = true;
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    }

    return 0;
}

