QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PacManQt
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
        main.cpp \
        mainwindow.cpp \
    actor.cpp \
    painter.cpp \
    pacman.cpp \
    ghost.cpp \
    tile.cpp \
    gameoptions.cpp \
    gamewindow.cpp \
    serverwindow.cpp \
    clientwindow.cpp

HEADERS += \
        mainwindow.h \
    tile.h \
    actor.h \
    painter.h \
    pacman.h \
    ghost.h \
    game_cfg.h \
    gameoptions.h \
    gamewindow.h \
    globaltypes.h \
    serverwindow.h \
    clientwindow.h

FORMS += \
        mainwindow.ui \
    gameoptions.ui \
    gamewindow.ui \
    serverwindow.ui \
    clientwindow.ui

RESOURCES += \
    resource.qrc
