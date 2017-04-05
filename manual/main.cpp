#include "mainwidget.h"
#include <QApplication>
#include <QDebug>
#include <QLibrary>
#include "trialcontroller.h"
#include <QMessageBox>
#include "registerdialog.h"
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RegisterDialog dialog;
    TrialController *trial = TrialController::getInstance();
    if(trial->isTrialVersion()){
        if(trial->isOutTime()){
            dialog.setUserKey(trial->getUserKey());
            dialog.exec();
            if(!dialog.bRegisteOk()){
                return -1;
            }
        }else
        {
            QMessageBox::information(NULL, "试用期提示", QString("您的试用期剩余%1天，若注册正式版，请联系QQ：595087268").arg(trial->getDaysRemaining()));
        }
    }


    MainWidget w;
    w.show();

    return a.exec();

}


