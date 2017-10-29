#-------------------------------------------------
#
# Project created by QtCreator 2017-10-29T02:13:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tableview
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    remotetabelview.cpp \
    remotetablemodel.cpp \
    delegates.cpp

HEADERS  += mainwindow.h \
    remotetabelview.h \
    remotetablemodel.h \
    delegates.h

FORMS    +=
