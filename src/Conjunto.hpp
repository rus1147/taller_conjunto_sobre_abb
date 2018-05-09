
template <class T>
Conjunto<T>::Conjunto() {
    _raiz=NULL;

}

template <typename T>
void Conjunto<T>::limpiar(){
    Nodo* p=_raiz;
    while(p!=NULL){
        Nodo* q=p->der;
        Nodo* t=p->izq;
        delete p;
        p->der=q;
        p->izq=t;
    }
    _raiz=NULL;

}
template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    assert(false);
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {

}

template <class T>
void Conjunto<T>::remover(const T&) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::minimo() const {
    assert(false);
}

template <class T>
const T& Conjunto<T>::maximo() const {
    assert(false);
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {

}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

/*






 */