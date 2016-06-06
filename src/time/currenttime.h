#ifndef CURRENTTIME_H
#define CURRENTTIME_H

#include <memory>
#include <QtCore/QObject>
#include <QtCore/QTimer>

namespace timespace {

    class CurrentTime : public QObject
    {
        Q_OBJECT
            Q_PROPERTY(QString time READ time NOTIFY timeChanged)
        public:
            explicit CurrentTime(QObject *parent = 0);
            ~CurrentTime ();

            QString time() const;

        signals:
            void timeChanged();

        public slots:
            void refreshTime();

        private:
            std::unique_ptr<QTimer> m_timer;
    };
}
#endif /* ifndef CURRENTTIME_H */
