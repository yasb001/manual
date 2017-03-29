#include "readdatafromxlsx.h"
#include <QFile>
#include <QApplication>
#include <QSettings>
#include <QDebug>
#include <QtSql>


ReadDataFromXlsx::ReadDataFromXlsx(QObject *parent) : QObject(parent){
}

void ReadDataFromXlsx::readData(QString xlsxPath,
                     QMap<QString, SignalItemBean *> &SignalItemMap){
    QXlsx::Document* mDocument = new QXlsx::Document(xlsxPath);
    if(NULL != mDocument){
        int row = 2;
        QString contentA = mDocument->read(row, 1).toString();
        qDebug() << contentA;
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

            SignalItemMap.insert(bean->ord(), bean);
            contentA = mDocument->read(row+1, 1).toString();
            row++;
        }
    }
}
