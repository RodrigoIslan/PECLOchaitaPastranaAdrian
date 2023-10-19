#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>  // Agrega la cabecera para usar vectores

using namespace std;

class Pedido {
public:
    int id;
    int seguimiento;
    string dni;
    bool esUrgente;

    Pedido() {
        generarPedidoAleatorio();
    }

    void mostrarPedido() {
        cout << "ID Pedido " << id << endl;
        cout << "Seguimiento " << seguimiento << endl;
        cout << "DNI " << dni << endl;
        if (esUrgente) {
            cout << "Pedido URGENTE" << endl;
        }
        else {
            cout << "Pedido ESTANDAR" << endl;
        }
    }

    bool getEsUrgente() {
        return this->esUrgente;
    }

    void setId(int id) {
        this->id = id;
    }

    void setSeguimiento(int seguimiento) {
        this->seguimiento = seguimiento;
    }

    void generarPedidoAleatorio() {
        esUrgente = rand() % 2 == 1;  // Aleatoriamente es urgente o no

        if (esUrgente) {
            id = 51 + (rand() % 49); // Genera un número entre 51 y 99 para pedidos urgentes
            seguimiento = 501 + (rand() % 499); // Genera un número entre 501 y 999 para pedidos urgentes
        } else {
            id = 1 + (rand() % 49); // Genera un número entre 1 y 49 para pedidos estándar
            seguimiento = 1 + (rand() % 499); // Genera un número entre 1 y 499 para pedidos estándar
        }

        // Generar un DNI aleatorio con 8 dígitos y una letra
        char letraDNI = 'A' + rand() % 26;  // Letra aleatoria (A-Z)
        string numeroDNI = to_string(10000000 + (rand() % 90000000)); // Genera un número aleatorio de 8 dígitos

        dni = numeroDNI + letraDNI;
    }
};

class Gestor {
public:
    vector<Pedido> generar12PedidosAleatorios() {
        vector<Pedido> pedidos;
        for (int i = 0; i < 12; i++) {
            Pedido pedido;
            pedidos.push_back(pedido);
        }
        return pedidos;
    }
};

int main() {
    srand(time(0));

    Gestor gestor;
    vector<Pedido> pedidos;

    char opcion;
    bool salir = false; // Variable para controlar la salida del bucle

    while (!salir) { // Bucle principal
        cout << "Menu:\n";
        cout << "A - Generar 12 pedidos aleatorios\n";
        cout << "Q - Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 'A':
            case 'a':
                pedidos = gestor.generar12PedidosAleatorios();
                cout << "Se han generado 12 pedidos aleatorios." << endl;
                // Imprimir información de los pedidos generados

                for (int i = 0; i < pedidos.size(); i++) {
                    cout << "Pedido " << i + 1 << ":\n";
                    cout << "ID: " << pedidos[i].id << "\n";
                    cout << "Numero de seguimiento: " << pedidos[i].seguimiento << "\n";
                    cout << "DNI del cliente: " << pedidos[i].dni << "\n";
                    cout << "Es urgente: " << (pedidos[i].esUrgente ? "Si" : "No") << "\n";
                    cout << "---------------------------------\n";
                }
                break;
            case 'Q':
            case 'q':
                cout << "Saliendo del programa." << endl;
                salir = true; // Establecer la variable de salida en verdadero
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    }

    return 0;
}

