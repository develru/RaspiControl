#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtCore/QTextStream>
#include <QtCore/QDateTime>
//#include <QQmlContext>
#include <cmath>
#include "weather.h"
using namespace weather;

Weather::Weather(QObject *parent) :
    QObject(parent),
    m_manager(new QNetworkAccessManager(this)),
    m_weatherData(new WeatherData()),
    m_timer(new QTimer(this)),
    m_dataModel(new ForecastDataModell())
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

Weather::~Weather()
{
    delete m_dataModel;
}

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

QList<WeatherForecastData*> Weather::forecastList() const
{
    return m_forecastDataList;
}


void Weather::requestWeatherData()
{
    QString apiCall =
            QString("http://api.openweathermap.org/data/2.5/weather?q=Dachau,de&units=metric&APPID=%1").arg(m_apiKey);

    QNetworkRequest requestCurrentWeather(apiCall);
    currentWeather = m_manager->get(requestCurrentWeather);
    connect(currentWeather, SIGNAL(finished()), this, SLOT(weatherDataRecived()));

    QString apiCallForecast =
            QString("http://api.openweathermap.org/data/2.5/forecast/daily?q=Dachau,de&cnt=4&units=metric&APPID=%1").arg(m_apiKey);
    QNetworkRequest requestForecast(apiCallForecast);
    forecast = m_manager->get(requestForecast);
    connect(forecast, SIGNAL(finished()), this, SLOT(forecastDataRecived()));
}

void Weather::weatherDataRecived()
{
    QString jsonStr(currentWeather->readAll());
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toStdString().c_str());
    readData(jsonDoc.object());
    currentWeather->deleteLater();
}

void Weather::forecastDataRecived()
{
    qDebug() << "Forecast data recived!";

    QString jsonForecastStr(forecast->readAll());
    QJsonDocument jsonForecastDoc = QJsonDocument::fromJson(jsonForecastStr.toStdString().c_str());
    readForecastData(jsonForecastDoc.object());
    forecast->deleteLater();
}


void Weather::readData(const QJsonObject &jsonObj)
{
    // location
    std::string name = jsonObj["name"].toString().toStdString();
    if (name == "") {
        std::string message = jsonObj["message"].toString().toStdString();
        m_weatherData->setLocationName(message);
        return;
    }
    m_weatherData->setLocationName(name);

    // temperature
    double tDo = jsonObj["main"].toObject()["temp"].toDouble();
    int temp = static_cast<int>(std::round(tDo));
    m_weatherData->setTemperature(temp);

    // description
    QJsonArray jsonA = jsonObj["weather"].toArray();
    std::string desc = jsonA[0].toObject()["description"].toString().toStdString();
    m_weatherData->setDescription(desc);

    // icon
    QString icon = jsonA[0].toObject()["icon"].toString();
    QString tempIcon = QString("qrc:/img/weather_img/%1.png").arg(icon);
    m_weatherData->setIcon(tempIcon.toStdString());
    emit weatherChanged();

    m_lastUpdateTime = QDateTime::currentDateTime().toString("h:mm");
    emit lastUpdateTimeChanged(m_lastUpdateTime);

    qDebug() << "Weather data recived";
}

void Weather::readForecastData(const QJsonObject& jsonObj)
{
    QJsonArray jsonList = jsonObj["list"].toArray();
    int count = jsonList.count();
    m_forecastDataList.clear();
    for (int i=0; i<count; i++) {
        QJsonObject jsonListObj = jsonList[i].toObject();
        WeatherForecastData* forecastData = new WeatherForecastData();
        // time
        int time = jsonListObj["dt"].toInt();
        forecastData->setTime(time);
        QDateTime dt = QDateTime::fromTime_t(time);
        qDebug() << dt.toString("dddd");

        // description
        QJsonArray weatherArr = jsonListObj["weather"].toArray();
        QJsonObject weatherObject = weatherArr[0].toObject();
        std::string desc = weatherObject["description"].toString().toStdString();
        forecastData->setDescription(QString::fromStdString(desc));
        qDebug() << QString::fromStdString(desc);
        QString icon = weatherObject["icon"].toString();
        QString tempIcon = QString("qrc:/img/weather_img/%1.png").arg(icon);
        forecastData->setIcon(tempIcon);

        // max/min
        QJsonObject temp = jsonListObj["temp"].toObject();
        double tempMinD = temp["min"].toDouble();
        double tempMaxD = temp["max"].toDouble();
        int tempMin = static_cast<int>(std::round(tempMinD));
        forecastData->setTempMin(tempMin);
        int tempMax = static_cast<int>(std::round(tempMaxD));
        forecastData->setTempMax(tempMax);
        qDebug() << "Min: " << tempMin << " Max: " << tempMax;

        m_forecastDataList.append(forecastData);
    }

    m_dataModel->setAllData(m_forecastDataList);

    emit modelChanged();
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

ForecastDataModell* Weather::dataModel()
{
    return m_dataModel;
}

QString Weather::lastUpdateTime() const
{
    return m_lastUpdateTime;
}

void Weather::viewIsReaddy()
{
    requestWeatherData();
    m_timer->start(3600000);
}
