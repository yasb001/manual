#include "readdatafromdb.h"
#include <QSqlDatabase>
#include <QApplication>
#include <QDebug>

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

void ReadDataFromDB::searchSignalInfoFromDb(QString deviceName, QString signalName, bool bFuzzy)
{

}
