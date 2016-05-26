#ifndef WEATHER_H
#define WEATHER_H

#include <memory>
#include <QtCore/QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QTimer>
#include <QtCore/QStringList>
#include <QAbstractListModel>
#include "weatherdata.h"
#include "forecastdatamodell.h"

namespace weather {

class Weather : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString location READ location NOTIFY weatherChanged)
    Q_PROPERTY(QString description READ description NOTIFY weatherChanged)
    Q_PROPERTY(QString temp READ temp NOTIFY weatherChanged)
    Q_PROPERTY(QString icon READ icon NOTIFY weatherChanged)
    Q_PROPERTY(ForecastDataModell *dataModel READ dataModel NOTIFY modelChanged)
    Q_PROPERTY(QString lastUpdateTime READ lastUpdateTime NOTIFY lastUpdateTimeChanged)

public:
    explicit Weather(QObject *parent = 0);
    ~Weather();

    QString location() const;
    QString description() const;
    QString temp() const;
    QString icon() const;
    QList<WeatherForecastData *> forecastList() const;
    Q_INVOKABLE void viewIsReaddy();
    Q_INVOKABLE void stopTimer();
    ForecastDataModell *dataModel();
    QString lastUpdateTime() const;

signals:
    void weatherChanged();
    void modelChanged();
    void lastUpdateTimeChanged(QString lastUpdateTime);

public slots:
    void weatherDataRecived();
    void forecastDataRecived();
    void updateWeather();

private:
    void readData(const QJsonObject& jsonObj);
    void readForecastData(const QJsonObject& jsonObj);
    void requestWeatherData();

    std::unique_ptr<QNetworkAccessManager> m_manager;
//    QNetworkAccessManager* m_manager;
    QString m_apiKey;
    std::unique_ptr<WeatherData> m_weatherData;
//    WeatherData* m_weatherData;
    std::unique_ptr<QTimer> m_timer;
    QNetworkReply* currentWeather;
    QNetworkReply* forecast;
    QList<WeatherForecastData*> m_forecastDataList;
    ForecastDataModell* m_dataModel;
    QString m_lastUpdateTime;
};

}

#endif // WEATHER_H
