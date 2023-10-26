#include "Lista.hpp"

Lista::Lista()
{
    cima = nullptr;
}
int Lista::longitud() {
    int count = 0;
    NodoLista* temp = cima;
    while (temp != nullptr) {
        count++;
        temp = temp->obtenerSiguiente();
    }
    return count;
}
void Lista::insertarEnOrden(Pedido* pedido) {
        NodoLista* nuevoNodo = new NodoLista(pedido);
        if (!cima || pedido->getID() > cima->pedido->getID()) {
            nuevoNodo->siguiente = cima;
            cima = nuevoNodo;
        } else {
            NodoLista* actual = cima;
            while (actual->siguiente && pedido->getID() < actual->siguiente->pedido->getID()) {
                actual = actual->siguiente;
            }
            nuevoNodo->siguiente = actual->siguiente;
            actual->siguiente = nuevoNodo;
        }
    if (pedido->esUrgente()) {
        // Asignar número de seguimiento para pedidos urgentes
        static int numeroSeguimientoUrgente = 501; // Comienza en 501
        pedido->asignarNumeroSeguimiento(numeroSeguimientoUrgente);
        if (numeroSeguimientoUrgente < 999) {
            numeroSeguimientoUrgente++;
        }
    } else {
        // Asignar número de seguimiento para pedidos estándar
        static int numeroSeguimientoEstandar = 1; // Comienza en 1
        pedido->asignarNumeroSeguimiento(numeroSeguimientoEstandar);
        if (numeroSeguimientoEstandar < 499) {
            numeroSeguimientoEstandar++;
        }
    }
}
bool Lista::estaVacia() {
    return cima == nullptr;
}
Pedido* Lista::pop() {
    if (estaVacia()) {
        throw "La cola está vacía.";
    }
    NodoLista* nodoDesencolado = cima;
    Pedido* pedido = nodoDesencolado->obtenerPedido();
    cima = cima->obtenerSiguiente();
    delete nodoDesencolado;
    if (cima == nullptr) {
        fin = nullptr;
    }
    return pedido;
}
void Lista::push(Pedido* pedido) {
    NodoLista* nuevoNodo = new NodoLista(pedido);
    if (estaVacia()) {
        cima = fin = nuevoNodo;
    } else {
        fin->establecerSiguiente(nuevoNodo);
        fin = nuevoNodo;
    }
}
void Lista::mostrarPedidos(Lista& lista) {
    Lista listaTemporal; // Crear una pila temporal para mostrar los pedidos sin borrarlos
    while (!lista.estaVacia()) {
        Pedido* pedido = lista.pop();
        std::cout << "El pedido a nombre del titular con DNI "<< pedido->getDNI()
        << " es de caracter " << (pedido->esUrgente() ? "urgente" : "estandar") << ", su ID es: " << pedido->getID() <<" y su numero de seguimiento asignado es: "<< pedido->getSeguimiento() << std::endl;
        listaTemporal.push(pedido); // Agregar el pedido a la pila temporal
    }
    while (!listaTemporal.estaVacia()) {
        Pedido* pedido = listaTemporal.pop();
        lista.push(pedido);
    }
}
Pedido* Lista::encontrarPedidoEstandarPrioritario() {
    Pedido* pedidoPrioritario = nullptr;
    NodoLista* actual = fin;
    pedidoPrioritario = actual->pedido;
    return pedidoPrioritario;
}
Pedido* Lista::encontrarPedidoUrgenteMenosPrioritario() {
    Pedido* pedidoMenosPrioritario = nullptr;
    NodoLista* actual = cima;
    pedidoMenosPrioritario = actual->pedido;
    return pedidoMenosPrioritario;
}
void Lista::limpiar() {
    NodoLista* actual = cima;
    while (actual) {
        NodoLista* siguiente = actual->siguiente;
        delete actual->pedido; // Liberar la memoria del pedido
        delete actual; // Liberar la memoria del nodo
        actual = siguiente;
    }
    cima = nullptr; // Establecer el puntero cima a nullptr para indicar que la lista está vacía
}
Lista::~Lista(){}

