#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <iostream>
#include <string.h>
#include "metafield.h"
#include <datafield.h>
#include "datareg.h"
#include <stdlib.h>
#include "lista.h"
#include <QDebug>
#include "hashtable.h"
using namespace std;
class Archivo
{
public:
    FILE * mf;
    const static int byte = 1024;
    Archivo();
    int uno;
    int dos;
    int getRegsize();
    int cantidadReg;
    HashTable *hbt ;
    Lista<int>idsc;
    Lista<char *>TableNamess;
    bool empty;
    void connect(char *n, char *mode);
    void closeconnection();
    void write(char * buffer, int block, long pos, int tipo);
    int read(int blockID);
    Lista<DataReg *>hashlooking(int lugar, int hasta);
    HashTable *readHash(int hashtable);
    int obtenerHb(int cant);
    Lista<DataReg *>readData(int BlockID);
    void bc();
};

#endif // ARCHIVO_H
