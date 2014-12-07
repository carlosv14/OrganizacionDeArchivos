#-------------------------------------------------
#
# Project created by QtCreator 2014-10-30T18:31:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto_Orga
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tablename.cpp \
    archivo.cpp \
    bloques.cpp \
    dialog.cpp \
    datafield.cpp \
    datareg.cpp \
    metafield.cpp \
    metareg.cpp \
    hashtable.cpp

HEADERS  += mainwindow.h \
    tablename.h \
    archivo.h \
    datafield.h \
    datareg.h \
    lista.h \
    metafield.h \
    metareg.h \
    nodo.h \
    dialog.h \
    bloques.h \
    hashtable.h

FORMS    += mainwindow.ui \
    tablename.ui \
    dialog.ui
