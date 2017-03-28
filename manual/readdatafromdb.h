#ifndef READDATAFROMDB_H
#define READDATAFROMDB_H

#include <QObject>
#include <QSqlDatabase>
#include <signalitembean.h>
#include <QMap>
#include <QVector>

class ReadDataFromDB : public QObject
{
    Q_OBJECT
public:
    static ReadDataFromDB* getInstance();


private:
    static ReadDataFromDB* instance;
    explicit ReadDataFromDB(QObject *parent = 0);
    QMap<QString, SignalItemBean*> mSearchResultMap;


signals:
    void deviceChanged(QList<QString> devices);
    void signalChanged(QList<QString> signalInfos);

public slots:
    void searchSignalInfoFromDb(QString deviceName,
                                QString signalName, bool bFuzzy);

    void writeSignalInfoToDb(SignalItemBean &item);

    void insertSignalInfoToDb(SignalItemBean &item);

    // 获取设备列表
    QList<QString> getDeviceNameList();
    // 获取信号名称列表
    QList<QString> getSignalNameList();

private:
    QSqlDatabase db;
    QSet<QString> mDeviceSet;

};

#endif // READDATAFROMDB_H
