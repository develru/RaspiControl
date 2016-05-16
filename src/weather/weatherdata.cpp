#include "weatherdata.h"

using namespace weather;

WeatherForecastData::WeatherForecastData() :
    m_tempMin(0),
    m_tempMax(0),
    m_time(0),
    m_description(""),
    m_icon("")
{
}

int WeatherForecastData::tempMax() const
{
    return m_tempMax;
}

int WeatherForecastData::tempMin() const
{
    return m_tempMin;
}

int WeatherForecastData::time() const
{
    return m_time;
}

std::string WeatherForecastData::description() const
{
    return  m_description;
}

std::string WeatherForecastData::icon() const
{
    return m_icon;
}

void WeatherForecastData::setDescription(const std::string &description)
{
    m_description = description;
}

void WeatherForecastData::setIcon(const std::string &icon)
{
    m_icon = icon;
}

void WeatherForecastData::setTempMax(int tempMax)
{
    m_tempMax = tempMax;
}

void WeatherForecastData::setTempMin(int tempMin)
{
    m_tempMin = tempMin;
}

void WeatherForecastData::setTime(int time)
{
    m_time = time;
}

WeatherData::WeatherData() :
    m_isDataRecived(false),
    m_locationName(""),
    m_temperature(0),
    m_description(""),
    m_icon("")
{
}

std::string WeatherData::locationName() const
{
    return m_locationName;
}

void WeatherData::setLocationName(const std::string &locationName)
{
    if (!m_isDataRecived)
        m_isDataRecived = true;
    m_locationName = locationName;
}

int WeatherData::temperature() const
{
    return m_temperature;
}

void WeatherData::setTemperature(int temperature)
{
    if (!m_isDataRecived)
        m_isDataRecived = true;
    m_temperature = temperature;
}

std::string WeatherData::description() const
{
    return m_description;
}

void WeatherData::setDescription(const std::string &description)
{
    if (!m_isDataRecived)
        m_isDataRecived = true;
    m_description = description;
}

bool WeatherData::isDataRecived() const
{
    return m_isDataRecived;
}

std::string WeatherData::icon() const
{
    return m_icon;
}

void WeatherData::setIcon(const std::string &icon)
{
    if (!m_isDataRecived)
            m_isDataRecived = true;
    m_icon = icon;
}

std::vector<WeatherForecastData> WeatherData::forecastData() const
{
    return m_forecastData;
}

void WeatherData::addForecastData(const WeatherForecastData &weatherForecast)
{
    m_forecastData.push_back(weatherForecast);
}

