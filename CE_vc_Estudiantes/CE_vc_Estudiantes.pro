#-------------------------------------------------
#
# Project created by QtCreator 2019-10-09T11:35:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CE_vc_Estudiantes
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
        Evolucionador.cpp \
        Juego.cpp \
        Listas/Lista.cpp \
        Listas/Node.cpp \
        Personajes/Cursos/Arquero.cpp \
        Personajes/Cursos/Artillero.cpp \
        Personajes/Cursos/Curso.cpp \
        Personajes/Cursos/Evaluacion.cpp \
        Personajes/Cursos/LanzaFuego.cpp \
        Personajes/Cursos/Mago.cpp \
        Personajes/Estudiantes/Elfo.cpp \
        Personajes/Estudiantes/Enemigo.cpp \
        Personajes/Estudiantes/Harpia.cpp \
        Personajes/Estudiantes/Mercenario.cpp \
        Personajes/Estudiantes/Ogro.cpp \
        Personajes/Personaje.cpp \
        Tablero.cpp \
        main.cpp \
        mainwindow.cpp \
    square.cpp

HEADERS += \
        Evolucionador.h \
        Juego.h \
        Listas/Lista.h \
        Listas/Node.h \
        Personajes/Cursos/Arquero.h \
        Personajes/Cursos/Artillero.h \
        Personajes/Cursos/Curso.h \
        Personajes/Cursos/Evaluacion.h \
        Personajes/Cursos/LanzaFuego.h \
        Personajes/Cursos/Mago.h \
        Personajes/Estudiantes/Elfo.h \
        Personajes/Estudiantes/Enemigo.h \
        Personajes/Estudiantes/Harpia.h \
        Personajes/Estudiantes/Mercenario.h \
        Personajes/Estudiantes/Ogro.h \
        Personajes/Personaje.h \
        Tablero.h \
        mainwindow.h \
    square.h

FORMS += \
        mainwindow.ui