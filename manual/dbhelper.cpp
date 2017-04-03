#include "dbhelper.h"
#include "readdatafromxlsx.h"
#include <QDebug>
#include <QSqlQuery>
#include <QUuid>
#include <QSqlError>

DBHelper* DBHelper::instance = NULL;

DBHelper *DBHelper::getInstance()
{
    if(NULL == instance){
        instance = new DBHelper();
    }
    return instance;
}

QSqlDatabase DBHelper::getDataBase()
{
    return mDataBase;
}


DBHelper::DBHelper(QObject *parent) : QObject(parent)
{
    mDBPath = Common::getDBPath();
    QFile *dbFile = new QFile(mDBPath);
    if(!dbFile->exists()){
        mDataBase = QSqlDatabase::addDatabase("QSQLITE");
        mDataBase.setDatabaseName(mDBPath);
        if(!mDataBase.open())
        {
            qDebug() << "DBHelper 数据库打开失败";
            return;
        }
        createTablesOfDB();
        initDBDataFromCfg();
    }else{
        mDataBase = QSqlDatabase::addDatabase("QSQLITE");
        mDataBase.setDatabaseName(mDBPath);
        if(!mDataBase.open())
        {
            qDebug() << "DBHelper 数据库打开失败";
            return;
        }
    }
}

DBHelper::~DBHelper()
{
    mDataBase.close();
}


void DBHelper::updateSignalInfoToDb(SignalItemBean &item)
{
    QString update_signalInfo = "UPDATE signalInfo SET signalfrom=?, signaltype=?, signalmeaning=?, signalconnected=?, signalreason=?, signalhandler=? WHERE id=?";
    QSqlQuery sql_query_update_signalInfo;
    sql_query_update_signalInfo.prepare(update_signalInfo);
    sql_query_update_signalInfo.bindValue(0, item.signalFrom());
    sql_query_update_signalInfo.bindValue(1, item.signalType());
    sql_query_update_signalInfo.bindValue(2, item.signalMeanning());
    sql_query_update_signalInfo.bindValue(3, item.signalConnected());
    sql_query_update_signalInfo.bindValue(4, item.signalReason());
    sql_query_update_signalInfo.bindValue(5, item.signalHandler());
    sql_query_update_signalInfo.bindValue(6, item.ord());

    if(!sql_query_update_signalInfo.exec()){
        qDebug() << "更新数据失败";
    }
}

void DBHelper::insertSignalInfoToDb(SignalItemBean &item)
{
    // 判断是否含有设备
    QList<QString> devicelist;
    getDeviceNameList(devicelist);
    if(!mDeviceSet.contains(item.deviceName())){
        QString uuid = QUuid::createUuid().toString();
        QString insert_Device = "INSERT INTO device VALUES(?, ?)";
        QSqlQuery sql_query_insert_device;
        sql_query_insert_device.prepare(insert_Device);
        sql_query_insert_device.bindValue(0, uuid);
        sql_query_insert_device.bindValue(1, item.deviceName());
        if(!sql_query_insert_device.exec()){
            qDebug() << "添加设备失败";
            return;
        }
        devicelist.append(item.deviceName());
        emit deviceChanged();
    }

    // 插入信号

    // 判断数据库中是否存在信号
    QMap<QString, SignalItemBean*> resultMap;
    if(!searchSignalInfoFromDb(item.deviceName(), item.signalName(), false, resultMap)){
        QString insert_signalInfo = "INSERT INTO signalInfo VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)";
        QSqlQuery sql_query_insert_signalInfo;
        sql_query_insert_signalInfo.prepare(insert_signalInfo);

        sql_query_insert_signalInfo.bindValue(0, item.ord());
        sql_query_insert_signalInfo.bindValue(1, item.signalName());
        sql_query_insert_signalInfo.bindValue(2, item.signalFrom());
        sql_query_insert_signalInfo.bindValue(3, item.signalType());
        sql_query_insert_signalInfo.bindValue(4, item.signalMeanning());
        sql_query_insert_signalInfo.bindValue(5, item.signalConnected());
        sql_query_insert_signalInfo.bindValue(6, item.signalReason());
        sql_query_insert_signalInfo.bindValue(7, item.signalHandler());
        sql_query_insert_signalInfo.bindValue(8, item.deviceName());

        if(!sql_query_insert_signalInfo.exec()){
            qDebug() << "添加信号失败";
            return;
        }
        emit signalChanged();
    }
}

void DBHelper::insertSignalInfoListToDb(QMap<QString, SignalItemBean *> &itemMap)
{
    QMap<QString, SignalItemBean *>::iterator itSignal = itemMap.begin();
    if(mDataBase.transaction()){
        while(itSignal != itemMap.end()){
            insertSignalInfoToDb(*itSignal.value());
            itSignal++;
        }

        mDataBase.commit();
    }

}

bool DBHelper::searchSignalInfoFromDb(QString deviceName, QString signalName,
                                      bool bFuzzy, QMap<QString, SignalItemBean*> &searchResultMap)
{
    bool bFind = false;
    QSqlQuery sql_query_select_signalInfo;
    QString select_signalInfo;
    if(signalName.isEmpty()){
        if(deviceName == "全部设备"){
            select_signalInfo = "SELECT * FROM signalInfo";
            sql_query_select_signalInfo.prepare(select_signalInfo);
        }else{
            select_signalInfo = "SELECT * FROM signalInfo WHERE devicename=?";
            sql_query_select_signalInfo.prepare(select_signalInfo);
            sql_query_select_signalInfo.bindValue(0, deviceName);
        }

    }else{
        if(deviceName == "全部设备"){
            select_signalInfo = "SELECT * FROM signalInfo WHERE signalname LIKE ?";
            sql_query_select_signalInfo.prepare(select_signalInfo);
            sql_query_select_signalInfo.bindValue(0, "%" + signalName + "%");
        }else{
            if(bFuzzy){
                select_signalInfo = "SELECT * FROM signalInfo WHERE devicename=? AND signalname LIKE ?";
                sql_query_select_signalInfo.prepare(select_signalInfo);
                sql_query_select_signalInfo.bindValue(0, deviceName);
                sql_query_select_signalInfo.bindValue(1, "%" + signalName + "%");
            }else{
                select_signalInfo = "SELECT * FROM signalInfo WHERE devicename=? AND signalname=?";
                sql_query_select_signalInfo.prepare(select_signalInfo);
                sql_query_select_signalInfo.bindValue(0, deviceName);
                sql_query_select_signalInfo.bindValue(1, signalName);
            }

        }


    }


    if(sql_query_select_signalInfo.exec()){
        while (sql_query_select_signalInfo.next()) {

            SignalItemBean *item = new SignalItemBean();
            item->setOrd(sql_query_select_signalInfo.value(0).toString());
            item->setSignalName(sql_query_select_signalInfo.value(1).toString());
            item->setSignalFrom(sql_query_select_signalInfo.value(2).toString());
            item->setSignalType(sql_query_select_signalInfo.value(3).toString());
            item->setSignalMeanning(sql_query_select_signalInfo.value(4).toString());
            item->setSignalConnected(sql_query_select_signalInfo.value(5).toString());
            item->setSignalReason(sql_query_select_signalInfo.value(6).toString());
            item->setSignalHandler(sql_query_select_signalInfo.value(7).toString());
            item->setDeviceName(sql_query_select_signalInfo.value(8).toString());

            searchResultMap.insert(item->ord(), item);
            bFind = true;
        }
    }
    return bFind;
}

void DBHelper::getDeviceNameList(QList<QString> &deviceList)
{
    mDeviceSet.clear();
    deviceList.clear();
    QString select_Device = "SELECT devicename FROM device";
    QSqlQuery sql_query_selectDevice;
    sql_query_selectDevice.prepare(select_Device);
    sql_query_selectDevice.exec();
    while(sql_query_selectDevice.next()){
        mDeviceSet.insert(sql_query_selectDevice.value(0).toString());
        deviceList.append(sql_query_selectDevice.value(0).toString());
    }
}

void DBHelper::getSignalNameList(QList<QString> &signalList)
{
    mSignalSet.clear();
    signalList.clear();
    QString select_Signal = "SELECT signalname FROM signalInfo";
    QSqlQuery sql_query_selectSignal;
    sql_query_selectSignal.prepare(select_Signal);
    sql_query_selectSignal.exec();
    while(sql_query_selectSignal.next()){
        mSignalSet.insert(sql_query_selectSignal.value(0).toString());
    }
    signalList = mSignalSet.toList();
}




void DBHelper::createTablesOfDB()
{
    QString create_DeviceTable = "CREATE TABLE device (\
                                    id int primary key, \
                                    devicename varchar(30)\
                                   )";

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


    QString create_SignalInfoTable = "CREATE TABLE signalInfo (id varchar(100) NOT NULL, signalname varchar(100), \
                                      signalfrom varchar(500), signaltype varchar(100), signalmeaning varchar(1000),\
                                      signalconnected varchar(1000), signalreason varchar(1000), \
                                       signalhandler varchar(1000), devicename varchar(100))";

    sql_query.prepare(create_SignalInfoTable);
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        qDebug()<<"signalInfo created!";
    }
}

void DBHelper::initDBDataFromCfg()
{
    QString cfgPath = Common::getTemplateXlsxPath();
    QMap<QString, SignalItemBean*> signalMap;
    ReadDataFromXlsx::readData(cfgPath, signalMap);
    insertSignalInfoListToDb(signalMap);
}


