#include "readdatafromxlsx.h"
#include <QFile>
#include <QApplication>
#include <QSettings>
#include <QDebug>
#include <QtSql>


ReadDataFromXlsx::ReadDataFromXlsx(QObject *parent) : QObject(parent)
{
    QString exePath = QApplication::applicationDirPath();

    mSettingCfgFilePath = "/cfg/setting.ini";
    mCfgSetting = new QSettings(exePath + mSettingCfgFilePath, QSettings ::IniFormat);

    mConfigFilePath = "/cfg/cfg.xlsx";
    QString xlsxCfgpath = exePath + mConfigFilePath;
    QFile *cfgFileXlsx = new QFile(xlsxCfgpath);
    if(cfgFileXlsx->exists()){
        mDocument = new QXlsx::Document(xlsxCfgpath);
        readData(xlsxCfgpath);
    }
}

void ReadDataFromXlsx::readData(QString cfgPath)
{
    if(NULL != mDocument){
        int row = 2;
        QString contentA = mDocument->read(row, 1).toString();
        qDebug() << contentA;
        while ("" != contentA) {
            SignalItemBean *bean = new SignalItemBean();
            bean->setOrd(mDocument->read(row, 1).toString());
            bean->setDeviceName(mDocument->read(row, 2).toString());
            bean->setSignalName(mDocument->read(row, 3).toString());
            bean->setSignalMeanning(mDocument->read(row, 4).toString());
            bean->setSignalFrom(mDocument->read(row, 5).toString());
            bean->setSignalType(mDocument->read(row, 6).toString());
            bean->setSignalConnected(mDocument->read(row, 7).toString());
            bean->setSignalReason(mDocument->read(row, 8).toString());
            bean->setSignalHandler(mDocument->read(row, 9).toString());

            mDataMap.insert(bean->ord(), bean);
            contentA = mDocument->read(row+1, 1).toString();
            row++;
        }
        writeDataToDb();
        qDebug() << mDataMap.size();
    }
}

void ReadDataFromXlsx::writeDataToDb()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(QApplication::applicationDirPath() +  "/cfg/zxc_database.db");
    if(!database.open())
    {
        qDebug()<<database.lastError();
        qFatal("failed to connect.") ;
    }
    else
    {

        QString create_DeviceTable = "CREATE TABLE device (\
                                        id int primary key, \
                                        devicename varchar(30)\
                                       )";
        QString create_SignalTable = "CREATE TABLE signal (\
                                        id int NOT NULL, signalname varchar(50), deviceId int, \
                                        PRIMARY KEY(id), FOREIGN KEY (deviceId) REFERENCES device (id));";
        QString create_SignalInfoTable = "CREATE TABLE signalInfo (id varchar(100) NOT NULL, signalid varchar(100), \
                                          signalfrom varchar(500), signaltype varchar(100), signalmeaning varchar(1000),\
                                          signalconnected varchar(1000), signalreason varchar(1000), \
                                           signalhandler varchar(1000))";

        QSqlQuery sql_query;
        sql_query.prepare(create_DeviceTable);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"device created!";
        }

        sql_query.prepare(create_SignalTable);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"signal created!";
        }

        sql_query.prepare(create_SignalInfoTable);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"signalInfo created!";
        }

        writeToDBTable(database);

        database.close();

    }
}


void ReadDataFromXlsx::writeToDBTable(QSqlDatabase database){
    QString insert_device = "INSERT INTO device VALUES(?, ?)";
    QSqlQuery sql_query_insert_device;
    sql_query_insert_device.prepare(insert_device);

    QString insert_signal = "INSERT INTO signal VALUES(?, ?, ?)";
    QSqlQuery sql_query_insert_signal;
    sql_query_insert_signal.prepare(insert_signal);


    QString insert_signalInfo = "INSERT INTO signalInfo VALUES(?, ?, ?, ?, ?, ?, ?, ?)";
    QSqlQuery sql_query_insert_signalInfo;
    sql_query_insert_signalInfo.prepare(insert_signalInfo);

    if(database.transaction()){
        QMap<QString, SignalItemBean*>::iterator itDataBean = mDataMap.begin();
        while (itDataBean != mDataMap.end()) {
            QString device_uuid = QUuid::createUuid().toString();
            SignalItemBean *bean = itDataBean.value();
            QString deviceName = bean->deviceName();
            QString signalName = bean->signalName();
            QString signalFrom = bean->signalFrom();
            QString signalType = bean->signalType();
            QString signalMeaning = bean->signalMeanning();
            QString signalConnected = bean->signalConnected();
            QString signalReason = bean->signalReason();
            QString signalHandler = bean->signalHandler();


            // 缓存入device
            sql_query_insert_device.bindValue(0, device_uuid);
            sql_query_insert_device.bindValue(1, deviceName);
            sql_query_insert_device.exec();

            // 缓存入signal
            QString signal_uuid = QUuid::createUuid().toString();
            sql_query_insert_signal.bindValue(0, signal_uuid);
            sql_query_insert_signal.bindValue(1, signalName);
            sql_query_insert_signal.bindValue(2, device_uuid);
            sql_query_insert_signal.exec();

            // 缓存入signalInfo
            QString signalInfo_uuid = QUuid::createUuid().toString();
            sql_query_insert_signalInfo.bindValue(0, signalInfo_uuid);
            sql_query_insert_signalInfo.bindValue(1, signal_uuid);
            sql_query_insert_signalInfo.bindValue(2, signalFrom);
            sql_query_insert_signalInfo.bindValue(3, signalType);
            sql_query_insert_signalInfo.bindValue(4, signalMeaning);
            sql_query_insert_signalInfo.bindValue(5, signalConnected);
            sql_query_insert_signalInfo.bindValue(6, signalReason);
            sql_query_insert_signalInfo.bindValue(7, signalHandler);
            sql_query_insert_signalInfo.exec();

            itDataBean++;
        }

        database.commit();
    }

}
