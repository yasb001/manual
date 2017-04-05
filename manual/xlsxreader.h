#ifndef XLSXREADER_H
#define XLSXREADER_H

#include <QObject>
#include <QMap>
#include "signalitembean.h"


#include "libxl/libxl.h"
using namespace libxl;

class XlsxReader : public QObject
{
    Q_OBJECT
public:
    explicit XlsxReader(QObject *parent = 0);
    static void readData(QString xlsxPath, QMap<QString, SignalItemBean *> &SignalItemMap);
    
};

#endif // XLSXREADER_H
