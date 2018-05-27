#include "Conjunto.h"

template <class T>
Conjunto<T>::Nodo::~Nodo() {
    if(izq!=NULL){
        delete izq;
    }
    if(der!=NULL){
        delete der;
    }
}
template <class T>
Conjunto<T>::Conjunto() {
    _raiz=NULL;
}

template <class T>
Conjunto<T>::~Conjunto() {
    if(_raiz!=NULL){
        delete _raiz;
    }

}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const{
    Nodo* r=_raiz;
    while(r!=NULL && r->valor!=clave){
        if(r->valor>clave){
            r=r->izq;
        } else{
            r=r->der;
        }
    }
    return r->valor==clave;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    Nodo* p=_raiz;
    Nodo *m= insertar(p,clave);
    _raiz=m;
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo* p=_raiz;
    Nodo*m= eliminarNodo(p,clave);
    _raiz=m;
    /*
    if(pertenece(clave)){
        Nodo*q=buscar_Nodo(clave);
        //es hoja
        if(q->der==NULL && q->izq==NULL){
            delete q;
            _raiz=NULL;
        }//1 hoja
        if(q->der!=NULL){
            delete q->der;
        } else if(q->izq!=NULL){
            delete q->izq;
        } //2 hojas
        if(q->der!=NULL && q->izq!=NULL){
            if(q->der->valor>clave){
                Nodo*p=q->der->der;
                p->izq=q->izq;
                p->der=q->der;
                delete q;
            } else if((q->izq->valor <clave)){
                Nodo*p=q->izq->izq;
                p->der =q->der;
                p->izq=q->izq;
                delete q;
            }
        }
    }
     */
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo*p=_raiz;
    Nodo* n =minValNodo(p);
    return n->valor;
}
template <class T>
T Conjunto<T>::findMinimo(Nodo *raiz)const {
    //Caso Base
    if(raiz ==NULL){
        return NULL;
    } else {
        T res = raiz->valor;
        T lres=NULL;
        T rres=NULL;
        if(raiz->izq!=NULL) {
            lres = findMinimo(raiz->izq);
            if (lres < res) {
                res = lres;
            }
        }
        if(raiz->der!=NULL) {
             rres = findMinimo(raiz->der);
            if (rres < res) {
                res = rres;
            }
        }
        
        
        return res;
    }
}

template <class T>
const T& Conjunto<T>::maximo() const {
    assert(false);
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    Nodo* r1=_raiz;
    Nodo* r2=_raiz;
    int i=0;
    int j=0;
    if(r1!=NULL){
        j=1;
    while (r1->izq!=NULL){
        i=cardinal(r1->izq,i);
        r1=r1->izq;
        }
    
    while(r2->der!=NULL){
        j=cardinal(r2->der,j);
        r2=r2->der;
        }
    }
    return j+i;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

template <typename T>
void Conjunto<T>::limpiar(){
    Nodo* p=_raiz;
    while(p!=NULL){
        p=padre(minimo());
        if(p->der!=NULL){
            delete p->der;}
        if(p->izq!=NULL) {
            delete p->izq;
        }
        delete p;
    }
    _raiz=NULL;

}

template <typename T>
typename Conjunto<T>::Nodo* Conjunto<T>::buscar_Nodo(const T k){
    Nodo* r=_raiz;
    if(k==NULL){
        return NULL;
    } else{
    while(r!=NULL){
        if(r->valor!=k){
            if(r->valor>k){
                r=r->izq;
            } else{
                r=r->der;
            }
        } else{
            return r;
        }
    }}
    return r;
}
// C function to search a given key in a given BST
template <typename T>
typename Conjunto<T>::Nodo* Conjunto<T>:: search(Nodo* raiz, int key) {
    // Base Cases: root is null or key is present at root
    if (raiz == NULL || raiz->valor == key)
        return raiz;
    
    // Key is greater than root's key
    if (_raiz->valor < key)
        return search(raiz->der, key);
    
    // Key is smaller than root's key
    return search(raiz->izq, key);
}
template <typename T>
typename Conjunto<T>::Nodo* Conjunto<T>:: CrearNodo(  int clave) {
    {
        Nodo* n=new Nodo(clave);
        /*n->valor = clave;
        n->izq = NULL;
        n->der = NULL;*/
        return n;
    }
}

template <typename T>
typename Conjunto<T>::Nodo* Conjunto<T>:: insertar(Nodo *nodo,  int key) {
    /* If the tree is empty, return a new node */
    if (nodo == NULL){
        Nodo*n= new Nodo(key);
        nodo=n;
        return nodo;
    }
    /* Otherwise, recur down the tree */
    if (key < nodo->valor)
        nodo->izq  = insertar(nodo->izq, key);
    else if (key > nodo->valor)
        nodo->der = insertar(nodo->der, key);
    
    /* return the (unchanged) node pointer */
    return nodo;
}
template <typename T>
int Conjunto<T>:: cardinal(Nodo *nodo,int i)const {
    /* If the tree is empty, return a new node */
    if (nodo != NULL) {
        i++;
    /* Otherwise, recur down the tree */
    if (nodo->izq != NULL) {
         i = cardinal(nodo->izq,i);
    } else if (nodo->valor != NULL) {
     i = cardinal(nodo->der,i);
        }
    }
    /* return the (unchanged) node pointer */
    return i;
}
/*
template <typename T>
void Conjunto<T>::inorder(Nodo *raiz){
    if (raiz != NULL)
    {
        inorder(raiz->izq);
        inorder(raiz->der);
    }
}
*/
/*
template <typename T>
typename Conjunto<T>::Nodo* Conjunto<T>::buscar_valor_Nodo(const T& k){
    Nodo* r=_raiz;
    while(r!=NULL && r->valor!=k){
        if(r->valor>k){
            r=r->izq;
        } else{
            r=r->der;
        }
    }
    return r->valor;
}
 */
template <typename T>
typename Conjunto<T>::Nodo * Conjunto<T>:: padre(Nodo* q)const {
    Nodo* p=_raiz;
    Nodo* papa=0;
    
        while(p!=NULL){
            if(p->valor>q->valor){
                if(p->izq!=NULL){
                    papa=p;
                    p=p->izq;
                }
            } else if(p->valor<q->valor){
                if(p->der!=NULL){
                    papa=p;
                    p=p->der;
                }
            }
        }
    
    return papa;
}
template <typename T>
typename Conjunto<T>::Nodo * Conjunto<T>:: minValNodo(Nodo *nodo)const {
    Nodo *actual= nodo;
    while(actual->izq!=NULL){
        actual=actual->izq;
    }
    return actual;
}
template <typename T>
typename Conjunto<T>::Nodo* Conjunto<T>:: eliminarNodo(Nodo *raiz,int valor){
    //caso base
    if(raiz==NULL){
        return raiz;
    }
    if(valor<raiz->valor){
        raiz->izq=eliminarNodo(raiz->izq,valor);
    }else if(valor>raiz->valor){
        raiz->der=eliminarNodo(raiz->der,valor);
    } else{
        //nodo con un solo hijo
        if(raiz->izq==NULL){
            Nodo *n=raiz->der;
            free(raiz);
            return n;
        } else if(raiz->der==NULL){
            Nodo *n=raiz->izq;
            free(raiz);
            return n;
        }
        //Nodo con 2 hijos:buscar inorder al sucesor
        Nodo *n=minValNodo(raiz->der);
        //copia inorder
        raiz->valor=n->valor;
        //borra inorder al sucesor
        raiz->der=eliminarNodo(raiz->der,n->valor);
    }
    return raiz;
}