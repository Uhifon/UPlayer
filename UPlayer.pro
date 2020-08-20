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

win32: LIBS += -L$$PWD/ffmpeg/lib/ -lavformat \
                -L$$PWD/ffmpeg/lib/ -lavutil \
                -L$$PWD/ffmpeg/lib/ -lavcodec \
                -L$$PWD/ffmpeg/lib/ -lavdevice \
                -L$$PWD/ffmpeg/lib/ -lavfilter \
                -L$$PWD/ffmpeg/lib/ -lpostproc \
                -L$$PWD/ffmpeg/lib/ -lswresample \
                -L$$PWD/ffmpeg/lib/ -lswscale \
                -L$$PWD/SDL/lib/ -lSDL2

INCLUDEPATH += $$PWD/ffmpeg/include\
               $$PWD/SDL/include
DEPENDPATH += $$PWD/ffmpeg/include\
              $$PWD/SDL/include
