#ifndef ADDSIGNALDIALOG_H
#define ADDSIGNALDIALOG_H

#include <QDialog>
#include "dbhelper.h"

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

    void on_pushButton_importTemplate_clicked();

private:
    Ui::AddSignalDialog *ui;
    DBHelper* mDBHelper;

};

#endif // ADDSIGNALDIALOG_H
