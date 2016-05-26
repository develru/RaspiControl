#ifndef FORECASTDATAMODELL_H
#define FORECASTDATAMODELL_H

#include <QAbstractListModel>
#include "weatherforecastdata.h"

class ForecastDataModell : public QAbstractListModel
{
    Q_OBJECT
public:
    enum RoleNames {
            TempRole = Qt::UserRole,
            DescriptionRole = Qt::UserRole+2,
            TimeRole = Qt::UserRole+3,
            IconRole = Qt::UserRole+4
        };
    explicit ForecastDataModell(QObject *parent=0);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void setAllData(const QList<weather::WeatherForecastData *> &data);

protected:
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QString formatTemp(weather::WeatherForecastData *weat) const;
    QString formatTime(weather::WeatherForecastData *weat) const;
    QList<weather::WeatherForecastData*> m_data;
    QHash<int, QByteArray> m_roleNames;

};

#endif // FORECASTDATAMODELL_H
