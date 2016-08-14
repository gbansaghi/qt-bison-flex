#-------------------------------------------------
#
# Project created by QtCreator 2016-07-23T15:50:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-bison-flex
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    testparser.cpp \
    parser.cpp \
    scanner.cpp

HEADERS  += mainwindow.h \
    testparser.h \
    common.h \
    parser.h \
    scanner.h

FORMS    += mainwindow.ui

DISTFILES += \
    parser.y \
    scanner.l
