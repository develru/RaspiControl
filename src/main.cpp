#include <QtWidgets/QApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include "weather/weather.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    weather::Weather weat;
    engine.rootContext()->setContextProperty("weather", &weat);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
