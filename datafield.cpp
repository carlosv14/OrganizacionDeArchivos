#include "datafield.h"

DataField::DataField(QString val, int tipo)
{
    this->tipo = tipo;
    if(tipo == 1)
        this->val =strdup(val.toStdString().c_str());
    else if(tipo ==2){
        this->num = val.toInt();
    cout<<"numero: " <<num<<endl;
    }

}
