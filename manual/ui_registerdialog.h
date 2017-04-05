/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created: Wed Apr 5 14:49:10 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_userCode;
    QLineEdit *lineEdit_UserCode;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_registerCode;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_register;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QString::fromUtf8("RegisterDialog"));
        RegisterDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(RegisterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(RegisterDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_userCode = new QLabel(RegisterDialog);
        label_userCode->setObjectName(QString::fromUtf8("label_userCode"));

        horizontalLayout->addWidget(label_userCode);

        lineEdit_UserCode = new QLineEdit(RegisterDialog);
        lineEdit_UserCode->setObjectName(QString::fromUtf8("lineEdit_UserCode"));
        lineEdit_UserCode->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_UserCode);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_registerCode = new QLineEdit(RegisterDialog);
        lineEdit_registerCode->setObjectName(QString::fromUtf8("lineEdit_registerCode"));

        horizontalLayout_2->addWidget(lineEdit_registerCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(RegisterDialog);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);

        pushButton_register = new QPushButton(RegisterDialog);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setDefault(true);

        horizontalLayout_3->addWidget(pushButton_register);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("RegisterDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\350\257\225\347\224\250\346\234\237\345\210\260\346\234\237\346\217\220\347\244\272</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">  \345\260\212\346\225\254\347\232\204\347\224\250\346\210\267\357\274\214\346\202\250\347\232\204\350\275\257\344\273\266\350\257\225\347\224\250\346\234\237\345\267\262\347\273\217\345\210\260\346\234\237\343\200\202\344\270\272\350\203\275\345\244\237\347\273\247\347"
                        "\273\255\344\270\272\346\202\250\346\234\215\345\212\241\357\274\214\350\257\267\350\201\224\347\263\273\346\210\221\344\273\254\347\232\204\345\256\242\346\234\215\350\277\233\350\241\214\346\263\250\345\206\214\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">QQ\357\274\232595087268</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">                         \350\260\242\350\260\242</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_userCode->setText(QApplication::translate("RegisterDialog", "\347\224\250\346\210\267\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("RegisterDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_register->setText(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
