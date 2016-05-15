#include "weatherdata.h"

using namespace weather;

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
