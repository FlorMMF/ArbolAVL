#ifndef ARBOLBB_HPP_INCLUDED
#define ARBOLBB_HPP_INCLUDED
template <typename T>
class ArbolBB{
public:
    /** \brief Constructor por defecto. Crea un &aacute;rbol vac&iacute;o.
     */
    ArbolBB();
    /** \brief Constructor de copia. Crea un nuevo &aacute;rbol copiando otro existente.
     * 
     * \param aBB &aacute;rbol a copiar.
     * 
     */
    ArbolBB(const ArbolBB<T> &aBB);
    //Operador =
    /** \brief Operador de asignacio&aacute;n. Copia el contenido de un &aacute;rbol en otro.
     * 
     * \param aBB &aacute;rbol a copiar.
     * 
     * \return Referencia al &aacute;rbol copiado.
     */
    ArbolBB &operator=(const ArbolBB<T> &aBB);
    //Destructor
    /** \brief Destructor. Libera la memoria ocupada por el &aacute;rbol.
     * 
     * 
     * 
     */
    ~ArbolBB();
    //Agregar Nodo
    /** \brief Agrega un nuevo valor al &aacute;rbol.
     * 
     * \param v Valor a insertar.
     * 
     */
    void Agregar(T v);
    //Eliminar un nodo y sus hijos
    /** \brief Podar un nodo espec&iacute;fico
     * 
     * \param v Valor del nodo a eliminar.
     * 
     */
    void Podar(T v);
    //Imprimir de manera ascendente
    /** \brief Imprime los valores del &aacute;rbol en orden ascendente.
     * 
     * 
     */
    void ImprimirAsc() const;
    //Imprimir de forma descendente
    /** \brief Imprime los valores del &aacute;rbol en orden descendente.
     * 
     * 
     */
    void ImprimirDes() const;
    //Vaciar
    /** \brief Vac&iacute;a el &aacute;rbol, eliminando todos los nodos.
     * 
     * 
     */
    void Vaciar();
    //Imprimir por niveles
    /** \brief Imprime el &aacute;rbol por niveles.
     * 
     * 
     */
    void ImprimirNivel() const;
    //Eliminar un nodo
    /** \brief Elimina un nodo del &aacute;rbol.
     * 
     * \param v Valor del nodo a eliminar.
     * 
     */
    void Eliminar(T v);
    //Obtener altura
    /** \brief Obtiene la altura del &aacute;rbol.
     * 
     * \return Altura del &aacute;rbol.
     * 
     */
    int ObtenerAltura() const;
    //Obtener mayor
    /** \brief Obtiene el mayor valor almacenado en el &aacute;rbol.
     * 
     * \return Mayor valor en el &aacute;rbol.
     * 
     */
    T ObtenerMayor();
    //Obtener menor
    /** \brief Obtiene el menor valor almacenado en el &aacute;rbol.
     * 
     * \return Menor valor en el &aacute;rbol.
     * 
     */
    T ObtenerMenor();
    //Obtener nu&aacute;mero total de nodos
    /** \brief Obtiene el nu&aacute;mero total de nodos en el &aacute;rbol.
     * 
     * \return Cantidad de nodos.
     * 
     */
    int ObtenerNumNodos() const;
    //Buscar nodos
    /** \brief Buscar si un valor especifico existe en el &aacute;rbol.
     * 
     * \param v Valor a buscar.
     * 
     * \return true si el valor est&aacute; en el &aacute;rbol, false en caso contrario.
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
    //Agregar valor
    /** \brief Inserta un nuevo valor en el &aacute;rbol de forma recursiva.
     *
     * \param v Valor a insertar.
     *
     * \param subraiz Referencia al nodo actual.
     *
     */
     void Agregar(T v, Nodo *&subraiz);
    //Imprimir de forma ascendente
     /** \brief Imprime los valores en orden ascendente de forma recursiva.
      *
      * \param subraiz Nodo ra&iacute;z de la sub&aacute;rbol actual.
      *
      */
     void ImprimirAsc(Nodo *subraiz) const;
    //Imprimir de forma descendente
     /** \brief Imprime los valores en orden descendente de forma recursiva.
      *
      * \param subraiz Nodo ra&iacute;z del sub&aacute;rbol actual.
      *
      */
     void ImprimirDes(Nodo *subraiz) const;
    //Eliminar nodo y todos sus hijos
     /** \brief Elimina todos los nodos del sub&aacute;rbol actual.
      *
      * \param subraiz Referencia al nodo actual.
      *
      */
     void Podar(Nodo *&subraiz);
    //Buscar direcci&ocute;n
     /** \brief Busca la direcci&ocute;n del nodo con un valor espec&iacute;fico en el &aacute;rbol.
      * 
      * \param v Valor a buscar.
      * 
      * \param subraiz Nodo actual.
      *
      * \return Referencia al nodo encontrado o `nullptr` si no existe.
      */
     Nodo *&BuscarDir(T v, Nodo *&subraiz) const;
    //Imprimir por niveles
     /** \brief Imprime el &aacute;rbol por niveles utilizando una cola.
      *
      * \param subraiz Nodo ra&iacute;z actual.
      *
      */
     void ImprimirNivel(Nodo *subraiz) const;
    //Eliminar nodo
     /** \brief Elimina un nodo del &aacute;rbol, reorganizando la estructura si es necesario.
      *
      * \param v Valor del nodo a eliminar.
      *
      * \param subraiz Referencia al nodo actual.
      *
      */
     void Eliminar(T v, Nodo *&subraiz);
    //Buscar mayor
     /** \brief Obtiene el nodo con el mayor valor dentro de un sub&aacute;rbol.
      *
      * \param subraiz Referencia al nodo actual.
      *
      * \return Referencia al nodo con el mayor valor.
      *
      */
     Nodo *&BuscarMayor(Nodo *&subraiz) const;
    //Buscar menor
     /** \brief Obtiene el nodo con el menor valor dentro de un sub&aacute;rbol.
      *
      * \param subraiz Referencia al nodo actual.
      *
      * \return Referencia al nodo con el menor valor.
      *
      */
     Nodo *&BuscarMenor(Nodo *&subraiz) const;
    //Obtener altura
     /** \brief Obtiene la altura de un sub&aacute;rbol de forma recursiva.
      *
      * \param subraiz Nodo actual.
      *
      * \return Altura del sub&aacute;rbol.
      *
      */
     int ObtenerAltura(Nodo *subraiz) const;
    //Balanceo del &aacute;rbol
     /** \brief Reequilibra un sub&aacute;rbol si existe un desbalance.
      *
      * \param subraiz Nodo ra&iacute;z del sub&aacute;rbol desbalanceado.
      *
      */
     void Equilibrar(Nodo *&subraiz);
    //Rotaci&ocute;n simple a la derecha
     /** \brief Realiza una rotaci&ocute;n simple hacia la derecha en un sub&aacute;rbol.
      *
      * \param subraiz Nodo ra&iacute;z del sub&aacute;rbol.
      *
      */
     void SimpleDer(Nodo *&subraiz);
    //Rotaci&ocute;n simple a la izquierda
     /** \brief Realiza una rotaci&ocute;n simple hacia la izquierda en un sub&aacute;rbol.
      *
      * \param subraiz Nodo ra&iacute;z del sub&aacute;rbol.
      *
      */
     void SimpleIzq(Nodo *&subraiz);
    //Rotaci&ocute;n doble a la izquierda
     /** \brief Realiza una rotaci&ocute;n doble hacia la izquierda en un sub&aacute;rbol.
      *
      * \param subraiz Nodo ra&iacute;z del sub&aacute;rbol.
      *
      */
     void DobleIzq(Nodo *&subraiz);
    //Rotaci&ocute;n doble a la derecha
     /** \brief Realiza una rotaci&ocute;n doble hacia la derecha en un sub&aacute;rbol.
      *
      * \param subraiz Nodo ra&iacute;z del sub&aacute;rbol.
      *
      */
     void DobleDer(Nodo *&subraiz);

};

#include "ArbolBB.tpp"

#endif // ARBOLBB_HPP_INCLUDED
