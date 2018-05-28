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
    if(_raiz!=NULL)
        delete _raiz;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const{
    return pertenece(buscar_Nodo(clave),clave);
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
    Nodo *m=siguienteInorder(_raiz,buscar_Nodo(clave));
    return m->valor;
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
    Nodo*p=_raiz;
    Nodo* n =maxValNodo(p);
    return n->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() {
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
typename Conjunto<T>::Nodo * Conjunto<T>::buscar_Nodo(const T k)const {
    Nodo* r=_raiz;
    if(_raiz==NULL){
        return NULL;
    }else if(_raiz!=NULL){
    if(k==0){
        return _raiz;
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
}}
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
typename Conjunto<T>::Nodo* Conjunto<T>:: insertar(Nodo *nodo,  int key) {
    /* If the tree is empty, return a new node */
    if (nodo == NULL){
        Nodo*n= new Nodo(key);
        nodo=n;
        return nodo;
    }
    /* Otherwise, recur down the tree */
    if (key < nodo->valor){
        Nodo*n= insertar(nodo->izq, key);
        nodo->izq  = n;
        n->padre=nodo;
    }
    else if (key > nodo->valor) {
        Nodo *n=insertar(nodo->der, key);
        nodo->der = n;
        n->padre=nodo;
    }
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
    } else if (nodo->der != NULL) {
     i = cardinal(nodo->der,i);
        }
    }
    /* return the (unchanged) node pointer */
    return i;
}
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
template <typename T>
typename Conjunto<T>::Nodo* Conjunto<T>:: buscarSiguiente(Nodo *nodo,  int clave) {
    /* If the tree is empty, return a new node */
    if(nodo->valor==clave && nodo->izq!=NULL && nodo->der!=NULL){
        buscarSiguiente(nodo->der,clave);
    }else{
    if(nodo->izq!=NULL && clave<nodo->valor){
        if(nodo->izq->der!=NULL){
        return buscarSiguiente(nodo->der,clave);} else{
            return nodo->izq;
        }
    } else if(nodo->der!=NULL && clave<nodo->valor){
        if(nodo->izq->der!=NULL){
            return buscarSiguiente(nodo->der,clave);} else{
            return nodo->izq;
        }
    }}
    /* Otherwise, recur down the tree
    if (clave < nodo->valor)
        nodo->izq  = insertar(nodo->izq, key);
    else if (key > nodo->valor)
        nodo->der = insertar(nodo->der, key);
    
    return the (unchanged) node pointer */
}
template <typename T>
typename Conjunto<T>::Nodo* Conjunto<T>:: siguienteInorder(Nodo *raiz,  Nodo *n) {
    if(n->der!=NULL){
        return minValNodo(n->der);
    }
    Nodo* padre= n->padre;
    while(padre!=NULL && n==padre->der){
        n=padre;
        padre=padre->padre;
    }
    return padre;
}
template <typename T>
typename Conjunto<T>::Nodo * Conjunto<T>:: maxValNodo(Nodo *nodo)const {
    Nodo *actual= nodo;
    while(actual->der!=NULL){
        actual=actual->der;
    }
    return actual;
}
template <typename T>
bool Conjunto<T>:: pertenece(Nodo *p,int clave)const {
    if(p==NULL){
        return false;
    }else{
        if(p!=NULL && p->der==NULL && p!=NULL){
            return clave==p->valor;
        }else{
            if(p->valor<clave){
                p=p->der;
                return pertenece(clave);
            }else if(p->valor>clave){
                p=p->izq;
                return pertenece(clave);
            }
        }}
}
