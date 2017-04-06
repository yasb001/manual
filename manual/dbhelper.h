#ifndef DBHELPER_H
#define DBHELPER_H

#include <QObject>
#include <QSqlDatabase>
#include <QMap>
#include <QList>
#include <QSet>

#include "common.h"
#include "signalitembean.h"

class DBHelper : public QObject
{
    Q_OBJECT
public:
    static DBHelper* getInstance();
    QSqlDatabase getDataBase();
    void updateSignalInfoToDb(SignalItemBean &item);
    void insertSignalInfoToDb(SignalItemBean &item);
    void insertSignalInfoListToDb(QMap<QString, SignalItemBean*> &itemMap);
    bool searchSignalInfoFromDb(QString deviceName, QString signalName,
                                bool bFuzzy, QMap<QString, SignalItemBean *> &searchResultMap);


    void getDeviceNameList(QList<QString> &deviceList);
    void getSignalNameList(QList<QString> &signalList);
private:
    explicit DBHelper(QObject *parent = 0);
    ~DBHelper();
    void createTablesOfDB();
    void initDBDataFromCfg();


    static DBHelper* instance;
    QString mDBPath;
    QSqlDatabase mDataBase;
    QSet<QString> mDeviceSet;
    QSet<QString> mSignalSet;

signals:
    void signalChanged();
    void deviceChanged();

public slots:
};

#endif // DBHELPER_H
