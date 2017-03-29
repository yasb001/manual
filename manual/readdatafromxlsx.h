#ifndef READDATAFROMXLSX_H
#define READDATAFROMXLSX_H

#include <QObject>
#include <QSettings>
#include <QMap>
#include <QSqlDatabase>

#include "signalitembean.h"

#include "xlsxdocument.h"
#include "xlsxformat.h"
QTXLSX_USE_NAMESPACE

class ReadDataFromXlsx : public QObject
{
    Q_OBJECT
public:
    explicit ReadDataFromXlsx(QObject *parent = 0);
    static void readData(QString xlsxPath,
        QMap<QString, SignalItemBean*> &SignalItemMap);
};

#endif // READDATAFROMXLSX_H
