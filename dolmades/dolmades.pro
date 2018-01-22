#-------------------------------------------------
#
# Project created by QtCreator 2017-07-07T19:27:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dolmades
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp\
	basewidget.cpp\
        dolmadewidget.cpp\
        recipewidget.cpp\
        ingredientwidget.cpp\
        toolwidget.cpp\
        helpwidget.cpp\
        preferenceswidget.cpp\
        containercmd.cpp

HEADERS  += mainwidget.h\
            basewidget.h\
            dolmadewidget.h\
            recipewidget.h\
            ingredientwidget.h\
            toolwidget.h\
            helpwidget.h\
            preferenceswidget.h\
            containercmd.h

RESOURCES = resources.qrc
