#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;

    private:

        /**
         * Completar con lo que sea necesario...
         **/

        struct Nodo
        {
            ~Nodo();
            // El constructor, toma el elemento al que representa el nodo.
            Nodo(const T& v):
            valor(v),izq(NULL),der(NULL){}
            // El elemento al que representa el nodo.
            T valor;
            // Puntero a la raíz del subárbol izquierdo.
            Nodo* izq;
            // Puntero a la raíz del subárbol derecho.
            Nodo* der; 
        };

        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;
        Nodo* buscar_Nodo(const T k);
        //Nodo* buscar_valor_Nodo(const T& k);
        Nodo * padre(Nodo* q)const;
        T findMinimo(Nodo *raiz)const;
        Nodo * search(Nodo* raiz, int key);
        Nodo *CrearNodo( int key);
        Nodo * insertar( Nodo *nodo, int key);
        int cardinal( Nodo *nodo,int i)const;
        void inorder(Nodo *raiz);
        Nodo * minValNodo( Nodo *nodo);
        Nodo * eliminarNodo( Nodo *nodo,int valor);

        void limpiar();

};

template<class T>
std::ostream& operator<<(const Conjunto<T>& c, std::ostream& os) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
