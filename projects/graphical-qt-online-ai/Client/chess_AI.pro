#-------------------------------------------------
#
# Project created by QtCreator 2018-06-07T18:32:17
#
#-------------------------------------------------

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chess_AI
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    game.cpp \
    button.cpp \
    gameitems/gameboard.cpp \
    gameitems/boardbox.cpp \
    gameitems/piece.cpp \
    gameitems/king.cpp \
    gameitems/queen.cpp \
    gameitems/bishop.cpp \
    gameitems/rook.cpp \
    gameitems/pawn.cpp \
    gameitems/knight.cpp \
    AI_files/possible_boxnpiece.cpp \
    AI_files/stupid_ai.cpp \
    AI_files/findallmovess.cpp \
    onlineGame/chessroom.cpp \
    onlineGame/chatroom.cpp \
    onlineGame/gamelobby.cpp \
    cJSON/cJSON.c

HEADERS += \
    game.h \
    button.h \
    gameitems/gameboard.h \
    gameitems/boardbox.h \
    gameitems/piece.h \
    gameitems/king.h \
    gameitems/queen.h \
    gameitems/bishop.h \
    gameitems/rook.h \
    gameitems/pawn.h \
    gameitems/knight.h \
    AI_files/possible_boxnpiece.h \
    AI_files/stupid_ai.h \
    AI_files/findallmovess.h \
    AI_files/moves.h \
    AI_files/positioncalcuation.h \
    onlineGame/chessroom.h \
    onlineGame/chatroom.h \
    onlineGame/message.h \
    onlineGame/onlinemove.h \
    onlineGame/gamelobby.h \
    cJSON/cJSON.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    res.qrc
