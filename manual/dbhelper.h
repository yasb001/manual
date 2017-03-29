#ifndef DBHELPER_H
#define DBHELPER_H

#include <QObject>
#include "common.h"
#include <QSqlDatabase>

class DBHelper : public QObject
{
    Q_OBJECT
public:
    static DBHelper* getInstance();
    QSqlDatabase getDataBase();

private:
    explicit DBHelper(QObject *parent = 0);
    ~DBHelper();
    void createTablesOfDB();

    static DBHelper* instance;
    QString mDBPath;
    QSqlDatabase mDataBase;

signals:

public slots:
};

#endif // DBHELPER_H
