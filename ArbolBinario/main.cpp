#include <iostream>
#include "ArbolBB.hpp"
using namespace std;

int main()
{
    ArbolBB<double> arbol, copia;
    cout << "Insertando valores." << endl;
    arbol.Agregar(30);
    arbol.Agregar(10);
    arbol.Agregar(40.23);
    arbol.Agregar(5.5);
    arbol.Agregar(0);
    arbol.Agregar(35);
    arbol.Agregar(50);
    arbol.Agregar(-15);
    arbol.Agregar(25);
    arbol.ImprimirNivel();
    
    cout << "Busqueda de valores." << endl;
    cout << "¿Est\240 30 en el \240rbol?: " << (arbol.BuscarNodo(30) ? "S\241" : "No") << endl;
    cout << "¿Est\240 100 en el \240rbol?: " << (arbol.BuscarNodo(100) ? "S\241" : "No") << endl;
    
    cout << "\nEliminaci\242n de valores." << endl;
    arbol.Eliminar(5);
    arbol.Eliminar(25);
    arbol.ImprimirNivel();

    cout << "Altura del \240rbol." << endl;
    cout << "Altura: " << arbol.ObtenerAltura() << endl;

    cout << "\nValor mayor y menor del \240rbol." << endl;
    cout << "Mayor valor: " << arbol.ObtenerMayor() << endl;
    cout << "Menor valor: " << arbol.ObtenerMenor() << endl;

    cout << "\nImpresi\242n en orden ascendente." << endl;
    arbol.ImprimirAsc();

    cout << "\nImpresi\242n en orden descendente." << endl;
    arbol.ImprimirDes();

    cout << "\nIntenando vaciar el \240rbol" << endl;
    arbol.Vaciar();
    cout << "Nodos despu\202s de vaciar: " << arbol.ObtenerNumNodos() << endl;

    return 0;
}
