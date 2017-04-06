#ifndef TRIALCONTROLLER_H
#define TRIALCONTROLLER_H

#include <QObject>
#include <QFile>
#include <QDateTime>

class TrialController : public QObject
{
    Q_OBJECT
public:
    static TrialController* getInstance();

    bool isOutTime();
    int getDaysRemaining();
    bool isTrialVersion();

    QString getUserKey();
    QString getUserValue();
    bool    registeOfficial(QString userValue);

signals:

    public slots:

private:
    TrialController(QObject *parent = 0);
    QString getMacAddress();
    QString getMD5FromAddress(QString address);
    void updateRegesterInfo();

    static TrialController* interface;

    QString mConfigPath;
    QFile *mConfigFile;

    static const int mDays = 5;
    QDateTime mFirstTime;
    QDateTime mLastTime;
    QDateTime mEndTime;

    QString mUserKey;
    QString mUserValue;
    bool mIsTrial;
};

#endif // TRIALCONTROLLER_H
