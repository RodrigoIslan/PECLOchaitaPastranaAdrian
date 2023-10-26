#ifndef GESTOR_HPP
#define GESTOR_HPP
#include <cstdlib>
#include <ctime>
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
using namespace std;
class Gestor {
public:
    Gestor();
    ~Gestor();
    int PedidosEnPila(/*pilaPedidos*/);
    int PedidosEnSalaA();
    int PedidosEnSalaB();
    int PedidosEnSalaC();
    int PedidosEnSalaD();
    int PedidosEnListaEstandar();
    int PedidosEnListaUrgentes();
    void generar12PedidosAleatorios(/*pilaPedidos*/);
    void muestraPedidos(/*pilaPedidos*/);
    void borraPedidosPila(/*pilaPedidos*/);
    void encolarPedidos(/*pilaPedidos*/);
    void muestraPedidosSalasAyB();
    void muestraPedidosSalasCyD();
    void borraPedidosColas();
    void enlistarPedidos();
    void muestraPedidosEstandar();
    void muestraPedidosUrgentes();
    void buscarPedidos(); 
    void reiniciar();
private:
    Cola estacionA;
    Cola estacionB;
    Cola estacionC;
    Cola estacionD;
    Lista listaEstandar;
    Lista listaUrgente;
	Pila pila;
};

#endif // GESTOR_HPP


