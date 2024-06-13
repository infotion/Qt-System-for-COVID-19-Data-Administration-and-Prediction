#-------------------------------------------------
#
# Project created by QtCreator 2024-05-15T19:44:31
#
#-------------------------------------------------

QT       += core gui
QT       += charts
QT       += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = System
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
    exceldialog.cpp \
    graphdialog.cpp \
        main.cpp \
        mainwindow.cpp \
    country.cpp \
    mycombobox.cpp \
    polycurve.cpp \
    predictdialog.cpp

HEADERS += \
    exceldialog.h \
    graphdialog.h \
        mainwindow.h \
    country.h \
    mycombobox.h \
    polycurve.h \
    predictdialog.h

FORMS += \
        exceldialog.ui \
        graphdialog.ui \
        mainwindow.ui \
        predictdialog.ui
