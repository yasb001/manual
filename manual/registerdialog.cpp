#include "registerdialog.h"
#include "ui_registerdialog.h"
#include <QMessageBox>

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    mBeRegiste = false;
    ui->setupUi(this);
    mTrialController = TrialController::getInstance();
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::setUserKey(QString userKey)
{
    ui->lineEdit_UserCode->setText(userKey);
}

void RegisterDialog::on_pushButton_register_clicked()
{
    QString userValue = ui->lineEdit_registerCode->text();
    if(mTrialController->registeOfficial(userValue)){
        mBeRegiste = true;
        QMessageBox::information(NULL, QObject::tr("注册"), QObject::tr("注册成功！"));
    }else{
        mBeRegiste = false;
        QMessageBox::information(NULL, QObject::tr("注册"), QObject::tr("注册失败，请与客服进行确认！"));
    }
    hide();
}

void RegisterDialog::on_pushButton_cancel_clicked()
{
    hide();
}
