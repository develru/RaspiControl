#include "weatherforecastdata.h"

using namespace weather;

WeatherForecastData::WeatherForecastData(QObject *parent) : QObject(parent),
    m_tempMin(0),
    m_tempMax(0),
    m_time(0),
    m_description(""),
    m_icon("")
{

}

int WeatherForecastData::tempMin() const
{
    return m_tempMin;
}

int WeatherForecastData::tempMax() const
{
    return m_tempMax;
}

int WeatherForecastData::time() const
{
    return m_time;
}

QString WeatherForecastData::description() const
{
    return m_description;
}

QString WeatherForecastData::icon() const
{
    return m_icon;
}

void WeatherForecastData::emitAllSignals()
{
    emit tempMinChanged(m_tempMin);
    emit tempMaxChanged(m_tempMax);
    emit timeChanged(m_time);
    emit descriptionChanged(m_description);
    emit iconChanged(m_icon);
}

void WeatherForecastData::setTempMin(int tempMin)
{
    if (m_tempMin == tempMin)
        return;

    m_tempMin = tempMin;
    emit tempMinChanged(tempMin);
}

void WeatherForecastData::setTempMax(int tempMax)
{
    if (m_tempMax == tempMax)
        return;

    m_tempMax = tempMax;
    emit tempMaxChanged(tempMax);
}

void weather::WeatherForecastData::setTime(int time)
{
    if (m_time == time)
        return;

    m_time = time;
    emit timeChanged(time);
}

void WeatherForecastData::setDescription(QString description)
{
    if (m_description == description)
        return;

    m_description = description;
    emit descriptionChanged(description);
}

void WeatherForecastData::setIcon(QString icon)
{
    if (m_icon == icon)
        return;

    m_icon = icon;
    emit iconChanged(icon);
}
