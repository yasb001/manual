#include "trialcontroller.h"
#include "common.h"
#include <QDataStream>

TrialController::TrialController(QObject *parent) : QObject(parent)
{
    mConfigPath = Common::getPrivateDirPath();
    mConfigFile = new QFile(mConfigPath);
    if(!mConfigFile->exists()){
        if(mConfigFile->open(QIODevice::ReadWrite)){
            QDataStream stream(mConfigFile);
            mFirstTime = mLastTime = QDateTime::currentDateTime();
            stream << QDateTime::currentDateTime();
            stream << QDateTime::currentDateTime();
            mConfigFile->close();
        }
    }else{
        if(mConfigFile->open(QIODevice::ReadWrite)){
            QDataStream stream(mConfigFile);
            stream >> mFirstTime;
            stream >> mLastTime;
            mConfigFile->close();
        }
    }
    mEndTime = mFirstTime.addDays(mDays);
}

bool TrialController::isOutTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    if(currentTime > mLastTime){
        if(currentTime > mFirstTime.addDays(mDays)){
            return true;
        }else{
            updateRegesterInfo();
            return false;
        }
    }else{
       return true;
    }
}

int TrialController::getDaysRemaining()
{
    return QDateTime::currentDateTime().daysTo(mEndTime);
}

bool TrialController::isTrialVersion()
{
    return true;
}

void TrialController::updateRegesterInfo()
{
    if(mConfigFile == NULL){
        mConfigFile = new QFile(mConfigPath);
    }
    if(mConfigFile->open(QIODevice::ReadWrite)){
        QDataStream stream(mConfigFile);
        stream << mFirstTime;
        stream << QDateTime::currentDateTime();
        mConfigFile->close();
    }
}




