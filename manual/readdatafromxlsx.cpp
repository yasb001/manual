#include "readdatafromxlsx.h"
#include <QFile>
#include <QApplication>
#include <QSettings>


ReadDataFromXlsx::ReadDataFromXlsx(QObject *parent) : QObject(parent)
{
    mConfigFilePath = "/cfg/cfg.xlsx";
    mSettingCfgFilePath = "/cfg/setting.ini";
    QString exePath = QApplication::applicationDirPath();

    mCfgSetting = new QSettings(exePath + mSettingCfgFilePath, QSettings ::IniFormat);

    QFile *cfgFileXlsx = new QFile(exePath + mConfigFilePath);
    if(cfgFileXlsx->exists()){
        mDocument = new QXlsx::Document(cfgFileXlsx);
        readData();
    }
}

void ReadDataFromXlsx::readData()
{
    if(NULL != mDocument && NULL != mCfgSetting){
//        QString minColumn = mCfgSetting->value("ExcelColumn/MinColumn").toInt();
//        QString maxColumn = mCfgSetting->value("ExcelColumn/MaxColumn").toInt();

        QXlsx::Worksheet *sheet = mDocument->sheet("");
        QString contentA1 = mDocument->read("A2").toString();
        QString contentA = mDocument->read(row, 'A').toString();
        while ("" != contentA) {
            SignalItemBean *bean = new SignalItemBean();
            bean->setOrd(mDocument->read(row, 1).toString());
            bean->setDeviceName(mDocument->read(row, 2).toString());
            bean->setSignalName(mDocument->read(row, 3).toString());
            bean->setSignalMeanning(mDocument->read(row, 4).toString());
            bean->setSignalFrom(mDocument->read(row, 5).toString());
            bean->setSignalType(mDocument->read(row, 6).toString());
            bean->setSignalConnected(mDocument->read(row, 7).toString());
            bean->setSignalReason(mDocument->read(row, 8).toString());
            bean->setSignalHandler(mDocument->read(row, 9).toString());

            mDataMap.insert(bean->ord(), bean);
            contentA = mDocument->read(row+1, 1).toString();
            row++;
        }
    }
}

void ReadDataFromXlsx::writeDataToDb()
{

}
