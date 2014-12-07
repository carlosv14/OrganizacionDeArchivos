#include "bloques.h"

Bloques::Bloques(int id, Archivo *a, QString tipo)
{

    this->id = id;
    this->a = a;
    this->apuntador = -1;
    this->tipo = tipo;
    a->connect("Miarchivo","r+");
    cout<<"mrb1"<<mrb<<endl;
}

void Bloques::cerrarHashBlock()
{
    char * q3 = (char*)malloc(4);
    char * q4 = (char*)malloc(4);
    int num;
    for(int i = 0 ; i<hbt->tam;i++){
        num = hbt->valores[i];
      memcpy(q3,&i,4);
      memcpy(q4,&num,4);
      cout<<"escribiendo en archivo: "<<num<<endl;
      this->a->write(q3,0,hb,2);
      hb+=4;
      this->a->write(q4,0,hb,2);
      hb+=4;
    }
    char * q1 = (char*)malloc(4);
    memcpy(q1,&hb,4);
    cout<<"hb"<<hb<<endl;
    this->a->write(q1,0,0,2);
}

int Bloques::buscarenHash()
{
   armarHash();

   a->hashlooking( hbt->Buscar(1));
}

void Bloques::escribirHashBlock(int num, int value)
{
    cout<<"num"<<num<<endl;
    cout<<"value"<<value;
    hbt->Agregar(num,value);
    cout<<"esto agregue"<<hbt->Buscar(1);
}

void Bloques::armarHash()
{
    cout<<"puuutta"<<endl;
 hbt = a->readHash();
}

void Bloques::escribirEncabezadoMetaReg(char * Id)
{
  if(mrbE+4 <= 512){
    a->write(Id,this->id*size,mrbE,2);
    mrbE+=4;
  }
}

int Bloques::buscarBloque(int id)
{
}


int Bloques::escribirMetaRegBlock(char *nombreT, int ID)
{
    cout<<"mrb2"<<mrb<<endl;
if(mrb+54 <=size*1024){
      char * nombre = (char*)malloc(50);
      nombre  = nombreT;
      char * Id = (char*)malloc(4);
       memcpy(Id,&ID,4);
      //escribirEncabezadoMetaReg(Id);
      a->write(Id,this->id*size,mrb,2);
      mrb+=4;
      a->write(nombre,this->id*size,mrb,1);
      mrb += 50;

      cantTablas++;
      cout<<"mrb3"<<mrb<<endl;
      return 0;
    }
return -1;
}

int Bloques::escribirMetaFieldBlock(Lista<MetaField *> campos)
{
    int hasta = campos.sizee;
    int sobrante = 0;
    if(mfb+(campos.sizee*54) > size*1024){
        sobrante = (mfb+(campos.sizee*54))-size*1024;
        hasta -=(sobrante/54);
    }
    char * tipo = (char*)malloc(4);
        for(int i = 0; i<hasta;i++){
            int n = campos.buscar(i)->tipo;
             memcpy(tipo,&n,4);
            a->write(tipo,this->id*size,mfb,2);
            mfb +=4;
            a->write(campos.buscar(i)->nombre,this->id*size,mfb,1);
            mfb += 50;
        }
        return sobrante/54;

}

void Bloques::cerrarMetaRegBlock()
{

    cout<<"mrb :"<<mrb<<endl;
    int esc = mrb;
     cout<<"escribo este mas : "<<esc<<endl;
    char * q1 = (char*)malloc(4);
    char * q2 = (char*)malloc(4);
    memcpy(q1,&mrbE,4);
    memcpy(q2,&esc,4);
    this->a->write(q1,this->id*size,0,2);
    this->a->write(q2,this->id*size,4,2);
}

Lista<DataReg* > Bloques::escribirDataFields(Lista<DataReg* > dr)
{

  this->hbt = new HashTable();
    int n;
    char * numero = (char*)malloc(4);
    int valnum;
    char * valnum2=(char*)malloc(4);
    char* valor = (char*)malloc(50);
    cc= dr.sizee;
    cp = dr.buscar(0)->campos.sizee;
   int total = 0;
    int eliminar=0;
    for(int i = 0; i<1;i++){
        for(int j = 0;j<dr.buscar(i)->campos.sizee;j++){
          n = dr.buscar(i)->campos.buscar(j)->tipo;
            if(n == 1){
                total += 50;
                cout<<"tipo1: "<<total<<endl;
            }else if( n == 2){
                total+=4;
                  cout<<"tipo2: "<<total<<endl;
            }
        }

    }
    cout<<"ESTE TOTAL: "<<total<<endl;
    cout<<"drs : "<<dr.sizee;
    for(int i = 0; i<dr.sizee;i++){
        escribirHashBlock(i+1,(id*4*1024)+dfb);
        cout<<"con dfb : "<<(dfb+total)<<endl;
        if((total*(i+1))+154 <= size*1024){
        for(int j = 0; j<dr.buscar(i)->campos.sizee; j++){
             n = dr.buscar(i)->campos.buscar(j)->tipo;
             memcpy(numero,&n,4);
             a->write(numero,this->id*size,dfb,2);
             dfb +=4;
        if(n==1){
            valor = dr.buscar(i)->campos.buscar(j)->val;
        a->write(valor,this->id*size,dfb,1);
        dfb +=50;
        }else if(n == 2){
            valnum = dr.buscar(i)->campos.buscar(j)->num;
             memcpy(valnum2,&valnum,4);
             a->write(valnum2,this->id*size,dfb,2);

             dfb +=4;
        }
        cout<<"j : "<<j<<endl;
      }
        eliminar++;
     }else if(dfb+total > size*1024){

        break;
        }
    }
    for(int a =0; a<eliminar; a++){
    dr.eliminar(0);
    cout<<"Sizeee: "<<dr.sizee<<endl;
    }
    cerrarHashBlock();
    return dr;
}

void Bloques::cerrarMetaFieldBlock()
{
    char * q1 = (char*)malloc(4);
    char * q2 = (char*)malloc(4);

    memcpy(q1,&mfbE,4);
    memcpy(q2,&mfb,4);

    this->a->write(q1,this->id*size,0,2);
    this->a->write(q2,this->id*size,4,2);

}

void Bloques::cerrarDataFieldBlock()
{

    char * q1 = (char*)malloc(4);
    char * q2 = (char*)malloc(4);
    char * q3 = (char*)malloc(4);
    char * q4 = (char*)malloc(4);
    memcpy(q1,&dfbE,4);
    memcpy(q2,&dfb,4);
    memcpy(q3,&cc,4);
    memcpy(q4,&cp,4);
    this->a->write(q1,this->id*size,0,2);
    this->a->write(q2,this->id*size,4,2);
    this->a->write(q3,this->id*size,8,2);
    this->a->write(q4,this->id*size,12,2);
    cout<<"escribibububu :"<<cc<<" y "<< cp<<endl;
}

void Bloques::escribirEncabezadoMetaField()
{

}

void Bloques::crearApuntador(int apuntador,QString tipo)
{
    char * q1 = (char*)malloc(4);
     this->apuntador = apuntador;
    memcpy(q1,&apuntador,4);
    if(tipo == "MR" || tipo == "MF"){
    this->a->write(q1,this->id*size,8,2);
    }else if(tipo == "DR"){
    this->a->write(q1,this->id*size,16,2);
    }
}
