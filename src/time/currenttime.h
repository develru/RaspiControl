#ifndef CURRENTTIME_H
#define CURRENTTIME_H

#include <QtCore/QObject>

namespace timespace {

    class CurrentTime : public QObject
    {
        Q_OBJECT
    public:
        explicit CurrentTime(QObject *parent = 0);
        ~CurrentTime ();

    private:
        /* data */
    };
}
#endif /* ifndef CURRENTTIME_H */
