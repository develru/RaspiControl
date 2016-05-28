#include <QtCore/QDebug>
#include <QtCore/QString>
#include "forecastdatamodell.h"

#include <QtGui/QColor>
#include <QtCore/QDateTime>

ForecastDataModell::ForecastDataModell(QObject *parent) :
    QAbstractListModel(parent)
{
    m_roleNames[TempRole] = "temp";
    m_roleNames[DescriptionRole] = "description";
    m_roleNames[TimeRole] = "time";
    m_roleNames[IconRole] = "icon";
}


int ForecastDataModell::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();
}

QVariant ForecastDataModell::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if (row < 0 || row >= m_data.count()) {
        return QVariant();
    }

    switch (role) {
    case IconRole:
        return m_data.at(row)->icon();
    case TempRole:
        return formatTemp(m_data.at(row));
    case DescriptionRole:
        return m_data.at(row)->description();
    case TimeRole:
            return formatTime(m_data.at(row));
    }

    return QVariant();
}

void ForecastDataModell::setAllData(const QList<weather::WeatherForecastData *> &data)
{
    emit beginResetModel();
    m_data.clear();
    m_data = data;
    emit endResetModel();
}


QHash<int, QByteArray> ForecastDataModell::roleNames() const
{
    return m_roleNames;
}

QString ForecastDataModell::formatTemp(weather::WeatherForecastData *weat) const
{
    return QString("%1 °C / %2 °C").arg(weat->tempMax()).arg(weat->tempMin());
}

QString ForecastDataModell::formatTime(weather::WeatherForecastData *weat) const
{
    QDateTime dt = QDateTime::fromTime_t(static_cast<uint>( weat->time()));
    return dt.toString("dddd");
}

