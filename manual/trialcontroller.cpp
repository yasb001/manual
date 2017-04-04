#include "trialcontroller.h"
#include "common.h"
#include <QDataStream>
#include <QtNetwork>

TrialController* TrialController::interface = NULL;

TrialController::TrialController(QObject *parent) : QObject(parent)
{
    mConfigPath = Common::getPrivateDirPath();

    mUserKey = getUserKey();
    qDebug() << "mUserKey" <<mUserKey;
    mUserValue = getUserValue();
    qDebug() << "mUserValue" <<mUserValue;
    mIsTrial = true;

    mConfigFile = new QFile(mConfigPath);
    if(!mConfigFile->exists()){
        if(mConfigFile->open(QIODevice::ReadWrite)){
            QDataStream stream(mConfigFile);
            mFirstTime = mLastTime = QDateTime::currentDateTime();
            stream << QDateTime::currentDateTime();
            stream << QDateTime::currentDateTime();
            stream << mIsTrial;
            mConfigFile->close();
        }
    }else{
        if(mConfigFile->open(QIODevice::ReadWrite)){
            QDataStream stream(mConfigFile);
            stream >> mFirstTime;
            stream >> mLastTime;
            stream >> mIsTrial;
            mConfigFile->close();
        }
    }
    mEndTime = mFirstTime.addDays(mDays);
}

TrialController *TrialController::getInstance()
{
    if(NULL == interface){
        interface = new TrialController();
    }
    return interface;
}

bool TrialController::isOutTime()
{
    if(!mIsTrial){
        return false;
    }else{
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

}

int TrialController::getDaysRemaining()
{
    return QDateTime::currentDateTime().daysTo(mEndTime);
}

bool TrialController::isTrialVersion()
{
    return mIsTrial;
}

QString TrialController::getUserKey()
{
    QString addr = getMacAddress();
    return getMD5FromAddress(addr);
}

QString TrialController::getUserValue()
{
    QString value;
    QByteArray temp = mUserKey.toLatin1().toHex();
    value.append(temp);
    return value;
}

bool TrialController::registeOfficial(QString userValue)
{
    if(userValue == mUserValue){
        mIsTrial = false;
        if(mConfigFile->open(QIODevice::ReadWrite)){
            QDataStream stream(mConfigFile);
            mFirstTime = mLastTime = QDateTime::currentDateTime();
            stream << mFirstTime;
            stream << mLastTime;
            stream << mIsTrial;
            mConfigFile->close();
        }
        return true;
    }
    return false;
}

QString TrialController::getMacAddress()
{
    QString address;
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface netInterface, list) {
        if (!netInterface.isValid())
            continue;

        QNetworkInterface::InterfaceFlags flags = netInterface.flags();
        if (flags.testFlag(QNetworkInterface::IsRunning)
                    && !flags.testFlag(QNetworkInterface::IsLoopBack)) {  // 网络接口处于活动状态

            address += netInterface.name();
//            qDebug() << "Device : " << netInterface.name();  // 设备名
//            qDebug() << "HardwareAddress : " << netInterface.hardwareAddress();  // 硬件地址
//            qDebug() << "Human Readable Name : " << netInterface.humanReadableName();  // 人类可读的名字
        }
    }
    return address;
}

QString TrialController::getMD5FromAddress(QString address)
{
    QString md5;
    QByteArray bb;
    bb = QCryptographicHash::hash(address.toLatin1(), QCryptographicHash::Md5);
    md5.append(bb.toHex());
    return md5;
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




