#include "xlsxreader.h"

XlsxReader::XlsxReader(QObject *parent) :
    QObject(parent)
{

}

void XlsxReader::readData(QString xlsxPath,
                     QMap<QString, SignalItemBean *> &SignalItemMap){

    Book* book = xlCreateBook();
    if(book->load(xlsxPath.toStdString().data()))
       {
          Sheet* sheet = book->getSheet(0);
          if(sheet)
          {
              int row = 1;
              CellType cellType = sheet->cellType(row, 1);
              while(cellType != CELLTYPE_EMPTY && cellType != CELLTYPE_ERROR){
                  SignalItemBean *bean = new SignalItemBean();
                  bean->setOrd(sheet->readStr(row, 1));
                  bean->setDeviceName(sheet->readStr(row, 2));
                  bean->setSignalName(sheet->readStr(row, 3));
                  bean->setSignalMeanning(sheet->readStr(row, 4));
                  bean->setSignalFrom(sheet->readStr(row, 5));
                  bean->setSignalType(sheet->readStr(row, 6));
                  bean->setSignalConnected(sheet->readStr(row, 7));
                  bean->setSignalReason(sheet->readStr(row, 8));
                  bean->setSignalHandler(sheet->readStr(row, 9));


                  SignalItemMap.insert(bean->ord(), bean);
                  cellType = sheet->cellType(row+1, 1);
                  row++;
              }
           }
       }

    book->release();
}
