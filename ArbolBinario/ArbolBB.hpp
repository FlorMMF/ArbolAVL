#ifndef ARBOLBB_HPP_INCLUDED
#define ARBOLBB_HPP_INCLUDED


template <typename T>
class ArbolBB{
public:
    ArbolBB();
    ArbolBB(const ArbolBB<T> & aBB);

    ArbolBB & operator= (const  ArbolBB<T> &aBB);
    ~ArbolBB();
    void Agregar(T v);
    void Podar(T v);
    void ImprimirAsc()const;
    void ImprimirDes()const;
    void Vaciar();
    void ImprimirNivel()const;
    void Eliminar(T v);
    int ObtenerAltura()const;
    T ObtenerMayor();
    T ObtenerMenor() ;
    int ObtenerNumNodos() const;
    bool BuscarNodo(T v) ;

private:
    struct Nodo{
        T valor;
        int Equilibrio;
        Nodo * hijoIzq, * hijoDer;
        Nodo(T v, Nodo * hIzq= nullptr, Nodo * hDer=nullptr, int Equi= 0):
            valor(v), hijoIzq(hIzq),hijoDer(hDer),Equilibrio(Equi) {}
    }* raiz;
    int numNodos;

    void Agregar(T v, Nodo *& subraiz);
    void ImprimirAsc(Nodo * subraiz)const;
    void ImprimirDes(Nodo * subraiz)const;
    void Podar(Nodo *& subraiz);
    Nodo *& BuscarDir(T v, Nodo *& subraiz)const;
    void ImprimirNivel(Nodo * subraiz)const;
    void Eliminar(T v, Nodo * &subraiz);
    Nodo *& BuscarMayor(Nodo *& subraiz) const;
    Nodo *& BuscarMenor(Nodo *& subraiz) const;
    int ObtenerAltura(Nodo * subraiz)const;
    void Equilibrar(Nodo *& subraiz);
    void SimpleDer(Nodo *& subraiz);
    void SimpleIzq(Nodo *& subraiz);

};

#include "ArbolBB.tpp"

#endif // ARBOLBB_HPP_INCLUDED
