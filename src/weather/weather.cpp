#include "weather.h"
using namespace weather;

Weather::Weather(QObject *parent) :
    QObject(parent), m_label("Hello Richard!")
{

}

QString Weather::getWeatherData()
{

}
