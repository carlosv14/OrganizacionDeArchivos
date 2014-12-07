#include "archivo.h"

Archivo::Archivo()
{
}

void Archivo::connect(char *n, char* mode)
{
    this->mf = fopen(n,mode);
    if(mf == NULL)
       this->mf = fopen(n,"w");
this->hbt=  new HashTable();
}

void Archivo::closeconnection()
{
    fclose(mf);
}

void Archivo::write(char *buffer, int block, long pos, int tipo)
{
    fseek(mf,block*byte,SEEK_SET);
    fseek(mf,pos,SEEK_CUR);
    if(tipo == 1)
    fwrite(buffer,sizeof(char),50,mf);
    if(tipo == 2)
       fwrite(buffer,sizeof(char),sizeof(buffer),mf);
}

int Archivo::read(int blockID )
{
    if(idsc.sizee>0){
        idsc.borrarTodo();
        TableNamess.borrarTodo();
    }
    char * q1 = (char*)malloc(4);
    char * q2 = (char*)malloc(4);
    char *nT = (char*)malloc(50);
    char *copy = (char*)malloc(50);
    char *Id = (char*)malloc(4);
    int nId;
    int where = blockID*byte;
    //busco el bloque
      fseek(mf,where,SEEK_SET);
    //leo la cantidad escrita de metadata y data
      fread(q1,sizeof(char),4,mf);
      fread(q2,sizeof(char),4,mf);
      memcpy(&uno,q1,4);
      memcpy(&dos,q2,4);
      cout<<"dos: tiene : "<<dos<<endl;
     //calculo la cantidad de informacion guardada
     cantidadReg = (dos-154)/54;
      int cuantas;
      cout<<" hay: "<<cantidadReg<<" cuantas desea ver: ";
      cuantas = cantidadReg;
      long pos  = where + 154;
      cuantas= (cuantas*54)+pos;
      fseek(mf,pos,SEEK_SET);
      cout<<"cantidad a leer: "<<cuantas<<endl;
      //muestro la cantidad deseada
      while(pos<cuantas){
          if(cuantas>73*54+pos)
              return -1;
      fread(Id,sizeof(char),4,mf);
      memcpy(&nId,Id,4);
      idsc.inserta(nId);
      pos+=4;
      fread(nT,sizeof(char),50,mf);
       copy = strdup(nT);
      TableNamess.inserta(copy);
      pos+=50;

    }
      for(int i = 0; i<idsc.sizee;i++){
      cout<<idsc.buscar(i)<<endl;
      cout<<TableNamess.buscar(i)<<endl;
      }
      return dos-154;
}

int Archivo::hashlooking(int lugar)
{
    cout<<"looking";
    char * tipo = (char*)malloc(4);
    int num;
    char *value = (char*)malloc(50);
    fseek(mf,lugar,SEEK_SET);
    fread(tipo,sizeof(char),4,mf);
    memcpy(&num,tipo,4);
    if(num == 1){
        fread(value,sizeof(char),50,mf);
        cout<<"es un valor"<<endl;
        cout<<value;
   } else if(num == 2){
        fread(tipo,sizeof(char),4,mf);
        memcpy(&num,tipo,4);
        cout<<num;
     }
    return 1;
}

HashTable* Archivo::readHash(int hashtable)
{
    int ne;
    char *cant = (char*)malloc(4);
    fseek(mf,0,SEEK_SET);
    fread(cant,sizeof(char),4,mf);
    memcpy(&ne,cant,4);
    if(hashtable>0)
    fseek(mf,(hashtable*800)+4,SEEK_SET);
    char * q3 = (char*)malloc(4);
    char * q4 = (char*)malloc(4);
    int num;
    int num2;
    for(int i = 0;i<100;i++){
        fread(q3,sizeof(char),4,mf);
        fread(q4,sizeof(char),4,mf);
        memcpy(&num,q3,4);
        memcpy(&num2,q4,4);
        hbt->Agregar(num,num2);
    }
    return hbt;
}

int Archivo::obtenerHb(int cant)
{
    cout<<"cant"<<cant<<endl;
    int retorno;
   retorno = cant*800;
    retorno+=4;
    cout<<"retorno "<<retorno<<endl;
    return retorno;
}

Lista<DataReg *> Archivo::readData(int BlockID)
{

    int tipo;
    char * tip = (char*)malloc(4);
    char* valor = (char*)malloc(50);
    char* num = (char*)malloc(4);
    int numero;
    int tres;
    int cuatro;
    char *copy = (char*)malloc(50);
    char * q1 = (char*)malloc(4);
    char * q2 = (char*)malloc(4);
    char * q3 = (char*)malloc(4);
    char * q4 = (char*)malloc(4);
    QString v;
    Lista<DataReg *> r;
    Lista<DataField *> d;
    int where = BlockID*byte;
    //busco el bloque
    fseek(mf,where,SEEK_SET);
    //leo la cantidad escrita de metadata y data
      fread(q1,sizeof(char),4,mf);
      fread(q2,sizeof(char),4,mf);
      fread(q3,sizeof(char),4,mf);
      fread(q4,sizeof(char),4,mf);
      memcpy(&uno,q1,4);
      memcpy(&dos,q2,4);
      memcpy(&tres,q3,4);
      memcpy(&cuatro,q4,4);
     cout<<"cuatro : "<<cuatro<<endl;
    long pos  = where + 154;
    long pasadas=0;
    fseek(mf,pos,SEEK_SET);
    cout<<"dos: "<<dos;
    while(pos<dos+where){
       while(pasadas<cuatro){
    fread(tip,sizeof(char),4,mf);
    memcpy(&tipo,tip,4);
    pos+=4;
    cout<<"tipis: "<<tipo<<endl;
    if(tipo == 1){
    fread(valor,sizeof(char),50,mf);
    pos+=50;
    copy = strdup(valor);
    v = copy;
    cout<<"copy: "<<copy<<endl;
   } else if(tipo == 2){
    fread(num,sizeof(char),4,mf);
    memcpy(&numero,num,4);
    pos+=4;
    v = QString::number(numero);
    }
    d.inserta(new DataField(v,tipo));
    pasadas++;
    }
    pasadas = 0;
    r.inserta(new DataReg(d));
    d.borrarTodo();
  }
    return r;
}

void Archivo::bc()
{
   // fseek(mf,12288,SEEK_SET);
}

