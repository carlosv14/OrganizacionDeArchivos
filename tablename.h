#ifndef TABLENAME_H
#define TABLENAME_H

#include <QDialog>

namespace Ui {
class TableName;
}

class TableName : public QDialog
{
    Q_OBJECT

public:
    QString nombre;
    explicit TableName(QWidget *parent = 0);
    ~TableName();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::TableName *ui;
};

#endif // TABLENAME_H
