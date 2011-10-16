#-------------------------------------------------
#
# Project created by QtCreator 2011-10-11T13:38:08
#
#-------------------------------------------------

QT       += core gui network

TARGET = MonitorServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    deviceinfo.cpp \
    serverthread.cpp \
    server.cpp

HEADERS  += mainwindow.h \
    deviceinfo.h \
    serverthread.h \
    server.h

FORMS    += mainwindow.ui
