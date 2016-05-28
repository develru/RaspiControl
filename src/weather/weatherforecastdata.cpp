#include "weatherforecastdata.h"

using namespace weather;

WeatherForecastData::WeatherForecastData() :
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

void WeatherForecastData::setTempMin(int tempMin)
{
    if (m_tempMin == tempMin)
        return;

    m_tempMin = tempMin;
}

void WeatherForecastData::setTempMax(int tempMax)
{
    if (m_tempMax == tempMax)
        return;

    m_tempMax = tempMax;
}

void weather::WeatherForecastData::setTime(int time)
{
    if (m_time == time)
        return;

    m_time = time;
}

void WeatherForecastData::setDescription(QString description)
{
    if (m_description == description)
        return;

    m_description = description;
}

void WeatherForecastData::setIcon(QString icon)
{
    if (m_icon == icon)
        return;

    m_icon = icon;
}
