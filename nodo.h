#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

template <class T>
class Nodo
{
    public:
        Nodo<T> * siguiente;
        Nodo<T>* anterior;
        T valor;
        Nodo(T valor){
    this->valor = valor;
    this->siguiente = NULL;
        }
        virtual ~Nodo(){

        }
    protected:
    private:
};



#endif // NODO_H
