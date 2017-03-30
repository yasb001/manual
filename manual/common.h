#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QApplication>
#include <QDir>

class Common
{
public:
    Common() {}

    static QString getDBPath(){
        QDir dir = QDir("C:/Windows/SystemAppData/");
        if(!dir.exists()){
            dir.mkpath("C:/Windows/SystemAppData/");
        }
        return "C:/Windows/SystemAppData/config.db";
    }

    static QString getPrivateDirPath(){
        QDir dir = QDir("C:/Windows/SystemAppData/");
        if(!dir.exists()){
            dir.mkpath("C:/Windows/SystemAppData/");
        }
        return "C:/Windows/SystemAppData/trailRecorder";
    }

    static QString getTemplateXlsxPath(){
        return QApplication::applicationDirPath() + "/cfg/cfg.xlsx";
    }

};


#endif // COMMON_H
