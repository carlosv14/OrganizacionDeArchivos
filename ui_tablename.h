/********************************************************************************
** Form generated from reading UI file 'tablename.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLENAME_H
#define UI_TABLENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_TableName
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *TableName)
    {
        if (TableName->objectName().isEmpty())
            TableName->setObjectName(QStringLiteral("TableName"));
        TableName->resize(415, 89);
        buttonBox = new QDialogButtonBox(TableName);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(300, 10, 81, 231));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(TableName);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 10, 161, 16));
        lineEdit = new QLineEdit(TableName);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 40, 161, 20));

        retranslateUi(TableName);
        QObject::connect(buttonBox, SIGNAL(accepted()), TableName, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TableName, SLOT(reject()));

        QMetaObject::connectSlotsByName(TableName);
    } // setupUi

    void retranslateUi(QDialog *TableName)
    {
        TableName->setWindowTitle(QApplication::translate("TableName", "Dialog", 0));
        label->setText(QApplication::translate("TableName", "Ingrese el Nombre para la tabla:", 0));
    } // retranslateUi

};

namespace Ui {
    class TableName: public Ui_TableName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLENAME_H
