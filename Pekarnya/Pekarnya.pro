TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    controller.cpp \
    elements.cpp \
    lists.cpp \
    userinterface.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    controller.h \
    lists.h \
    userinterface.h \
    elements.h

