#include "Gestor.hpp"
Gestor::Gestor() {
    srand(time(nullptr));
}
int Gestor::PedidosEnPila(/*pilaPedidos*/){
    return pila.longitud();
}
int Gestor::PedidosEnSalaA(){
    return estacionA.longitud();
}
int Gestor::PedidosEnSalaB(){
    return estacionB.longitud();
}
int Gestor::PedidosEnSalaC(){
    return estacionC.longitud();
}
int Gestor::PedidosEnSalaD(){
    return estacionD.longitud();
}
int Gestor::PedidosEnListaEstandar(){
    return listaEstandar.longitud();
}
int Gestor::PedidosEnListaUrgentes(){
    return listaUrgente.longitud();
}
void Gestor::generar12PedidosAleatorios(/*pilaPedidos*/) {
    for (int i = 0; i < 12; i++) {
        if (pila.longitud() >= 48) {
            // Si ya hay 48 pedidos en la pila, sigue generando pero no los agregues.
            break;
        }

        bool esUrgente = rand() % 2 == 1;
        int id, seguimiento;
        std::string dni;

        if (esUrgente) {
            id = 51 + (rand() % 49);
            seguimiento = 501 + (rand() % 499);
        } else {
            id = 1 + (rand() % 49);
            seguimiento = 1 + (rand() % 499);
        }
        // Genera un número de DNI aleatorio de 8 dígitos
        std::string numeroDNI;
        for (int j = 0; j < 8; j++) {
            int digito = rand() % 10;
            numeroDNI += std::to_string(digito);
        }

        // Genera una letra aleatoria (A-Z)
        char letraDNI = 'A' + rand() % 26;

        dni = numeroDNI + letraDNI;
        Pedido* nuevoPedido = new Pedido(id, seguimiento, dni, esUrgente);
        pila.push(nuevoPedido);
	}
}

void Gestor::muestraPedidos(/*pilaPedidos*/) {
    Pila pilaTemporal; // Crear una pila temporal para mostrar los pedidos sin borrarlos
    while (!pila.estaVacia()) {
        Pedido* pedido = pila.pop();
        std::cout << "El pedido a nombre del titular con DNI "<< pedido->getDNI()
        << " es de caracter " << (pedido->esUrgente() ? "urgente" : "estandar") << std::endl;
        pilaTemporal.push(pedido); // Agregar el pedido a la pila temporal
    }

    // Ahora, restaurar los pedidos a la pila original en su orden original
    while (!pilaTemporal.estaVacia()) {
        Pedido* pedido = pilaTemporal.pop();
        pila.push(pedido);
	}
}
void Gestor::borraPedidosPila(/*pilaPedidos*/){
    while (!pila.estaVacia()) {
        pila.pop();
    }
}

void Gestor::encolarPedidos(/*pilaPedidos*/) {
    while (!pila.estaVacia()) {
        Pedido* pedido = pila.pop();
        Cola* estacion = nullptr;
        if (pedido->esUrgente()) {
            if (estacionC.estaVacia() || (estacionC.longitud() <= estacionD.longitud())) {
                estacion = &estacionC;
            } else {
                estacion = &estacionD;
            }
        } else {
            if (estacionA.estaVacia() || (estacionA.longitud() <= estacionB.longitud())) {
                estacion = &estacionA;
            } else {
                estacion = &estacionB;
            }
        }
        estacion->encolar(pedido);
    }
}

void Gestor::muestraPedidosSalasAyB(){
    //Sala A
    Cola tempEstacionA;
    std::cout << " Sala A: " << std::endl;
    while (!estacionA.estaVacia()) {
        Pedido* pedido = estacionA.desencolar();
        std::cout << "El pedido a nombre del titular con DNI "<< pedido->getDNI()
        << " es de caracter " << (pedido->esUrgente() ? "urgente" : "estandar") << ", su ID es: " << pedido->getID() <<" y su numero de seguimiento asignado es: "<< pedido->getSeguimiento() << std::endl;
        // Volver a encolar el pedido en la copia temporal de la estación
        tempEstacionA.encolar(pedido);
    }
    // Restaurar la estación original
    while (!tempEstacionA.estaVacia()) {
        Pedido* pedido = tempEstacionA.desencolar();
        estacionA.encolar(pedido);
    }
    //Sala B
    Cola tempEstacionB; 
    std::cout << " Sala B: " << std::endl;
    // Mostrar el contenido de la estación sin modificarla
    while (!estacionB.estaVacia()) {
        Pedido* pedido = estacionB.desencolar();
        std::cout << "El pedido a nombre del titular con DNI "<< pedido->getDNI()
        << " es de caracter " << (pedido->esUrgente() ? "urgente" : "estandar") << ", su ID es: " << pedido->getID() <<" y su numero de seguimiento asignado es: "<< pedido->getSeguimiento() << std::endl;
        // Volver a encolar el pedido en la copia temporal de la estación
        tempEstacionB.encolar(pedido);
    }

    // Restaurar la estación original
    while (!tempEstacionB.estaVacia()) {
        Pedido* pedido = tempEstacionB.desencolar();
        estacionB.encolar(pedido);
    }
}
void Gestor::muestraPedidosSalasCyD(){
    //Sala C
    Cola tempEstacionC;
    std::cout << " Sala C: " << std::endl;
    while (!estacionC.estaVacia()) {
        Pedido* pedido = estacionC.desencolar();
        std::cout << "El pedido a nombre del titular con DNI "<< pedido->getDNI()
        << " es de caracter " << (pedido->esUrgente() ? "urgente" : "estandar") << ", su ID es: " << pedido->getID() <<" y su numero de seguimiento asignado es: "<< pedido->getSeguimiento() << std::endl;
        // Volver a encolar el pedido en la copia temporal de la estación
        tempEstacionC.encolar(pedido);
    }
    // Restaurar la estación original
    while (!tempEstacionC.estaVacia()) {
        Pedido* pedido = tempEstacionC.desencolar();
        estacionC.encolar(pedido);
    }
    //Sala D
    Cola tempEstacionD; 
    std::cout << " Sala D: " << std::endl;
    // Mostrar el contenido de la estación sin modificarla
    while (!estacionD.estaVacia()) {
        Pedido* pedido = estacionD.desencolar();
        std::cout << "El pedido a nombre del titular con DNI "<< pedido->getDNI()
        << " es de caracter " << (pedido->esUrgente() ? "urgente" : "estandar") << ", su ID es: " << pedido->getID() <<" y su numero de seguimiento asignado es: "<< pedido->getSeguimiento() << std::endl;
        // Volver a encolar el pedido en la copia temporal de la estación
        tempEstacionD.encolar(pedido);
    }

    // Restaurar la estación original
    while (!tempEstacionD.estaVacia()) {
        Pedido* pedido = tempEstacionD.desencolar();
        estacionD.encolar(pedido);
    }
}
void Gestor::borraPedidosColas(){
while (!estacionA.estaVacia()) {
        Pedido* pedido = estacionA.desencolar();
        delete pedido; // Liberar la memoria asignada a cada pedido
    }
    
    while (!estacionB.estaVacia()) {
        Pedido* pedido = estacionB.desencolar();
        delete pedido; // Liberar la memoria asignada a cada pedido
    }
    
    while (!estacionC.estaVacia()) {
        Pedido* pedido = estacionC.desencolar();
        delete pedido; // Liberar la memoria asignada a cada pedido
    }
    
    while (!estacionD.estaVacia()) {
        Pedido* pedido = estacionD.desencolar();
        delete pedido; // Liberar la memoria asignada a cada pedido
    }
}
void Gestor::enlistarPedidos() {
    while (!estacionA.estaVacia()) {
        Pedido* pedido = estacionA.desencolar();
        listaEstandar.insertarEnOrden(pedido);
    }
    while (!estacionB.estaVacia()) {
        Pedido* pedido = estacionB.desencolar();
        listaEstandar.insertarEnOrden(pedido);
    }
    while (!estacionC.estaVacia()) {
        Pedido* pedido = estacionC.desencolar();
        listaUrgente.insertarEnOrden(pedido);
    }
    while (!estacionD.estaVacia()) {
        Pedido* pedido = estacionD.desencolar();
        listaUrgente.insertarEnOrden(pedido);
    }
}
void Gestor::muestraPedidosEstandar(){
    std::cout << "Pedidos en la Lista Estandar:" << std::endl;
    listaEstandar.mostrarPedidos(listaEstandar);
}

void Gestor::muestraPedidosUrgentes(){
    std::cout << "Pedidos en la Lista Urgente:" << std::endl;
    listaUrgente.mostrarPedidos(listaUrgente);
}
void Gestor::buscarPedidos() {
    Pedido* pedidoEstandarPrioritario = listaEstandar.encontrarPedidoEstandarPrioritario();
    Pedido* pedidoUrgenteMenosPrioritario = listaUrgente.encontrarPedidoUrgenteMenosPrioritario();

    if (pedidoEstandarPrioritario) {
        std::cout << "EL pedido estandar de mayor prioridad: \n" << "El pedido a nombre del titular con DNI "<< pedidoEstandarPrioritario->getDNI()
        << " es de caracter " << (pedidoEstandarPrioritario->esUrgente() ? "urgente" : "estandar") << ", su ID es: " << pedidoEstandarPrioritario->getID() <<" y su numero de seguimiento asignado es: "<< pedidoEstandarPrioritario->getSeguimiento() << std::endl;
    } else {
        std::cout << "No hay pedidos estandar en la lista." << std::endl;
    }

    if (pedidoUrgenteMenosPrioritario) {
        std::cout << "El pedido urgente de menor prioridad: \n" << "El pedido a nombre del titular con DNI "<< pedidoUrgenteMenosPrioritario->getDNI()
        << " es de caracter " << (pedidoUrgenteMenosPrioritario->esUrgente() ? "urgente" : "estandar") << ", su ID es: " << pedidoUrgenteMenosPrioritario->getID() <<" y su numero de seguimiento asignado es: "<< pedidoUrgenteMenosPrioritario->getSeguimiento() << std::endl;
    } else {
        std::cout << "No hay pedidos urgentes en la lista." << std::endl;
    }
}
void Gestor::reiniciar() {
    // Eliminar todos los pedidos en las estaciones A y B
    while (!estacionA.estaVacia()) {
        delete estacionA.desencolar();
    }
    while (!estacionB.estaVacia()) {
        delete estacionB.desencolar();
    }
    // Eliminar todos los pedidos en las estaciones C y D
    while (!estacionC.estaVacia()) {
        delete estacionC.desencolar();
    }
    while (!estacionD.estaVacia()) {
        delete estacionD.desencolar();
    }
    while (!listaEstandar.estaVacia()) {
        Pedido* pedido = listaEstandar.pop();
        pedido->reiniciarNumeroSeguimiento();
    }
    while (!listaUrgente.estaVacia()) {
        Pedido* pedido = listaUrgente.pop();
        pedido->reiniciarNumeroSeguimiento();
    }    
    // Eliminar todos los pedidos en las listas de pedidos
    listaEstandar.limpiar();
    listaUrgente.limpiar();
    std::cout << "El programa ha sido reiniciado a su estado inicial." << std::endl;
}
Gestor::~Gestor(){
}

