#ifndef WEATHERFORECASTDATA_H
#define WEATHERFORECASTDATA_H

#include <QtCore/QString>

namespace weather {

class WeatherForecastData
{
    int m_tempMin;
    int m_tempMax;
    int m_time;
    QString m_description;
    QString m_icon;

public:
    explicit WeatherForecastData();

    int tempMin() const;
    int tempMax() const;
    int time() const;
    QString description() const;
    QString icon() const;
    void setTempMin(int tempMin);
    void setTempMax(int tempMax);
    void setTime(int time);
    void setDescription(QString description);
    void setIcon(QString icon);

};

}

#endif // WEATHERFORECASTDATA_H
