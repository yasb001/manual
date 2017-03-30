#include "addsignaldialog.h"
#include "ui_addsignaldialog.h"
#include "signalitembean.h"
#include <QUuid>
#include <QFileDialog>
#include "readdatafromxlsx.h"

AddSignalDialog::AddSignalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSignalDialog)
{
    ui->setupUi(this);
    QIcon *icon = new QIcon(":/pic/MainIcon.ico");
    setWindowIcon(*icon);
    setWindowTitle("增加信号");
    mDBHelper = DBHelper::getInstance();
}

AddSignalDialog::~AddSignalDialog()
{
    delete ui;
}

void AddSignalDialog::on_pushButton_Save_clicked()
{
    SignalItemBean *item = new SignalItemBean();
    QString uuid = QUuid::createUuid().toString();

    QString signalDevice = ui->lineEdit_SignalDevice->text();
    QString signalName = ui->lineEdit_SignalName->text();
    QString signalFrom = ui->lineEdit_SignalFrom->text();
    QString signalType = ui->lineEdit_SignalType->text();

    QString signalMeaning = ui->textEdit_SignalMeaning->document()->toPlainText();
    QString signalConnected = ui->textEdit_SignalConnected->document()->toPlainText();
    QString signalReason = ui->textEdit_SignalReason->document()->toPlainText();
    QString signalHandler = ui->textEdit_SignalHandler->document()->toPlainText();

    item->setOrd(uuid);

    item->setDeviceName(signalDevice);
    item->setSignalName(signalName);
    item->setSignalFrom(signalFrom);
    item->setSignalType(signalType);

    item->setSignalMeanning(signalMeaning);
    item->setSignalConnected(signalConnected);
    item->setSignalReason(signalReason);
    item->setSignalHandler(signalHandler);

    mDBHelper->insertSignalInfoToDb(*item);
    hide();
}

void AddSignalDialog::on_pushButton_Cancel_clicked()
{
    hide();
}

void AddSignalDialog::on_pushButton_importTemplate_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "导入文件", "D:/", "Excel文件(*.xlsx)" );
    if(fileName.isEmpty()){
        return;
    }
    hide();

    // 导入数据库
    QMap<QString, SignalItemBean*> signalItemMap;
    ReadDataFromXlsx::readData(fileName, signalItemMap);
    mDBHelper->insertSignalInfoListToDb(signalItemMap);
}
