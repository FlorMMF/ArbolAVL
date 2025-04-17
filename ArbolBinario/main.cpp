#include <iostream>
#include "ArbolBB.hpp"
using namespace std;

int main()
{
    ArbolBB<double> arbol, copia;
    arbol.Agregar(17);
    arbol.Agregar(15);
    arbol.Agregar(14);
    arbol.Agregar(16);
    arbol.Agregar(-2);
    arbol.Agregar(15.5);
    arbol.Agregar(10);
    arbol.Agregar(0);
    arbol.Agregar(1);
    arbol.Agregar(5);
    arbol.Agregar(27);
    arbol.Agregar(23);
    arbol.Agregar(652);
    arbol.Agregar(40);
    arbol.Agregar(30);
    arbol.Agregar(50);
    arbol.Agregar(45);
    cout << "Antes de eliminar nodos:" << endl;
    arbol.ImprimirNivel();

    arbol.Eliminar(-2);
    arbol.Eliminar(0);

    cout << "Después de eliminar nodos:" << endl;
    arbol.ImprimirNivel();
 

//
//
//    cout << "Altura " << arbol.ObtenerAltura()<< endl;
//    cout  << "Mayor"<< arbol.ObtenerMayor()<< endl;
//    cout  << "Menor "<< arbol.ObtenerMenor()<< endl;
//
//    cout << "Buscar 44: " << (arbol.BuscarNodo(44) ? "Si esta" : "No esta") << endl;
    return 0;
}
