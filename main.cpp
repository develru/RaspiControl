#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include "src/weather/weather.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    weather::Weather weat;
//    QQmlContext *context = new QQmlContext(engine.rootContext());
    engine.rootContext()->setContextProperty("weather", &weat);

//    qmlRegisterType<weather::Weather>("com.rschwalk.qmlcomponents", 1, 0, "Weather");
//    engine.rootContext()->setContextProperty("weather", weat);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    QQmlComponent component(&engine);
//    component.create(context);

    return app.exec();
}
