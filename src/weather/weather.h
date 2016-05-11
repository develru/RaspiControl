#ifndef WEATHER_H
#define WEATHER_H

#include <memory>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>


namespace weather {

class Weather : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label)
public:
    explicit Weather(QObject *parent = 0);
    QString label() const {return m_label;}
    Q_INVOKABLE void requestWeatherData();

public slots:
    void weatherDataRecived(QNetworkReply* networkReply);

private:
    QString m_label;
    std::unique_ptr<QNetworkAccessManager> m_manager;
//    QNetworkAccessManager* m_manager;
    QString m_apiKey;
};

}

#endif // WEATHER_H
