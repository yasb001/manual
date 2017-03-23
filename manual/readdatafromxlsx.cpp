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
    database.setDatabaseName("zxc_database.db");
    if(!database.open())
    {
        qDebug()<<database.lastError();
        qFatal("failed to connect.") ;
    }
    else
    {
        QString create_DeviceTable = "create table device (id int primary key, devicename varchar(30))";
//        QString create_SignalTable = "create table signal (id int primary key, signalname varchar(50), deviceId int forgin key)";
//        QString create_DeviceTable = "create table signalinfo (id int primary key, name varchar(30))";

        QSqlQuery sql_query;
        sql_query.prepare(create_DeviceTable);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"table created!";
        }

        database.close();

    }
}
