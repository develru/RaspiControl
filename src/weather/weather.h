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
    Q_PROPERTY(QString label READ label)
    Q_PROPERTY(QString location READ location NOTIFY weatherChanged)
public:
    explicit Weather(QObject *parent = 0);
    ~Weather();
    QString label() const {return m_label;}
    QString location() const;
    Q_INVOKABLE void requestWeatherData();

signals:
    void weatherChanged();

public slots:
    void weatherDataRecived(QNetworkReply* networkReply);

private:
    void readData(const QJsonObject& jsonObj);

    QString m_label;
    std::unique_ptr<QNetworkAccessManager> m_manager;
//    QNetworkAccessManager* m_manager;
    QString m_apiKey;
    WeatherData* m_weatherData;

};

}

#endif // WEATHER_H
