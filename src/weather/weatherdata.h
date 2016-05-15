#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <string>

namespace weather {

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

private:
    bool m_isDataRecived;
    std::string m_locationName;
    int m_temperature;
    std::string m_description;
    std::string m_icon;
};

}

#endif // WEATHERDATA_H
