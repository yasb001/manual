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
    int getDaysRemaining();
    bool isTrialVersion();

signals:

public slots:

private:
    void updateRegesterInfo();
    QString mConfigPath;
    QFile *mConfigFile;

    const int mDays = 5;
    QDateTime mFirstTime;
    QDateTime mLastTime;
    QDateTime mEndTime;
};

#endif // TRIALCONTROLLER_H
