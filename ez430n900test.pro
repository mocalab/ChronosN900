#-------------------------------------------------
#
# Project created by QtCreator 2011-03-23T13:19:03
#
#-------------------------------------------------

QT       += core gui

TARGET = ez430n900test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    UnixSerialInterface.cpp \
    Chronos.cpp \
    n900accelerometer.cpp

HEADERS  += mainwindow.h \
    UnixSerialInterface.h \
    Chronos.h \
    n900accelerometer.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

OTHER_FILES += \
    test.txt

#target.path = /opt/MasterController/bin
desktop.path = /usr/share/applications/hildon
desktop.files += maemofiles/chronos.desktop
icon48.path = /usr/share/icons/hicolor/64x64/apps
icon48.files += maemofiles/chronos_icon.png

INSTALLS += desktop icon48

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/bin
    } else {
        target.path = /usr/local/bin
    }
    INSTALLS += target
}
