#include "Cola.hpp"
//PUBLICAS **********************************************************
template <typename T>
ArbolBB<T>::ArbolBB(): raiz(nullptr), numNodos(0){}

template <typename T>
ArbolBB<T>::ArbolBB(const ArbolBB<T> & aBB): raiz(nullptr), numNodos(0){
    *this = aBB;
}
template <typename T>
ArbolBB<T> & ArbolBB<T>::operator= (const  ArbolBB<T> &aBB){
    if(this == &aBB) return *this;
    Vaciar();
    //codigo codigo codigo codigo codigo
    Cola <Nodo *> cola;
    Nodo * aux = aBB.raiz;
    if(aux != nullptr){
        cola.Encolar(aux);
        while(!cola.EstaVacia()){
            if(cola.ObtenerPrimero() -> hijoIzq != nullptr){
                cola.Encolar(cola.ObtenerPrimero() -> hijoIzq);
            }
            if(cola.ObtenerPrimero() -> hijoDer != nullptr){
                cola.Encolar(cola.ObtenerPrimero() -> hijoDer);
            }
             Agregar(cola.ObtenerPrimero() -> valor);
            cola.Desencolar();
        }


    }
    return *this;
}

template <typename T>
ArbolBB<T>::~ArbolBB(){
    Vaciar();
}

template <typename T>
void ArbolBB<T>::Agregar(T v){
    Agregar(v,raiz);
}

template <typename T>
void ArbolBB<T>::Podar(T v){
    Nodo *& dirNodo = BuscarDir(v, raiz);
    Podar(dirNodo);

}

template <typename T>
void ArbolBB<T>::ImprimirAsc()const{
    ImprimirAsc(raiz);
}

template <typename T>
void ArbolBB<T>:: ImprimirDes()const{
    ImprimirDes(raiz);
}

template <typename T>
void ArbolBB<T>:: Vaciar(){
    Podar(raiz);
}

template <typename T>
void ArbolBB<T>::ImprimirNivel()const{
    ImprimirNivel(raiz);
}

template <typename T>
void ArbolBB<T>::Eliminar(T v){
    Eliminar(v, raiz);
}

template <typename T>
int ArbolBB<T>::ObtenerAltura()const{
    return ObtenerAltura(raiz);
}

 template <typename T>
T ArbolBB<T>::ObtenerMayor(){
    return BuscarMayor(raiz)-> valor;
}

 template <typename T>
T ArbolBB<T>::ObtenerMenor(){
    return BuscarMenor(raiz)-> valor;
}

 template <typename T>
int ArbolBB<T>::ObtenerNumNodos() const{
    return numNodos;
}

template <typename T>
bool ArbolBB<T>::BuscarNodo(T v) {
    return(BuscarDir(v,raiz) != nullptr);
}
//**************************************************************
//***********************************************
//PRIVADAS ***********************************************************************************************
template <typename T>
void ArbolBB<T>::Agregar(T v, Nodo * & subraiz){
    if(subraiz == nullptr){
        subraiz = new Nodo (v);
        ++ numNodos;
    }else if(v == subraiz -> valor){
        return;
    }else if(v <  subraiz -> valor ){
        Agregar(v, subraiz  -> hijoIzq);
        subraiz -> Equilibrio = ObtenerAltura(subraiz -> hijoDer) - ObtenerAltura(subraiz -> hijoIzq);
    }else {
        Agregar(v, subraiz  -> hijoDer);
        subraiz -> Equilibrio = ObtenerAltura(subraiz -> hijoDer) - ObtenerAltura(subraiz -> hijoIzq);
    }
    if(subraiz -> Equilibrio > 1 || subraiz -> Equilibrio < -1){
        Equilibrar(subraiz);
    }
}




template <typename T>
void ArbolBB<T>::ImprimirAsc(Nodo * subraiz)const{
    if(subraiz != nullptr){
        ImprimirAsc(subraiz -> hijoIzq);
        std::cout << subraiz -> valor << std::endl;
        ImprimirAsc(subraiz -> hijoDer);

    }
}



template <typename T>
void ArbolBB<T>:: ImprimirDes(Nodo * subraiz)const{
    if(subraiz != nullptr){
        ImprimirDes(subraiz -> hijoDer);
        std::cout << subraiz -> valor << std::endl;
        ImprimirDes(subraiz -> hijoIzq);

    }
}



template <typename T>
void ArbolBB<T>::Podar(Nodo *& subraiz){
    if(subraiz != nullptr){
        Podar(subraiz -> hijoIzq);
        Podar(subraiz -> hijoDer);
        delete subraiz;
        subraiz = nullptr;
        --numNodos;
    }
}

template <typename T>
typename  ArbolBB<T>::Nodo *& ArbolBB<T>::BuscarDir(T v, Nodo *& subraiz)const{
    if(subraiz != nullptr){
        if(v < subraiz -> valor)return BuscarDir(v, subraiz -> hijoIzq );
        else if(v > subraiz -> valor)return BuscarDir(v, subraiz -> hijoDer);

    }
    return subraiz;
}

template <typename T>
void ArbolBB<T>::ImprimirNivel(Nodo * subraiz)const{
    Cola <Nodo *> cola;
    if(subraiz != nullptr){
        cola.Encolar(subraiz);
        while(!cola.EstaVacia()){
            if(cola.ObtenerPrimero() -> hijoIzq != nullptr){
                cola.Encolar(cola.ObtenerPrimero() -> hijoIzq);
            }
            if(cola.ObtenerPrimero() -> hijoDer != nullptr){
                cola.Encolar(cola.ObtenerPrimero() -> hijoDer);
            }
            std::cout << cola.ObtenerPrimero() -> valor << std::endl;
            cola.Desencolar();
        }


    }
    std::cout << std::endl;
}

template <typename T>
void ArbolBB<T>::Eliminar(T v, Nodo *& subraiz){
    if( (BuscarDir(v,subraiz) == nullptr) || (subraiz == nullptr) )return;
    if(subraiz -> valor == v){
        if( (subraiz -> hijoIzq == nullptr) && (subraiz -> hijoDer == nullptr)){
            Nodo * porBorrar = subraiz;
            subraiz = nullptr;
            delete porBorrar;
            --numNodos;
        }else if((subraiz -> hijoDer == nullptr)){
            Nodo * porBorrar = subraiz;
            subraiz = subraiz -> hijoIzq;
            delete porBorrar;
            --numNodos;
        }else if((subraiz -> hijoIzq == nullptr)){
            Nodo * porBorrar = subraiz;
            subraiz = subraiz -> hijoDer;
            delete porBorrar;
            --numNodos;
        }else{
        //cuando tiene dos hijos
            Nodo *& dirMayorMenor = BuscarMayor(subraiz -> hijoIzq);
            subraiz -> valor = dirMayorMenor -> valor;
            Eliminar(dirMayorMenor-> valor, dirMayorMenor);
            subraiz -> Equilibrio = ObtenerAltura(subraiz -> hijoDer) - ObtenerAltura(subraiz -> hijoIzq);
        }

    }else{
        if(subraiz -> valor > v){
            Eliminar(v, subraiz -> hijoIzq);
            subraiz -> Equilibrio = ObtenerAltura(subraiz -> hijoDer) - ObtenerAltura(subraiz -> hijoIzq);
        }else{
            Eliminar(v, subraiz -> hijoDer);
            subraiz -> Equilibrio = ObtenerAltura(subraiz -> hijoDer) - ObtenerAltura(subraiz -> hijoIzq);
        }
    }
    if(subraiz != nullptr){
        if(subraiz -> Equilibrio > 1 || subraiz -> Equilibrio < -1){
        Equilibrar(subraiz);
    }
    }

}

template <typename T>
typename  ArbolBB<T>::Nodo *& ArbolBB<T>::BuscarMayor(Nodo *& subraiz) const{
    if(subraiz == nullptr)throw ("Algo ha fallado buscando el mayor");
    if(subraiz -> hijoDer == nullptr){
       return subraiz;

    }
    return BuscarMayor(subraiz ->hijoDer);
}

template <typename T>
typename  ArbolBB<T>::Nodo *& ArbolBB<T>::BuscarMenor(Nodo *& subraiz) const{
    if(subraiz == nullptr)throw ("Algo ha fallado buscando el menor");
    if(subraiz -> hijoIzq == nullptr){
       return subraiz;

    }
    return BuscarMenor(subraiz ->hijoIzq);
}

template <typename T>
int ArbolBB<T>::ObtenerAltura(Nodo * subraiz)const{
    if( subraiz  == nullptr )return 0;
    return std::max(ObtenerAltura(subraiz -> hijoIzq),ObtenerAltura(subraiz -> hijoDer)) +1;

}

template <typename T>
void ArbolBB<T>::Equilibrar(Nodo *& subraiz){
    if(subraiz -> Equilibrio > 1){
        if(subraiz -> hijoDer -> Equilibrio == -1){
            SimpleDer(subraiz -> hijoDer);
        }
        SimpleIzq(subraiz);
    }else{
        if(subraiz -> hijoIzq -> Equilibrio == 1){
            SimpleIzq(subraiz -> hijoIzq);
        }
        SimpleDer(subraiz);
    }
}

template <typename T>
void ArbolBB<T>:: SimpleDer(Nodo *& subraiz){
    Nodo * aux = subraiz;
    subraiz = subraiz -> hijoIzq;
    aux -> hijoIzq = subraiz -> hijoDer;
    subraiz -> hijoDer = aux;

    subraiz -> hijoDer ->Equilibrio = ObtenerAltura(subraiz -> hijoDer -> hijoDer) - ObtenerAltura(subraiz -> hijoDer -> hijoIzq);
    subraiz ->Equilibrio = ObtenerAltura(subraiz -> hijoDer) - ObtenerAltura(subraiz -> hijoIzq);

}


template <typename T>
void ArbolBB<T>::SimpleIzq(Nodo *& subraiz){
    Nodo * aux = subraiz;
    subraiz = subraiz -> hijoDer;
    aux -> hijoDer = subraiz -> hijoIzq;
    subraiz -> hijoIzq = aux;

    subraiz -> hijoIzq ->Equilibrio = ObtenerAltura(subraiz -> hijoIzq-> hijoDer) - ObtenerAltura(subraiz -> hijoIzq-> hijoIzq);;
    subraiz ->Equilibrio = ObtenerAltura(subraiz -> hijoDer) - ObtenerAltura(subraiz -> hijoIzq);;
}


