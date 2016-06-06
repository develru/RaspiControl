#include "currenttime.h"
#include <QtCore/QTime>

using namespace timespace;

CurrentTime::CurrentTime(QObject *parent) :
    QObject(parent),
    m_timer(new QTimer(this))
{
    connect(m_timer.get(), SIGNAL(timeout()), this, SLOT(refreshTime()));
    m_timer->start(10000);
}

CurrentTime::~CurrentTime()
{
}

QString CurrentTime::time() const
{
    return QTime::currentTime().toString("h:mm");
}

void CurrentTime::refreshTime()
{
    emit timeChanged();
}

