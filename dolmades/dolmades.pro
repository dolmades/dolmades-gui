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
        basewidget.cpp \
    dolmade.cpp \
    ingredient.cpp \
    recipe.cpp

HEADERS  += mainwidget.h\
            containercmd.h \
            basewidget.h \
    dolmade.h \
    ingredient.h \
    recipe.h \
    blob.h \
    descriptor.h

RESOURCES = resources.qrc

FORMS += basewidget.ui

DISTFILES += \
    icons/search.png \
    icons/search.png
