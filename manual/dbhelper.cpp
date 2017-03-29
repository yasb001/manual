#include "dbhelper.h"

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

    mDataBase = QSqlDatabase::addDatabase("QSQLITE");
    mDataBase.setDatabaseName(mDBPath);
    if(!mDataBase.open())
    {
        qDebug()<<mDataBase.lastError();
    }else{
        createTablesOfDB();
    }
}

DBHelper::~DBHelper()
{
    mDataBase.close();
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


