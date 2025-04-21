#ifndef ARBOLBB_HPP_INCLUDED
#define ARBOLBB_HPP_INCLUDED
template <typename T>
class ArbolBB{
public:
    /** \brief Constructor por defecto. Crea un a&acute;rbol vaci&acute;o.
     */
    ArbolBB();
    /** \brief Constructor de copia. Crea un nuevo a&acute;rbol copiando otro existente.
     * 
     * \param aBB a&acute;rbol a copiar.
     * 
     */
    ArbolBB(const ArbolBB<T> &aBB);
    //Operador =
    /** \brief Operador de asignacio&acute;n. Copia el contenido de un a&acute;rbol en otro.
     * 
     * \param aBB a&acute;rbol a copiar.
     * 
     * \return Referencia al a&acute;rbol copiado.
     */
    ArbolBB &operator=(const ArbolBB<T> &aBB);
    //Destructor
    /** \brief Destructor. Libera la memoria ocupada por el a&acute;rbol.
     * 
     * 
     * 
     */
    ~ArbolBB();
    //Agregar Nodo
    /** \brief Agrega un nuevo valor al a&acute;rbol.
     * 
     * \param v Valor a insertar.
     * 
     */
    void Agregar(T v);
    //Eliminar un nodo y sus hijos
    /** \brief Podar un nodo especi&acute;fico
     * 
     * \param v Valor del nodo a eliminar.
     * 
     */
    void Podar(T v);
    //Imprimir de manera ascendente
    /** \brief Imprime los valores del a&acute;rbol en orden ascendente.
     * 
     * 
     */
    void ImprimirAsc() const;
    //Imprimir de forma descendente
    /** \brief Imprime los valores del a&acute;rbol en orden descendente.
     * 
     * 
     */
    void ImprimirDes() const;
    //Vaciar
    /** \brief Vaci&acute;a el a&acute;rbol, eliminando todos los nodos.
     * 
     * 
     */
    void Vaciar();
    //Imprimir por niveles
    /** \brief Imprime el a&acute;rbol por niveles.
     * 
     * 
     */
    void ImprimirNivel() const;
    //Eliminar un nodo
    /** \brief Elimina un nodo del a&acute;rbol.
     * 
     * \param v Valor del nodo a eliminar.
     * 
     */
    void Eliminar(T v);
    //Obtener altura
    /** \brief Obtiene la altura del a&acute;rbol.
     * 
     * \return Altura del a&acute;rbol.
     * 
     */
    int ObtenerAltura() const;
    //Obtener mayor
    /** \brief Obtiene el mayor valor almacenado en el a&acute;rbol.
     * 
     * \return Mayor valor en el a&acute;rbol.
     * 
     */
    T ObtenerMayor();
    //Obtener menor
    /** \brief Obtiene el menor valor almacenado en el a&acute;rbol.
     * 
     * \return Menor valor en el a&acute;rbol.
     * 
     */
    T ObtenerMenor();
    //Obtener nu&acute;mero total de nodos
    /** \brief Obtiene el nu&acute;mero total de nodos en el a&acute;rbol.
     * 
     * \return Cantidad de nodos.
     * 
     */
    int ObtenerNumNodos() const;
    //Buscar nodos
    /** \brief Buscar si un valor especifico existe en el a&acute;rbol.
     * 
     * \param v Valor a buscar.
     * 
     * \return true si el valor esta&acute; en el a&acute;rbol, `false` en caso contrario.
     * 
     */
    bool BuscarNodo(T v);
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
    void DobleDer(Nodo *& subraiz);
    void DobleIzq(Nodo *& subraiz);

};

#include "ArbolBB.tpp"

#endif // ARBOLBB_HPP_INCLUDED
