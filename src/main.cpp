#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "src/weather/weather.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    weather::Weather weat;
    engine.rootContext()->setContextProperty("weather", &weat);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
