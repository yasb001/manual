#ifndef ADDSIGNALDIALOG_H
#define ADDSIGNALDIALOG_H

#include <QDialog>
#include "readdatafromdb.h"

namespace Ui {
class AddSignalDialog;
}

class AddSignalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSignalDialog(QWidget *parent = 0);
    ~AddSignalDialog();

private slots:
    void on_pushButton_Save_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::AddSignalDialog *ui;
    ReadDataFromDB* mDB;

};

#endif // ADDSIGNALDIALOG_H
