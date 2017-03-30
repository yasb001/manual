#ifndef TRIALCONTROLLER_H
#define TRIALCONTROLLER_H

#include <QObject>
#include <QFile>
#include <QDateTime>

class TrialController : public QObject
{
    Q_OBJECT
public:
    explicit TrialController(QObject *parent = 0);
    bool isOutTime();

signals:

public slots:

private:
    void updateRegesterInfo();
    QString mConfigPath;
    QFile *mConfigFile;

    const int mDays = 15;
    QDateTime mFirstTime;
    QDateTime mLastTime;
};

#endif // TRIALCONTROLLER_H
