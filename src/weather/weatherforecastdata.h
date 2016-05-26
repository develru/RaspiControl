#ifndef WEATHERFORECASTDATA_H
#define WEATHERFORECASTDATA_H

#include <QObject>
#include <QString>

namespace weather {

class WeatherForecastData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int tempMin READ tempMin WRITE setTempMin NOTIFY tempMinChanged)
    Q_PROPERTY(int tempMax READ tempMax WRITE setTempMax NOTIFY tempMaxChanged)
    Q_PROPERTY(int time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)

    int m_tempMin;
    int m_tempMax;
    int m_time;
    QString m_description;
    QString m_icon;

public:
    explicit WeatherForecastData(QObject *parent = 0);

    int tempMin() const;
    int tempMax() const;
    int time() const;
    QString description() const;
    QString icon() const;

    void emitAllSignals();

signals:
    void tempMinChanged(int tempMin);
    void tempMaxChanged(int tempMax);
    void timeChanged(int time);
    void descriptionChanged(QString description);
    void iconChanged(QString icon);

public slots:
    void setTempMin(int tempMin);
    void setTempMax(int tempMax);
    void setTime(int time);
    void setDescription(QString description);
    void setIcon(QString icon);
};

}

#endif // WEATHERFORECASTDATA_H
