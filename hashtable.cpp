#include "hashtable.h"

HashTable::HashTable()
{
tam = 100;
}
int HashTable::hash(int llave)
{

    return llave%tam;
}

int HashTable::Agregar(int llave, int valor)
{
    int pos=hash(llave);
    valores[pos]=valor;
    return pos;
}

int HashTable::Buscar(int llave)
{
    int pos=hash(llave);
    return valores[pos];
}

void HashTable::load()
{

}

