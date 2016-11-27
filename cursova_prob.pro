#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T17:55:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cursova_prob
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    triangle.cpp \
    scena.cpp \
    ball.cpp \
    frame.cpp

HEADERS  += widget.h \
    triangle.h \
    scena.h \
    ball.h \
    frame.h

FORMS    += widget.ui

win32-msvc*{
    LIBS += -luser32
}

DISTFILES +=

RESOURCES += \
    triangle.qrc
