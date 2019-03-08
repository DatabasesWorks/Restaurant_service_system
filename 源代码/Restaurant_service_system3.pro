#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T16:34:49
#
#-------------------------------------------------

QT       += core gui
QT       += sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Restaurant_service_system2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    administrator.cpp \
    registeraccount.cpp \
    deskchoose.cpp \
    login.cpp \
    waiterdlg.cpp \
    cookdlg.cpp \
    registertel.cpp \
    waitingfor.cpp \
    order.cpp \
    evaluate.cpp \
    database.cpp \
    managerdlg.cpp \
    cooking.cpp \
    customer.cpp \
    cook.cpp \
    waiter.cpp \
    desk.cpp \
    onedish.cpp \
    restaurant.cpp \
    pay.cpp \
    managecustomer.cpp \
    managedish.cpp \
    managewaiter.cpp \
    managecook.cpp \
    newworker.cpp \
    newcook.cpp \
    serve.cpp \
    cookassess.cpp \
    waiterassess.cpp

HEADERS += \
        mainwindow.h \
    customer.h \
    administrator.h \
    registeraccount.h \
    deskchoose.h \
    database.h \
    dish.h \
    login.h \
    waiterdlg.h \
    cookdlg.h \
    registertel.h \
    desk.h \
    waitingfor.h \
    order.h \
    evaluate.h \
    customer.h \
    managerdlg.h \
    cooking.h \
    restaurant.h \
    cook.h \
    waiter.h \
    onedish.h \
    pay.h \
    managecustomer.h \
    managedish.h \
    managewaiter.h \
    managecook.h \
    newworker.h \
    newcook.h \
    serve.h \
    cookassess.h \
    waiterassess.h

FORMS += \
        mainwindow.ui \
    customer.ui \
    administrator.ui \
    registeraccount.ui \
    deskchoose.ui \
    login.ui \
    waiterdlg.ui \
    cookdlg.ui \
    registertel.ui \
    waitingfor.ui \
    order.ui \
    evaluate.ui \
    managerdlg.ui \
    cooking.ui \
    pay.ui \
    managecustomer.ui \
    managedish.ui \
    managewaiter.ui \
    managecook.ui \
    newworker.ui \
    newcook.ui \
    serve.ui \
    cookassess.ui \
    waiterassess.ui
