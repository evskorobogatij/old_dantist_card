#-------------------------------------------------
#
# Project created by QtCreator 2016-11-08T16:20:12
#
#-------------------------------------------------

DESTDIR = bin
QT       += core gui widgets sql

TARGET = old_dantist_kard
#CONFIG   += console

TEMPLATE = app


SOURCES += main.cpp \
    qdkcontroler.cpp \
    qdkbase.cpp \
    qdkmain.cpp \
    qdkaddcard.cpp

HEADERS += \
    qdkcontroler.h \
    qdkbase.h \
    qdkmain.h \
    qdkaddcard.h \
    qdkadding.h

FORMS += \
    qdkmain.ui \
    qdkaddcard.ui
