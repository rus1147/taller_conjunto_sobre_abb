
template <class T>
Conjunto<T>::Conjunto() {
    _raiz=NULL;
}

template <class T>
Conjunto<T>::~Conjunto() {
    if(minimo()==NULL) {
        _raiz=NULL;
    }else{
        while(_raiz!=NULL){
            Nodo*p=buscar_Nodo(minimo());
            delete p;
            _raiz=NULL;
        }
    }
    _raiz=NULL;
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
    Nodo*p=_raiz;
    if(p==NULL){
        Nodo * n= new Nodo(clave);
        _raiz=n;
    } else{
    while(p!=NULL){
        if(p->valor==clave){
            break;
        } else if(p->valor<clave){
            p=p->der;
        } else{
            p=p->izq;
        }
    }
    if(padre(p)->valor<clave){
        Nodo * n= new Nodo(clave);
        padre(p)->izq=n;
    } else{
        Nodo* n=new Nodo(clave);
        padre(p)->der=n;
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
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
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo*p=_raiz;
    return findMinimo(p);
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
    while(r1!=NULL && r1->der!=NULL && r1->izq!=NULL){
        if(r1->valor>r1->izq->valor){
            r1=r1->izq;
            i++;
        } else{
            r1=r1->der;
            i++;
        }
    }
    while(r2!=NULL && r1->der!=NULL && r1->izq!=NULL){
        if(r2->valor<r2->izq->valor){
            r2=r2->der;
            j++;
        } else{
            r2=r2->izq;
            j++;
        }
    }
    if(r1!=NULL){
        j=1;
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
typename Conjunto<T>::Nodo* Conjunto<T>::buscar_Nodo(const T& k){
    Nodo* r=_raiz;
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
    }
    return r;
}
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
/*






 */