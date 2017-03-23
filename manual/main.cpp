#include "mainwidget.h"
#include <QApplication>
#include <QDebug>

#include "xlsxdocument.h"
#include "xlsxformat.h"
QTXLSX_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget w;
    w.show();

    return a.exec();
}
