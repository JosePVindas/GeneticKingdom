#-------------------------------------------------
#
# Project created by QtCreator 2016-10-08T14:29:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ogre.cpp \
    enemy.cpp \
    mymouse.cpp

HEADERS  += mainwindow.h \
    ogre.h \
    enemy.h \
    mymouse.h

FORMS    += mainwindow.ui

LIBS += -LC:/Users/jpvin/Documents/Qt_projects/SFML-2.3.1/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d


INCLUDEPATH += C:/Users/jpvin/Documents/Qt_projects/SFML-2.3.1/include
DEPENDPATH += C:/Users/jpvin/Documents/Qt_projects/SFML-2.3.1/include
