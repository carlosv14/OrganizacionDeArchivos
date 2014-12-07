#ifndef BLOQUES_H
#define BLOQUES_H
#include "archivo.h"
#include <stdlib.h>
#include <QDebug>
#include "lista.h"
#include "metafield.h"
#include "datafield.h"
#include "datareg.h"
#include "hashtable.h"
class Bloques
{
public:
    int id;
    Archivo *a;
    int cc;
    int cp;
    int apuntador;
    int cantRegis;
    int cantTablas =0;
    const int size=4;
    int sig;
    HashTable *hbt;
    QString tipo;
    Bloques(int id, Archivo *a, QString tipo);
    long mrb = 154;
    long mrbE = 8;
    long mfb = 154;
    long mfbE = 8;
    long dfb = 154;
    long dfbE =8;
    int hb = 4;
    void cerrarHashBlock();
    int buscarenHash(int id, int current);
    void escribirHashBlock(int num, int value);
    void armarHash(int current);
    void escribirEncabezadoMetaReg(char *Id);
    int buscarBloque(int id);
    int escribirMetaRegBlock(char* nombreT, int ID);
    int escribirMetaFieldBlock(Lista<MetaField *> campos);
    void cerrarMetaRegBlock();
    Lista<DataReg *> escribirDataFields(Lista<DataReg *> dr, int current);
    void cerrarMetaFieldBlock();
    void cerrarDataFieldBlock();
    void escribirEncabezadoMetaField();
    void crearApuntador(int apuntador, QString tipo);
};

#endif // BLOQUES_H
