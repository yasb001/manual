#-------------------------------------------------
#
# Project created by QtCreator 2017-03-22T22:58:44
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = manual
TEMPLATE = app

RC_FILE+= adminis.rc

#QMAKE_LFLAGS += /MANIFESTUAC:"level='requireAdministrator'uiAccess='false'"

#include(./common/xlsx/qtxlsx.pri)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwidget.cpp \
    signalitembean.cpp \
    addsignaldialog.cpp \
    dbhelper.cpp \
    trialcontroller.cpp \
    registerdialog.cpp \
    xlsxreader.cpp

HEADERS  += mainwidget.h \
    signalitembean.h \
    addsignaldialog.h \
    dbhelper.h \
    common.h \
    trialcontroller.h \
    registerdialog.h \
    xlsxreader.h

FORMS    += mainwidget.ui \
    addsignaldialog.ui \
    registerdialog.ui

CONFIG += mobility
MOBILITY =

RESOURCES += \
    resource.qrc



win32: LIBS += -L$$PWD/../lib/ -llibxl

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
