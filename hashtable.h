#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
public:
    HashTable();
    int hash(int llave);
    int tam;
    int Agregar(int llave, int valor);
    int Buscar( int llave);
    int valores[100];
    void load();
};

#endif // HASHTABLE_H
