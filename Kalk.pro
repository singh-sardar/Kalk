#-------------------------------------------------
#
# Project created by QtCreator 2017-12-13T22:46:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kalk
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    colorergb.cpp \
    librettoesami.cpp \
    esame.cpp \
    data.cpp \
    colore.cpp \
    ingrediente.cpp \
    ricetta.cpp \
    spinslider.cpp \
    rgbpicker.cpp \
    matrice.cpp \
    coloroperationbuttons.cpp \
    colorcontroller.cpp \
    ricettagui.cpp \
    ingredientedialog.cpp \
    ricettacontroller.cpp \
    matricigui.cpp \
    elementisingolamatrice.cpp \
    tableviewmatrice.cpp \
    matricicontroller.cpp \
    singololibrettoesamiview.cpp \
    esamedialog.cpp \
    librettoesamicontroller.cpp \
    librettoesamigui.cpp \
    tabwidgetgui.cpp \
    colorehsl.cpp \
    hslpicker.cpp \
    colorergba.cpp \
    colorgui.cpp \
    colorpicker.cpp \
    rgbapicker.cpp \
    twocolorpicker.cpp

HEADERS += \
    vettoregenerico.h \
    colore.h \
    colorergb.h \
    esame.h \
    librettoesami.h \
    data.h \
    ingrediente.h \
    ricetta.h \
    spinslider.h \
    rgbpicker.h \
    matrice.h \
    coloroperationbuttons.h \
    colorcontroller.h \
    ricettagui.h \
    ingredientedialog.h \
    ricettacontroller.h \
    matricigui.h \
    elementisingolamatrice.h \
    matricicontroller.h \
    tableviewmatrice.h \
    singololibrettoesamiview.h \
    esamedialog.h \
    librettoesamicontroller.h \
    librettoesamigui.h \
    tabwidgetgui.h \
    colorehsl.h \
    hslpicker.h \
    colorergba.h \
    colorgui.h \
    colorpicker.h \
    rgbapicker.h \
    twocolorpicker.h

FORMS +=
QMAKE_CXXFLAGS += -std=c++11
