#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>

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
        cout << "ID Pedido " << this->id << endl;
        cout << "Seguimiento " << this->seguimiento << endl;
        cout << "DNI " << this->dni << endl;
        if (esUrgente) {
            cout << "Pedido URGENTE" << endl;
        }
        else {
            cout << "Pedido STANDARD" << endl;
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

int main() {
    srand(time(0));

    Pedido pedidos[12];

    for (int i = 0; i < 12; i++) {
        // La generación aleatoria ya se realiza en el constructor, no es necesario llamar a generarPedidoAleatorio() aquí

        // Imprimir información del pedido generado
        cout << "Pedido " << i + 1 << ":\n";
        cout << "ID: " << pedidos[i].id << "\n";
        cout << "Numero de seguimiento: " << pedidos[i].seguimiento << "\n";
        cout << "DNI del cliente: " << pedidos[i].dni << "\n";
        cout << "Es urgente: " << (pedidos[i].esUrgente ? "Si" : "No") << "\n";
        cout << "---------------------------------\n";
    }

    return 0;
}