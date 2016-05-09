TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    src/weather/weather.cpp

RESOURCES += qml.qrc \
    appres.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH =

linux-rasp-pi2-g++ {
    target.path = /home/pi/prg
}

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/weather/weather.h
