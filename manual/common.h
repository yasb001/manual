#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QApplication>

class Common
{
public:
    Common() {}

    static QString getDBPath(){
        return QApplication::applicationDirPath() + "/cfg/zxc_database.db";
    }
};


#endif // COMMON_H
