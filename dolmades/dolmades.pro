#-------------------------------------------------
#
# Project created by QtCreator 2017-07-07T19:27:27
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dolmades
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp\
        containercmd.cpp \
        basewidget.cpp

HEADERS  += mainwidget.h\
            containercmd.h \
            basewidget.h

RESOURCES = resources.qrc

FORMS += \
    basewidget.ui
