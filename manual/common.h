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

    static QString getTemplateXlsxPath(){
        return QApplication::applicationDirPath() + "/cfg/cfg.xlsx";
    }
};


#endif // COMMON_H
