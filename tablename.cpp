#include "tablename.h"
#include "ui_tablename.h"

TableName::TableName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableName)
{
    ui->setupUi(this);
}

TableName::~TableName()
{
    delete ui;
}

void TableName::on_buttonBox_accepted()
{
   nombre = ui->lineEdit->text();
}
