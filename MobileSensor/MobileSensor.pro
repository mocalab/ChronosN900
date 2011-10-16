# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

# Avoid auto screen rotation
DEFINES += ORIENTATIONLOCK

# Needs to be defined for Symbian
#DEFINES += NETWORKACCESS

symbian:TARGET.UID3 = 0xE0795C14

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
# CONFIG += mobility
# MOBILITY +=

QT += network

SOURCES += main.cpp mainwindow.cpp \
    client.cpp \
    Chronos.cpp \
    UnixSerialInterface.cpp \
    n900accelerometer.cpp
HEADERS += mainwindow.h \
    client.h \
    Chronos.h \
    UnixSerialInterface.h \
    n900accelerometer.h
FORMS += mainwindow.ui

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()
