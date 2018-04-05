#-------------------------------------------------
#
# Project created by QtCreator 2018-04-03T20:13:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cop
TEMPLATE = app
CONFIG+= static

DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build

SOURCES += main.cpp\
        mainwindow.cpp \
        Common_functions.cpp\
        Edge2d_List.cpp\
        Edge3d_List.cpp\
        Face3d_List.cpp\
        HiddenLines.cpp\
        Projection2d.cpp\
        Solid3d.cpp\
        Surface3d_List.cpp\
        Vertex2d_List.cpp\
        Vertex3d_List.cpp

HEADERS  += mainwindow.h\
            Common_functions.h\
            Edge2d_List.h\
            Edge3d_List.h\
            Face3d_List.h\
            HiddenLines.h\
            Projection2d.h\
            Solid3d.h\
            Surface3d_List.h\
            Vertex2d_List.h\
            Vertex3d_List.h\


FORMS    += mainwindow.ui
