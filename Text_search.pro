#-------------------------------------------------
#
# Project created by QtCreator 2014-11-21T22:06:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Text_search
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    otsa.cpp \
    naive.cpp

HEADERS  += mainwindow.h \
    otsa.h \
    naive.h

FORMS    += mainwindow.ui \
    otsa.ui \
    naive.ui
