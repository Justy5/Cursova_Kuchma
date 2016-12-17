#-------------------------------------------------
#
# Project created by QtCreator 2016-10-22T12:16:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cusrova_remastered
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    triangle.cpp \
    scena.cpp \
    frame.cpp \
    ball.cpp

HEADERS  += widget.h \
    ball.h \
    frame.h \
    scena.h \
    triangle.h

FORMS    += widget.ui

win32-msvc*{
    LIBS += -luser32
}

RESOURCES += \
    resourses.qrc

DISTFILES += \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/bullet.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/scena_pikcha.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/sphere.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/weapon.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/weapon-down.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/weapon-left.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/weapon-up.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/sphere.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/weapon.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/weapon-down.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/weapon-left.png \
    C:/Users/L Lawliet/Documents/cursova_prob/Cursova_Kuchma/weapon-up.png
