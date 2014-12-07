#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTableWidget>
#include "tablename.h"
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <qtreewidget.h>
#include "lista.h"
#include "dialog.h"
#include "bloques.h"
#include "metafield.h"
#include "metareg.h"
#include "archivo.h"
#include "datareg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Archivo *arch;
    Lista<Bloques *> blocks;
    int contB;
    int lastblock;
    int aver;
    int current;
    int count=0;
    char *Tnom;
      int cani;
    Lista<MetaReg*> tables;
    Lista<QTableWidget *>tablas;
    Lista<int> ids;
    Lista<char *>TableNames;

    Lista<MetaField *> mfs;
    char *campos;

    int guardarMetaReg();
    int guardarMetaFields();

    int recollect();
    Lista<DataField *> dt;
    Lista<DataReg *> dr;
    int mas;


    void leerArchivo();

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_Table_triggered();

    void on_treeWidget_doubleClicked(const QModelIndex &index);

    void on_actionNuevo_Campo_triggered();

    void on_pushButton_clicked();

    void on_actionNuevo_Campo_2_triggered();

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
