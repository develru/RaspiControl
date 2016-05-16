#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <string>
#include <vector>

namespace weather {

class WeatherForecastData
{
public:
    WeatherForecastData();

    int tempMin() const;
    void setTempMin(int tempMin);

    int tempMax() const;
    void setTempMax(int tempMax);

    int time() const;
    void setTime(int time);

    std::string description() const;
    void setDescription(const std::string &description);

    std::string icon() const;
    void setIcon(const std::string &icon);

private:
    int m_tempMin;
    int m_tempMax;
    int m_time;
    std::string m_description;
    std::string m_icon;
};

class WeatherData
{
public:
    WeatherData();

    std::string locationName() const;
    void setLocationName(const std::string &locationName);

    int temperature() const;
    void setTemperature(int temperature);

    std::string description() const;
    void setDescription(const std::string &description);

    bool isDataRecived() const;

    std::string icon() const;
    void setIcon(const std::string &icon);

    std::vector<WeatherForecastData> forecastData() const;
    void addForecastData(const WeatherForecastData &weatherForecast);

private:
    bool m_isDataRecived;
    std::string m_locationName;
    int m_temperature;
    std::string m_description;
    std::string m_icon;
    std::vector<WeatherForecastData> m_forecastData;
};

}

#endif // WEATHERDATA_H
