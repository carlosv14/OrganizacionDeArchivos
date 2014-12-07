#ifndef DATAREG_H
#define DATAREG_H
#include "lista.h"
#include "datafield.h"
class DataReg
{
public:
    Lista<DataField *> campos;
    DataReg( Lista<DataField *> campos);
};

#endif // DATAREG_H
