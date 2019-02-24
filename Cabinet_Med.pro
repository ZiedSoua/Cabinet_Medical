#-------------------------------------------------
#
# Project created by QtCreator 2019-01-29T01:11:04
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cabinet_Med
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ajoutclientvue.cpp \
    rechclientvue.cpp \
    supclientvue.cpp \
    gestioncabinetmeddao.cpp \
    rechhotelresvue.cpp \
    ajoutrdvvue.cpp \
    suprdvvue.cpp \
    historiquevue.cpp \
    calendriervue.cpp

HEADERS += \
        mainwindow.h \
    ajoutclientvue.h \
    rechclientvue.h \
    supclientvue.h \
    gestioncabinetmeddao.h \
    rechhotelresvue.h \
    ajoutrdvvue.h \
    suprdvvue.h \
    historiquevue.h \
    calendriervue.h

FORMS += \
        mainwindow.ui \
    ajoutclientvue.ui \
    rechclientvue.ui \
    supclientvue.ui \
    rechhotelresvue.ui \
    ajoutrdvvue.ui \
    suprdvvue.ui \
    historiquevue.ui \
    calendriervue.ui

win32: LIBS += -L$$PWD/../../Desktop/mysql-connector-c-6.1.11-winx64/mysql-connector-c-6.1.11-winx64/lib/ -llibmysql

INCLUDEPATH += $$PWD/../../Desktop/mysql-connector-c-6.1.11-winx64/mysql-connector-c-6.1.11-winx64/include
DEPENDPATH += $$PWD/../../Desktop/mysql-connector-c-6.1.11-winx64/mysql-connector-c-6.1.11-winx64/include
