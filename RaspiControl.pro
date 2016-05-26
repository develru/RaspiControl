TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += src/main.cpp \
    src/weather/weather.cpp \
    src/weather/weatherdata.cpp \
    src/weather/weatherforecastdata.cpp \
    src/weather/forecastdatamodell.cpp

RESOURCES += src/qml.qrc \
    src/appres.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

linux-rasp-pi2-g++ {
    target.path = /home/pi/prg
}

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/weather/weather.h \
    src/weather/weatherdata.h \
    src/weather/weatherforecastdata.h \
    src/weather/forecastdatamodell.h

DISTFILES +=
