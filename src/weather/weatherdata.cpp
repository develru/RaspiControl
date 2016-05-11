#include "weatherdata.h"

using namespace weather;

WeatherData::WeatherData() :
    m_isDataRecived(false),
    m_locationName(""),
    m_temperature(0),
    m_description("")
{
}

std::string WeatherData::locationName() const
{
    return m_locationName;
}

void WeatherData::setLocationName(const std::string &locationName)
{
    m_locationName = locationName;
}

int WeatherData::temperature() const
{
    return m_temperature;
}

void WeatherData::setTemperature(int temperature)
{
    m_temperature = temperature;
}

std::string WeatherData::description() const
{
    return m_description;
}

void WeatherData::setDescription(const std::string &description)
{
    m_description = description;
}

bool WeatherData::isDataRecived() const
{
    return m_isDataRecived;
}

void WeatherData::setIsDataRecived(bool isDataRecived)
{
    m_isDataRecived = isDataRecived;
}
