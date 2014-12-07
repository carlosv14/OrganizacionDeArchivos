#ifndef LISTA_H
#define LISTA_H
#include<iostream>
#include "Nodo.h"
using namespace std;

template <class T>

class Lista
{
    public:
        int sizee;
        Nodo<T>* inicio;

        Lista();
        virtual ~Lista();
        void inserta(int posicion, T valor);
        void inserta(T valor);
        T buscar(int pos);
        int Eliminar(T valor);
        void borrarTodo();
        void eliminar(int pos);

    protected:
    private:
};

template<class T>
Lista<T>::Lista()
{
    sizee = 0;
    inicio = NULL;
}

template<class T>
Lista<T>::~Lista()
{
    //dtor
}

template<class T>
void Lista<T>::borrarTodo(){
    inicio =NULL;
    this->sizee=0;
}

template<class T>
T Lista<T>::buscar(int pos){
    Nodo<T>*tmp = inicio;
    for(int i=0; i<pos;i++)
            tmp = tmp->siguiente;
    return tmp->valor;
}

template<class T>
void Lista<T>::eliminar(int pos){
    if(pos<0 || pos>=this->sizee)
        return;
    Nodo<T>* tmp = inicio;
    for(int i =0 ; i<pos-1; i++){
        tmp = tmp->siguiente;
    }
    if(pos == 0){
        inicio = inicio->siguiente;
    }else if(pos == sizee-1){
        tmp->siguiente = NULL;
    }else{
        tmp->siguiente = tmp->siguiente->siguiente;
    }
    sizee--;
}

template<class T>
void Lista<T>::inserta(T valor){
    inserta(this->sizee, valor);
}


template<class T>
void Lista<T>::inserta(int posicion, T valor)
{
    if(posicion>sizee)
        return ;
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if(posicion == 0)
    {
        if(sizee == 0)
        {
            inicio = nuevoNodo;
        }else
        {
            nuevoNodo->siguiente = inicio;
            inicio = nuevoNodo;
        }
        sizee++;
        return ;
    }
    Nodo<T>* tmp;
    int i = 0;
    for(tmp = inicio; tmp != NULL; tmp = tmp->siguiente)
    {
        if(i == posicion-1)
        {
            nuevoNodo->siguiente = tmp->siguiente;
            tmp->siguiente = nuevoNodo;
        }
        i++;
    }


    sizee++;
}
template<class T>
int Lista<T>:: Eliminar(T valor){
    Nodo<T>* tmp = inicio;
    for(int i = 0; i<sizee ; i++){
        if(tmp->valor == valor)
            return i;
        tmp = tmp->siguiente;

      }
    return -1;
}



#endif // LISTA_H
