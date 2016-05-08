#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>

namespace weather {

class Weather : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label)
public:
    explicit Weather(QObject *parent = 0);
    QString label() const {return m_label;}
    QString getWeatherData();

private:
    QString m_label;
};

}

#endif // WEATHER_H
