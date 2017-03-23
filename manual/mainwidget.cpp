#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "readdatafromxlsx.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ReadDataFromXlsx *reader = new ReadDataFromXlsx();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_pushButton_SignalEdit_clicked()
{
    if(ui->pushButton_SignalEdit->isChecked()){
        ui->pushButton_SignalEdit->setText("保存修改");

        ui->lineEdit_SignalFrom->setEnabled(true);
        ui->lineEdit_SignalType->setEnabled(true);
        ui->textEdit_SignalMeaning->setEnabled(true);
        ui->textEdit_SignalConnected->setEnabled(true);
        ui->textEdit_SignalReason->setEnabled(true);
        ui->textEdit_SignalHandler->setEnabled(true);
    }
    else {
        ui->pushButton_SignalEdit->setText("信号编辑");

        ui->lineEdit_SignalFrom->setEnabled(false);
        ui->lineEdit_SignalType->setEnabled(false);
        ui->textEdit_SignalMeaning->setEnabled(false);
        ui->textEdit_SignalConnected->setEnabled(false);
        ui->textEdit_SignalReason->setEnabled(false);
        ui->textEdit_SignalHandler->setEnabled(false);
    }

}
