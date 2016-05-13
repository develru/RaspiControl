#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>
#include "weather.h"
using namespace weather;

Weather::Weather(QObject *parent) :
    QObject(parent),
    m_label("Hello Richard!"),
    m_manager(new QNetworkAccessManager(this)),
    m_weatherData(new WeatherData())
{
    connect(m_manager.get(), SIGNAL(finished(QNetworkReply*)),
            this, SLOT(weatherDataRecived(QNetworkReply*)));

    QFile apiFile(":/res/api.txt");
    if (apiFile.open(QFile::ReadOnly)) {
        QTextStream in(&apiFile);
        in.readLineInto(&m_apiKey);
        apiFile.close();
    }
}

//Weather::~Weather()
//{
//    delete m_weatherData;
//}

QString Weather::location() const
{
    return QString::fromStdString(m_weatherData->locationName());
}

void Weather::requestWeatherData()
{
    QString apiCall =
            QString("http://api.openweathermap.org/data/2.5/weather?q=Dachau,de&units=metrics&APPID=%1").arg(m_apiKey);
    m_manager->get(QNetworkRequest(QUrl(apiCall)));
}

void Weather::weatherDataRecived(QNetworkReply* networkReply)
{
    QString jsonStr(networkReply->readAll());
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toStdString().c_str());
    readData(jsonDoc.object());
    networkReply->deleteLater();
}

void Weather::readData(const QJsonObject &jsonObj)
{
    // location
    std::string name = jsonObj["name"].toString().toStdString();
    m_weatherData->setLocationName(name);

    // temperature
    int temp = jsonObj["main"].toObject()["temp"].toInt();
    m_weatherData->setTemperature(temp);

    emit weatherChanged();
}
