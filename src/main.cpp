#include <QtWidgets/QApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
//#include <QtQml>
//#include <QtGui>
#include "weather/weather.h"
#include "weather/weatherdata.h"
#include "weather/forecastdatamodell.h"
#include "time/currenttime.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    weather::Weather weat;
    engine.rootContext()->setContextProperty("weather", &weat);
    timespace::CurrentTime cTime;
    engine.rootContext()->setContextProperty("curtime", &cTime);
//    qmlRegisterType<ForecastDataModell>("org.weatherdata", 1, 0, "ForecastDataModell");
//    QList<QObject*> myModelList = weat.forecastList();
//    engine.rootContext()->setContextProperty("forecastModel", QVariant::fromValue(myModelList));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
