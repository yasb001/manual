#include <QCompleter>
#include <QMessageBox>
#include "registerdialog.h"
#include "trialcontroller.h"
#include "mainwidget.h"
#include "ui_mainwidget.h"
//#include "readdatafromxlsx.h"
#include "xlsxreader.h"
#include "readdatafromdb.h"
#include <QIcon>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    QIcon *icon = new QIcon(":/pic/MainIcon.ico");
    setWindowIcon(*icon);

    setWindowTitle("220kV及以下变电站信号检索工具");
    setWindowState(Qt::WindowMaximized);

    mAddDialog = new AddSignalDialog();

    initDb();
    initUi();
}

void MainWidget::UpdateDeviceNameComboBox(){
    mDBHelper->getDeviceNameList(mDevicesList);
    mDevicesList.append("全部设备");
    ui->comboBox_DeviceName->clear();
    ui->comboBox_DeviceName->addItems(mDevicesList);
}

void MainWidget::UpdateSignalNameSearchEdit()
{
    mDBHelper->getSignalNameList(mSignalList);
    QCompleter *completerSignal = new QCompleter(mSignalList);
    ui->lineEdit_SignalName_Search->setCompleter(completerSignal);
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

        updateSignalInfo();
    }

}

void MainWidget::on_pushButton_SignalSearch_clicked()
{
    TrialController *trial = TrialController::getInstance();
    if(trial->isOutTime()){
        RegisterDialog dialog;
        dialog.setUserKey(trial->getUserKey());
            dialog.exec();
            if(!dialog.bRegisteOk()){
                return;
            }
    }
    mResultUuid.clear();
    mSearchResult.clear();
    ui->treeWidget_SearchResult->clear();
    QString deviceName = ui->comboBox_DeviceName->currentText();
    QString signalName = ui->lineEdit_SignalName_Search->text();
    bool bFuzzy = ui->checkBox_Blur->isChecked();
    mDBHelper->searchSignalInfoFromDb(deviceName, signalName, bFuzzy, mSearchResult);
    if(mSearchResult.size() > 0){
        QMap<QString, SignalItemBean*>::iterator itSignalItem =
                mSearchResult.begin();
        int iOrd = 1;
        while (itSignalItem != mSearchResult.end()) {
            QStringList itemContent;
            itemContent << QString::number(iOrd) << itSignalItem.value()->signalName();
            QTreeWidgetItem *item = new QTreeWidgetItem(itemContent);
            item->setData(0, Qt::UserRole, itSignalItem.value()->ord());
            ui->treeWidget_SearchResult->addTopLevelItem(item);
            mResultUuid.append(itSignalItem.value()->ord());
            if(iOrd == 1){
                ui->treeWidget_SearchResult->setCurrentItem(item);
            }
            iOrd++;
            itSignalItem++;
        }
    }
}

void MainWidget::on_treeWidget_SearchResult_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if(NULL == current){
        ui->lineEdit_SignalDevice->clear();
        ui->lineEdit_SignalName->clear();
        ui->lineEdit_SignalFrom->clear();
        ui->lineEdit_SignalType->clear();

        ui->textEdit_SignalMeaning->clear();
        ui->textEdit_SignalConnected->clear();
        ui->textEdit_SignalReason->clear();
        ui->textEdit_SignalHandler->clear();

        return;
    }
    mCurrentItemUuid = current->data(0, Qt::UserRole).toString();
    QMap<QString, SignalItemBean*>::iterator itSignalItem = mSearchResult.find(mCurrentItemUuid);
    if(itSignalItem != mSearchResult.end()){
        ui->lineEdit_SignalDevice->setText(itSignalItem.value()->deviceName());
        ui->lineEdit_SignalName->setText(itSignalItem.value()->signalName());
        ui->lineEdit_SignalFrom->setText(itSignalItem.value()->signalFrom());
        ui->lineEdit_SignalType->setText(itSignalItem.value()->signalType());

        ui->textEdit_SignalMeaning->setText(itSignalItem.value()->signalMeanning());
        ui->textEdit_SignalConnected->setText(itSignalItem.value()->signalConnected());
        ui->textEdit_SignalReason->setText(itSignalItem.value()->signalReason());
        ui->textEdit_SignalHandler->setText(itSignalItem.value()->signalHandler());
    }
}

void MainWidget::updateSignalInfo(){
    SignalItemBean *item;

    QString signalFrom = ui->lineEdit_SignalFrom->text();
    QString signalType = ui->lineEdit_SignalType->text();

    QString signalMeaning = ui->textEdit_SignalMeaning->document()->toPlainText();
    QString signalConnected = ui->textEdit_SignalConnected->document()->toPlainText();
    QString signalReason = ui->textEdit_SignalReason->document()->toPlainText();
    QString signalHandler = ui->textEdit_SignalHandler->document()->toPlainText();


    QMap<QString, SignalItemBean*>::iterator itSignal = mSearchResult.find(mCurrentItemUuid);
    if(itSignal != mSearchResult.end()){
        item = itSignal.value();
        item->setOrd(mCurrentItemUuid);
        item->setSignalFrom(signalFrom);
        item->setSignalType(signalType);
        item->setSignalMeanning(signalMeaning);
        item->setSignalConnected(signalConnected);
        item->setSignalReason(signalReason);
        item->setSignalHandler(signalHandler);
    }

    mDBHelper->updateSignalInfoToDb(*item);
}

void MainWidget::on_pushButton_AddSignal_clicked()
{
    mAddDialog->show();
}

void MainWidget::initDb()
{
    mDBHelper = DBHelper::getInstance();
    connect(mDBHelper, SIGNAL(deviceChanged()), this, SLOT(UpdateDeviceNameComboBox()));
    connect(mDBHelper, SIGNAL(signalChanged()), this, SLOT(UpdateSignalNameSearchEdit()));
}

void MainWidget::initUi()
{
    ui->treeWidget_SearchResult->header()->setStretchLastSection(true);
    ui->treeWidget_SearchResult->setColumnWidth(0, 70);

    // 获取设备列表
    UpdateDeviceNameComboBox();

    // 获取信号列表
    UpdateSignalNameSearchEdit();

    ui->checkBox_Blur->setChecked(true);
    ui->comboBox_DeviceName->setCurrentIndex(0);
    int index = ui->comboBox_DeviceName->findText("全部设备");
    if(index == -1){
        index = 0;
    }
    ui->comboBox_DeviceName->setCurrentIndex(index);
//    ui->comboBox_DeviceName->setCurrentText("全部设备");
    on_pushButton_SignalSearch_clicked();
}

void MainWidget::on_comboBox_DeviceName_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_SignalName_Search->setText("");
    on_pushButton_SignalSearch_clicked();
}
