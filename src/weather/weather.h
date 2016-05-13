#ifndef WEATHER_H
#define WEATHER_H

#include <memory>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "weatherdata.h"

namespace weather {

class Weather : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString location READ location NOTIFY weatherChanged)
    Q_PROPERTY(QString description READ description NOTIFY weatherChanged)
    Q_PROPERTY(QString temp READ temp NOTIFY weatherChanged)

public:
    explicit Weather(QObject *parent = 0);
//    ~Weather();

    QString location() const;
    QString description() const;
    QString temp() const;
    Q_INVOKABLE void requestWeatherData();

signals:
    void weatherChanged();

public slots:
    void weatherDataRecived(QNetworkReply* networkReply);

private:
    void readData(const QJsonObject& jsonObj);

    std::unique_ptr<QNetworkAccessManager> m_manager;
//    QNetworkAccessManager* m_manager;
    QString m_apiKey;
    std::unique_ptr<WeatherData> m_weatherData;
//    WeatherData* m_weatherData;

};

}

#endif // WEATHER_H
