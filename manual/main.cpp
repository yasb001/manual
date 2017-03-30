#include "mainwidget.h"
#include <QApplication>
#include <QDebug>
#include "trialcontroller.h"
#include <QMessageBox>
#include "xlsxdocument.h"
#include "xlsxformat.h"
QTXLSX_USE_NAMESPACE


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrialController trial;
    if(trial.isOutTime()){
        QMessageBox::warning(NULL, "试用过期", "您的试用期限已经过期，请联系QQ：***");
        return -1;
    }

    MainWidget w;
    w.show();

    return a.exec();
}
