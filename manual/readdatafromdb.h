#ifndef READDATAFROMDB_H
#define READDATAFROMDB_H

#include <QObject>
#include <QSqlDatabase>

class ReadDataFromDB : public QObject
{
    Q_OBJECT
public:
    explicit ReadDataFromDB(QObject *parent = 0);

signals:

public slots:
    void searchSignalInfoFromDb(QString deviceName, QString signalName, bool bFuzzy);

private:
    QSqlDatabase db;

};

#endif // READDATAFROMDB_H
