QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT  += charts

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    change.cpp \
    ggraph.cpp \
    graph_month.cpp \
    graph_year.cpp \
    inventory_add.cpp \
    look.cpp \
    main.cpp \
    mainwindow.cpp \
    p_delete.cpp \
    trash.cpp

HEADERS += \
    change.h \
    ggraph.h \
    graph_month.h \
    graph_year.h \
    inventory_add.h \
    look.h \
    mainwindow.h \
    p_delete.h \
    trash.h

FORMS += \
    change.ui \
    ggraph.ui \
    graph_month.ui \
    graph_year.ui \
    inventory_add.ui \
    look.ui \
    mainwindow.ui \
    p_delete.ui \
    trash.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
