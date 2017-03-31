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
    if(trial.isTrialVersion()){
        if(trial.isOutTime()){
            QMessageBox::warning(NULL, "试用过期", "您的试用期限已经过期，请联系QQ：595087268");
            return -1;
        }

        QMessageBox::information(NULL, "试用期提示", QString("您的试用期剩余%1天，若注册正式版，请联系QQ：595087268").arg(trial.getDaysRemaining()));
    }

    MainWidget w;
    w.show();

    return a.exec();
}
