#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "trialcontroller.h"

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();
    bool bRegisteOk(){
        return mBeRegiste;
    }

    void setUserKey(QString userKey);

private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_cancel_clicked();

private:
    bool mBeRegiste;
    Ui::RegisterDialog *ui;
    TrialController *mTrialController;
};

#endif // REGISTERDIALOG_H
