TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    userinterface.cpp \
    listreports.cpp \
    listworkers.cpp \
    listingredients.cpp \
    listrecepi.cpp \
    worker.cpp \
    product.cpp \
    ingredient.cpp \
    ingredientforrecepi.cpp \
    recepi.cpp \
    report.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    userinterface.h \
    listreports.h \
    listworkers.h \
    listingredients.h \
    listrecepi.h \
    worker.h \
    product.h \
    ingredient.h \
    ingredientforrecepi.h \
    resepi.h \
    report.h

