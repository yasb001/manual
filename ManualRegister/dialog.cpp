#include "dialog.h"
#include "ui_dialog.h"
#include <QIcon>

Dialog::Dialog(QWidget *parent) :
QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle(QString("注册机"));
    QIcon *icon = new QIcon(":/pic/MainIcon.ico");
    setWindowIcon(*icon);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_cancel_clicked()
{
    exit(0);
}

void Dialog::on_pushButton_ok_clicked()
{
    QString key = ui->lineEdit_key->text();
    QString value;
    QByteArray temp = key.toLatin1().toHex();
    value.append(temp);
    ui->lineEdit_value->setText(value);
}
