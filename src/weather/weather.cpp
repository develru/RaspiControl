#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "weather.h"
using namespace weather;

Weather::Weather(QObject *parent) :
    QObject(parent),
    m_label("Hello Richard!"),
    m_manager(new QNetworkAccessManager(this))
{
    connect(m_manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(weatherDataRecived(QNetworkReply*)));

    QFile apiFile(":/res/api.txt");
    if (apiFile.open(QFile::ReadOnly)) {
        QTextStream in(&apiFile);
        in.readLineInto(&m_apiKey);
        apiFile.close();
    }
}

void Weather::requestWeatherData()
{
    QString apiCall = QString("http://api.openweathermap.org/data/2.5/weather?q=Dachau,de&APPID=%1").arg(m_apiKey);
    m_manager->get(QNetworkRequest(QUrl(apiCall)));
}

void Weather::weatherDataRecived(QNetworkReply* networkReply)
{
    qDebug() << QString(networkReply->readAll());
    networkReply->deleteLater();
}
