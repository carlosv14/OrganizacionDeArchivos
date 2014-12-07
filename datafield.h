#ifndef DATAFIELD_H
#define DATAFIELD_H
#include <iostream>
#include <QString>
using namespace std;
class DataField
{
public:
   int num;
   char *val;
   int tipo;
    DataField(QString val, int tipo);
};

#endif // DATAFIELD_H
