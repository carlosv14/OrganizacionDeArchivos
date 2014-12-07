#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arch= new Archivo();
    this->contB = 3;
    ui->treeWidget->setHeaderLabel("Tablas");
    blocks.inserta(new Bloques(0,arch,"MR"));
    blocks.inserta(new Bloques(1,arch,"MF"));
    blocks.inserta(new Bloques(2,arch,"DR"));
    leerArchivo();
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::guardarMetaReg()
{
    int retorno = 0;
    for(int i = 0; i<blocks.sizee;i++)
        if(blocks.buscar(i)->tipo == "MR")
            lastblock = i;

   cout<<"tables: "<<tables.sizee<<endl;
if(mas<0)
    mas = 0;
 if((mas/54)+1 == 73)
     blocks.inserta(new Bloques(contB,arch,"MR"));
qDebug()<<"mas";
qDebug()<<mas;
 if( aver>0){
 blocks.inserta(new Bloques(contB,arch,"MF"));
 contB++;
 blocks.inserta(new Bloques(contB,arch,"DR"));
 contB++;
 }
 cout<<"Tablenames4: " <<tables.sizee<<endl;
 cout<<"ids4:" <<ids.sizee<<endl;
int lastboftype;
 for(int i = 0; i<tables.sizee;i++){
 if(blocks.buscar(lastblock)->escribirMetaRegBlock(tables.buscar(i)->nombre,tables.buscar(i)->ID) == -1){
     lastboftype = blocks.sizee-1;
     blocks.buscar(lastblock)->crearApuntador(blocks.sizee,"MR");
     blocks.inserta(new Bloques(contB,arch,"MR"));
     blocks.buscar(lastboftype)->escribirMetaRegBlock(tables.buscar(i)->nombre,tables.buscar(i)->ID);
    retorno = lastboftype;
 }
}
 aver++;
 tables.borrarTodo();
 ids.borrarTodo();
TableNames.borrarTodo();
return retorno;
}
void MainWindow::on_actionNew_Table_triggered()
{

   TableName m;
   m.setModal(true);
   m.exec();
   tablas.inserta(new QTableWidget());
   ui->stackedWidget->addWidget(tablas.buscar(tablas.sizee-1));
   QTreeWidgetItem *tablen = new QTreeWidgetItem();
   for(int i = m.nombre.size(); i<50; i++)
            m.nombre+= " ";
   tablen->setText(0,m.nombre);
   ui->treeWidget->addTopLevelItem(tablen);
   Tnom  = strdup(m.nombre.toStdString().c_str());
   tables.inserta(new MetaReg(count,Tnom));
   count++;
}


void MainWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{
int error = 0;
  if(ids.sizee> 0)
      ids.borrarTodo();
  if(TableNames.sizee>0)
      TableNames.borrarTodo();
    qDebug()<<ids.sizee;
    std::string nombre;
    current =index.row();
    if(current == 0)
     error = arch->read(1*4);
    else
    error = arch->read((current*2+1)*4);
    ids = arch->idsc;
    TableNames = arch->TableNamess;
    for(int i = 0; i<ids.sizee;i++){
    QTableWidgetItem * tb = new QTableWidgetItem();
    campos = strdup(TableNames.buscar(i));
    nombre = campos;
    tb->setText(QString::fromStdString(nombre));
    if(ids.sizee>tablas.buscar(current)->columnCount())
    tablas.buscar(current)->setColumnCount(tablas.buscar(current)->columnCount()+1);
    tablas.buscar(current)->setHorizontalHeaderItem(tablas.buscar(current)->columnCount()-1,tb);
    mfs.inserta(new MetaField(ids.buscar(i),campos));
    }

if(dr.sizee>0)
    dr.borrarTodo();
if(error >0){
        if(current ==0 )
           dr= arch->readData(2*4);
        else
            dr = arch->readData((current*2+2)*4);
        for(int i = 0; i<dr.sizee;i++){
             tablas.buscar(current)->setRowCount( tablas.buscar(current)->rowCount()+1);
            for(int j= 0 ; j<dr.buscar(i)->campos.sizee;j++){
                QTableWidgetItem * tb2 = new QTableWidgetItem();
               if(dr.buscar(i)->campos.buscar(j)->tipo ==1)
                tb2->setText(QString::fromStdString(strdup(dr.buscar(i)->campos.buscar(j)->val)));
                 else if(dr.buscar(i)->campos.buscar(j)->tipo == 2)
                  tb2->setText(QString::number(dr.buscar(i)->campos.buscar(j)->num));

                  tablas.buscar(current)->setItem(i,j,tb2);
            }
        }
    }

    ui->stackedWidget->setCurrentWidget(tablas.buscar(current));


}

void MainWindow::on_actionNuevo_Campo_triggered()
{
    Dialog m;
    m.setModal(true);
    m.exec();
    QTableWidgetItem * tb = new QTableWidgetItem();
    for(int i = m.campo.size(); i<50; i++)
             m.campo+= " ";
    tb->setText(m.campo);
    tablas.buscar(current)->setColumnCount(tablas.buscar(current)->columnCount()+1);
    tablas.buscar(current)->setHorizontalHeaderItem(tablas.buscar(current)->columnCount()-1,tb);
    campos = strdup(m.campo.toStdString().c_str());
    mfs.inserta(new MetaField(m.tipo+1,campos));

}


int MainWindow::guardarMetaFields()
{
    int retorno = 0;
     cout<<"paso modi"<<endl;
    int re;
    int lastboftype;
     if(current == 0){
      re = blocks.buscar(1)->escribirMetaFieldBlock(mfs);
      if(re!=0){
          lastboftype = blocks.sizee-1;
          for(int i = 0; i<(mfs.sizee-re); i++)
                     mfs.eliminar(i);
          blocks.buscar(1)->crearApuntador(blocks.sizee,"MF");
          blocks.inserta(new Bloques(contB,arch,"MF"));
          blocks.buscar(lastboftype)->escribirMetaFieldBlock(mfs);
          retorno = lastboftype;
      }
  }else{
      re = blocks.buscar(2*current+1)->escribirMetaFieldBlock(mfs);
      if(re!=0){
          for(int i = 0; i<(mfs.sizee-re); i++)
                     mfs.eliminar(i);
          blocks.buscar(2*current+1)->crearApuntador(blocks.sizee,"MF");
          blocks.inserta(new Bloques(contB,arch,"MF"));
          blocks.buscar(lastboftype)->escribirMetaFieldBlock(mfs);
          retorno =lastboftype;
      }
   }
  mfs.borrarTodo();
  return retorno;
}



int MainWindow::recollect()
{
    int retorno = 0;
  dr.borrarTodo();
QString item;
    for(int i =0 ; i<tablas.buscar(current)->rowCount();i++){
        if(dt.sizee>0)
         dt.borrarTodo();
        for(int j = 0; j<tablas.buscar(current)->columnCount();j++){
          if(tablas.buscar(current)->item(i,j)->text().isNull()){
              if(mfs.buscar(j)->tipo == 1)
                  tablas.buscar(current)->item(i,j)->setText(" ");
               else if(mfs.buscar(j)->tipo == 2)
                  tablas.buscar(current)->item(i,j)->setText(0);
            }            item = tablas.buscar(current)->item(i,j)->text();
            if(mfs.buscar(j)->tipo == 1)
            item +=QString((50-item.size()),' ');

            cout<<"s: " <<item.size()<<endl;
            qDebug()<<item;
            cout<<"busco: "<<mfs.buscar(j)->tipo<<endl;
           dt.inserta(new DataField(item,mfs.buscar(j)->tipo));
        }
        dr.inserta(new DataReg(dt));
    }
    int lastboftype;
    Lista<DataReg *> drrr;
   if(current == 0){
       drrr= blocks.buscar(2)->escribirDataFields(dr);
       cout<<"drrrsize: "<<drrr.sizee<<endl;
     if(drrr.sizee>0){
          lastboftype = blocks.sizee-1;
            blocks.buscar(2)->crearApuntador(blocks.sizee,"DR");
             blocks.inserta(new Bloques(contB,arch,"DR"));
             blocks.buscar(lastboftype)->escribirDataFields(drrr);
             retorno = lastboftype;
     }
  }else{
       drrr = blocks.buscar(2*current+2)->escribirDataFields(dr);
     if(drrr.sizee>0){
        lastboftype = blocks.sizee-1;
      blocks.buscar(2*current+2)->crearApuntador(blocks.sizee,"DR");
      blocks.inserta(new Bloques(contB,arch,"DR"));
      blocks.buscar(lastboftype)->escribirDataFields(drrr);
      retorno = lastboftype;
     }
   }
   dr.borrarTodo();
return retorno;
}


void MainWindow::leerArchivo()
{
    std::string nombre;
    if(ids.sizee> 0)
        ids.borrarTodo();
    if(TableNames.sizee>0)
        TableNames.borrarTodo();

    for(int i = 0; i<blocks.sizee;i++)
        if(blocks.buscar(i)->tipo == "MR"){
            mas = arch->read(i);
            lastblock = i;
        }
    cout<<"lastb : "<<lastblock;
    ids = arch->idsc;
    TableNames = arch->TableNamess;
    cout<<"Tablenames1: " <<tables.sizee;
    cout<<"ids1:" <<ids.sizee;
    for(int i = 0; i<ids.sizee;i++){
        tablas.inserta(new QTableWidget());
        ui->stackedWidget->addWidget(tablas.buscar(tablas.sizee-1));
        QTreeWidgetItem *tablen = new QTreeWidgetItem();
         Tnom  = strdup(TableNames.buscar(i));
           nombre = Tnom;
        tablen->setText(0,QString::fromStdString(nombre));
        ui->treeWidget->addTopLevelItem(tablen);
        tables.inserta(new MetaReg(ids.buscar(i),Tnom));
        count++;

    }
    for(int i = 1; i<(mas/54) ; i++){
    blocks.inserta(new Bloques(contB,arch,"MF"));
    contB++;
    blocks.inserta(new Bloques(contB,arch,"DR"));
    contB++;
    }


}
void MainWindow::on_pushButton_clicked()
{
    int retornaron;
    if(tables.sizee>0){
    retornaron = guardarMetaReg();
    for(int i = 0; i<blocks.sizee;i++)
        if(blocks.buscar(i)->tipo == "MR")
            lastblock = i;
    cout<<"Esto mas: "<<mas<<endl;
    blocks.buscar(lastblock)->cerrarMetaRegBlock();
    if(retornaron != 0)
        blocks.buscar(retornaron)->cerrarMetaRegBlock();
    }

  retornaron =  recollect();
  if(current == 0)
      blocks.buscar(2)->cerrarDataFieldBlock();
   else
       blocks.buscar(current*2+2)->cerrarDataFieldBlock();
  if(retornaron !=0)
      blocks.buscar(retornaron)->cerrarDataFieldBlock();


    qDebug()<<"mfs.sizee";
    qDebug()<<mfs.sizee;
    if(mfs.sizee>0){
    retornaron = guardarMetaFields();
    if(current == 0)
        blocks.buscar(1)->cerrarMetaFieldBlock();
    else
        blocks.buscar(current*2+1)->cerrarMetaFieldBlock();
    }
    if(retornaron!=0)
        blocks.buscar(retornaron)->cerrarMetaFieldBlock();

}

void MainWindow::on_actionNuevo_Campo_2_triggered()
{
     tablas.buscar(current)->setRowCount(tablas.buscar(current)->rowCount()+1);
}





void MainWindow::on_pushButton_2_clicked()
{


}
