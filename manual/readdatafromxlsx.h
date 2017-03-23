#ifndef READDATAFROMXLSX_H
#define READDATAFROMXLSX_H

#include <QObject>
#include <QSettings>
#include <QMap>

#include "signalitembean.h"

#include "xlsxdocument.h"
#include "xlsxformat.h"
#include "xlsxworkbook.h"
QTXLSX_USE_NAMESPACE

class ReadDataFromXlsx : public QObject
{
    Q_OBJECT
public:
    explicit ReadDataFromXlsx(QObject *parent = 0);

signals:
    void finishRead();

public slots:

private:
    void readData();
    void writeDataToDb();

    QString mConfigFilePath;
    QString mSettingCfgFilePath; // Setting
    QXlsx::Document *mDocument;

    QSettings *mCfgSetting;
    QMap<QString, SignalItemBean*> mDataMap;
};

#endif // READDATAFROMXLSX_H
