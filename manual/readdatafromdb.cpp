#include "readdatafromdb.h"
#include <QSqlDatabase>
#include <QApplication>
#include <QDebug>
#include <QSqlQuery>
#include <QUuid>


ReadDataFromDB* ReadDataFromDB::instance = NULL;

ReadDataFromDB* ReadDataFromDB::getInstance()
{
    if(NULL == instance){
        instance = new ReadDataFromDB();
    }
    return instance
}

ReadDataFromDB::ReadDataFromDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString appDir = QApplication::applicationDirPath();
    db.setDatabaseName(appDir + "/cfg/zxc_database.db");
    if(!db.open()){
        qDebug() << "readDataFromDB       数据库打开失败";
    }
    else{
        qDebug() << "readDataFromDB       数据库打开成功";
    }
}

void ReadDataFromDB::searchSignalInfoFromDb(QString deviceName,
                                            QString signalName, bool bFuzzy)
{
    mSearchResultMap.clear();

    QSqlQuery sql_query_select_signalInfo;
    QString select_signalInfo;
    if(bFuzzy){
        select_signalInfo = "SELECT * FROM signalInfo WHERE devicename LIKE ? AND signalname LIKE ?";
        sql_query_select_signalInfo.prepare(select_signalInfo);
        sql_query_select_signalInfo.bindValue(0, "%" + deviceName + "%");
        sql_query_select_signalInfo.bindValue(1, "%" + signalName + "%");
    }else{
        select_signalInfo = "SELECT * FROM signalInfo WHERE devicename=? AND signalname=?";
        sql_query_select_signalInfo.prepare(select_signalInfo);
        sql_query_select_signalInfo.bindValue(0, deviceName);
        sql_query_select_signalInfo.bindValue(1, signalName);
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

            qDebug() << "11111111111" << item->signalName();
            mSearchResultMap.insert(item->ord(), item);
        }
    }

}

QList<QString> ReadDataFromDB::getDeviceNameList(){
    QList<QString> deviceList;
    mDeviceSet.clear();
    QString select_Device = "SELECT devicename FROM device";
    QSqlQuery sql_query_selectDevice;
    sql_query_selectDevice.prepare(select_Device);
    sql_query_selectDevice.exec();
    while(sql_query_selectDevice.next()){
        mDeviceSet.insert(sql_query_selectDevice.value(0).toString());
        deviceList.append(sql_query_selectDevice.value(0).toString());
    }

    return deviceList;
}

QList<QString> ReadDataFromDB::getSignalNameList(){
    QSet<QString> signalSet;
    QString select_Signal = "SELECT signalname FROM signalInfo";
    QSqlQuery sql_query_selectSignal;
    sql_query_selectSignal.prepare(select_Signal);
    sql_query_selectSignal.exec();
    while(sql_query_selectSignal.next()){
        signalSet.insert(sql_query_selectSignal.value(0).toString());
    }
    qDebug() << "Signal" << signalSet.toList();
    return signalSet.toList();
}

void ReadDataFromDB::writeSignalInfoToDb(SignalItemBean &item)
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


void ReadDataFromDB::insertSignalInfoToDb(SignalItemBean &item){
    // 判断是否含有设备
    QList<QString> list = getDeviceNameList();
    if(!mDeviceSet.find(item.deviceName())){
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
        list.append(item.deviceName());
        emit deviceChanged(list);
    }

    // 插入信号
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
}
