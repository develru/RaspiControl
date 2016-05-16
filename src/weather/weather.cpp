#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtCore/QTextStream>
#include <cmath>
#include "weather.h"
using namespace weather;

Weather::Weather(QObject *parent) :
    QObject(parent),
    m_manager(new QNetworkAccessManager(this)),
    m_weatherData(new WeatherData()),
    m_timer(new QTimer(this))
{
//    connect(m_manager.get(), SIGNAL(finished(QNetworkReply*)),
//            this, SLOT(weatherDataRecived(QNetworkReply*)));

    connect(m_timer.get(), SIGNAL(timeout()), this, SLOT(updateWeather()));

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

QString Weather::description() const
{
    return QString::fromStdString(m_weatherData->description());
}

QString Weather::temp() const
{
    return QString::number(m_weatherData->temperature());
}

QString Weather::icon() const
{
    return QString::fromStdString(m_weatherData->icon());
}

void Weather::requestWeatherData()
{
    QString apiCall =
            QString("http://api.openweathermap.org/data/2.5/weather?q=Dachau,de&units=metric&APPID=%1").arg(m_apiKey);
    //m_manager->get(QNetworkRequest(QUrl(apiCall)));

    QNetworkRequest requestCurrentWeather(apiCall);
    currentWeather = m_manager->get(requestCurrentWeather);
    connect(currentWeather, SIGNAL(finished()), this, SLOT(weatherDataRecived()));
}

void Weather::weatherDataRecived()
{
    QString jsonStr(currentWeather->readAll());
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toStdString().c_str());
    readData(jsonDoc.object());
    currentWeather->deleteLater();
}

void Weather::readData(const QJsonObject &jsonObj)
{
    // location
    std::string name = jsonObj["name"].toString().toStdString();
    m_weatherData->setLocationName(name);

    // temperature
    double tDo = jsonObj["main"].toObject()["temp"].toDouble();
    int temp = static_cast<int>(std::round(tDo));
//    int temp = jsonObj["main"].toObject()["temp"].toInt();
    m_weatherData->setTemperature(temp);

    // description
    QJsonArray jsonA = jsonObj["weather"].toArray();
    std::string desc = jsonA[0].toObject()["description"].toString().toStdString();
    m_weatherData->setDescription(desc);

    // icon
    std::string icon = jsonA[0].toObject()["icon"].toString().toStdString();
    QString tempIcon = QString("qrc:/img/weather_img/%1.png").arg(QString::fromStdString(icon));
    m_weatherData->setIcon(tempIcon.toStdString());
    emit weatherChanged();

    qDebug() << "Weather data recived";
}

void Weather::updateWeather()
{
    requestWeatherData();
    qDebug() << "Timeout: request new weather data";
}

void Weather::stopTimer()
{
    m_timer->stop();
    qDebug() << "Stop Timer";
}

void Weather::viewIsReaddy()
{
    requestWeatherData();
    m_timer->start(3600000);
}

