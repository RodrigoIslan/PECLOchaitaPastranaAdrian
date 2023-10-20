// Pila.cpp
#include "Pila.hpp"
#include "NodoPila.hpp"


Pila::Pila() : cima(nullptr), tamano(0) {}

Pila::~Pila() {
    while (!isEmpty()) {
        pop();
    }
}

void Pila::push(Pedido pedido) {
    NodoPila* nuevoNodo = new NodoPila(pedido);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
    tamano++;
}

void Pila::pop() {
    if (!isEmpty()) {
        NodoPila* nodoAEliminar = cima;
        cima = cima->siguiente;
        delete nodoAEliminar;
        tamano--;
    }
}

Pedido Pila::top() {
    if (!isEmpty()) {
        return cima->pedido;
    }
    // Debes manejar el caso de una pila vacía
    // Podrías lanzar una excepción aquí o tomar otro enfoque.
    // Aquí, simplemente devolvemos un Pedido vacío.
    return Pedido();
}

bool Pila::isEmpty() {
    return tamano == 0;
}

int Pila::size() {
    return tamano;
}

// Desapila un pedido de la pila y lo ingresa en la estación con la menor cantidad de pedidos.
void ingresarPedidoEnEstacion(Pedido pedido, Cola& estacionA, Cola& estacionB, Cola& estacionC, Cola& estacionD) {
    // Calcula cuántos pedidos hay en cada estación.
    int cantidadEstacionA = estacionA.size();
    int cantidadEstacionB = estacionB.size();
    int cantidadEstacionC = estacionC.size();
    int cantidadEstacionD = estacionD.size();

    // Encuentra la estación con la menor cantidad de pedidos.
    Cola* estacionMenosPedidos = &estacionA; // Inicialmente, asumimos que A es la estación con menos pedidos.

    if (cantidadEstacionB < estacionMenosPedidos->size()) {
        estacionMenosPedidos = &estacionB;
    }

    if (cantidadEstacionC < estacionMenosPedidos->size()) {
        estacionMenosPedidos = &estacionC;
    }

    if (cantidadEstacionD < estacionMenosPedidos->size()) {
        estacionMenosPedidos = &estacionD;
    }

    // Ingresa el pedido en la estación con menos pedidos.
    estacionMenosPedidos->encolar(pedido);
}

// Luego de generar y almacenar los pedidos en la pila, puedes ingresarlos en las estaciones uno por uno.
while (!pilaPedidos.estaVacia()) {
    Pedido pedido = pilaPedidos.top();
    ingresarPedidoEnEstacion(pedido, estacionA, estacionB, estacionC, estacionD);
    pilaPedidos.pop();
}

