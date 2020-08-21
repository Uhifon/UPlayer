#-------------------------------------------------
#
# Project created by QtCreator 2020-08-20T10:48:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        uffmpeg.cpp \
        play.cpp \
        sdldisplay.cpp

HEADERS  += mainwindow.h \
    uffmpeg.h \
    play.h \
    sdldisplay.h

FORMS    += mainwindow.ui

win32: LIBS += -L$$PWD/ffmpeg/lib/  -lavformat \
                                     -lavutil \
                                     -lavcodec \
                                     -lavdevice \
                                     -lavfilter \
                                     -lpostproc \
                                     -lswresample \
                                     -lswscale
INCLUDEPATH += $$PWD/ffmpeg/include/
DEPENDPATH += $$PWD/ffmpeg/include/


win32: LIBS += -L$$PWD/SDL/lib/ -lSDL2
INCLUDEPATH += $$PWD/SDL/include/
DEPENDPATH += $$PWD/SDL/include/
