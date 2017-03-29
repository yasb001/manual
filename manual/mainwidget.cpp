#include <QCompleter>

#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "readdatafromxlsx.h"
#include "readdatafromdb.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    setWindowTitle("信号查询工具");
    setWindowFlags(Qt::WindowMaximized);

    ui->setupUi(this);
    ui->treeWidget_SearchResult->header()->setStretchLastSection(true);
    ui->treeWidget_SearchResult->setColumnWidth(0, 50);

    mXlsxReader = new ReadDataFromXlsx();
    mDBReader = ReadDataFromDB::getInstance();
    mAddDialog = new AddSignalDialog();

    // 获取设备列表
    UpdateDeviceNameComboBox();

    // 获取信号列表
    UpdateSignalNameSearchEdit();
}

void MainWidget::UpdateDeviceNameComboBox(){
    // 获取设备列表
    QList<QString> deviceList = mDBReader->getDeviceNameList();
    QCompleter *completerDevices = new QCompleter(deviceList);
    ui->comboBox_DeviceName->setCompleter(completerDevices);
    ui->comboBox_DeviceName->addItems(deviceList);
}

void MainWidget::UpdateSignalNameSearchEdit()
{
    QList<QString> signalList = mDBReader->getSignalNameList();
    QCompleter *completerSignal = new QCompleter(signalList);
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
    mResultUuid.clear();
    ui->treeWidget_SearchResult->clear();
//    QString deviceName = ui->lineEdit_SignalDevice_Search->text();
    QString deviceName = ui->comboBox_DeviceName->currentText();
    QString signalName = ui->lineEdit_SignalName_Search->text();
    bool bFuzzy = ui->checkBox_Blur->isChecked();
    mDBReader->searchSignalInfoFromDb(deviceName, signalName, bFuzzy);
    if(mDBReader->mSearchResultMap.size() > 0){
        QMap<QString, SignalItemBean*>::iterator itSignalItem =
                mDBReader->mSearchResultMap.begin();
        int iOrd = 1;
        while (itSignalItem != mDBReader->mSearchResultMap.end()) {
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
        return;
    }
    mCurrentItemUuid = current->data(0, Qt::UserRole).toString();
    QMap<QString, SignalItemBean*>::iterator itSignalItem = mDBReader->mSearchResultMap.find(mCurrentItemUuid);
    if(itSignalItem != mDBReader->mSearchResultMap.end()){
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
    SignalItemBean *item = new SignalItemBean();
    QString signalFrom = ui->lineEdit_SignalFrom->text();
    QString signalType = ui->lineEdit_SignalType->text();

    QString signalMeaning = ui->textEdit_SignalMeaning->document()->toPlainText();
    QString signalConnected = ui->textEdit_SignalConnected->document()->toPlainText();
    QString signalReason = ui->textEdit_SignalReason->document()->toPlainText();
    QString signalHandler = ui->textEdit_SignalHandler->document()->toPlainText();

    item->setOrd(mCurrentItemUuid);
    item->setSignalFrom(signalFrom);
    item->setSignalType(signalType);
    item->setSignalMeanning(signalMeaning);
    item->setSignalConnected(signalConnected);
    item->setSignalReason(signalReason);
    item->setSignalHandler(signalHandler);
    mDBReader->writeSignalInfoToDb(*item);
}

void MainWidget::on_pushButton_AddSignal_clicked()
{
    mAddDialog->show();
}
