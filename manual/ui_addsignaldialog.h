/********************************************************************************
** Form generated from reading UI file 'addsignaldialog.ui'
**
** Created: Wed Apr 5 14:49:10 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSIGNALDIALOG_H
#define UI_ADDSIGNALDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddSignalDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_SignalDevice;
    QLabel *label_5;
    QLineEdit *lineEdit_SignalName;
    QLabel *label_7;
    QLineEdit *lineEdit_SignalFrom;
    QLabel *label_6;
    QLineEdit *lineEdit_SignalType;
    QLabel *label_9;
    QTextEdit *textEdit_SignalMeaning;
    QLabel *label_8;
    QTextEdit *textEdit_SignalConnected;
    QLabel *label_11;
    QTextEdit *textEdit_SignalReason;
    QLabel *label_10;
    QTextEdit *textEdit_SignalHandler;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_importTemplate;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AddSignalDialog)
    {
        if (AddSignalDialog->objectName().isEmpty())
            AddSignalDialog->setObjectName(QString::fromUtf8("AddSignalDialog"));
        AddSignalDialog->resize(799, 511);
        horizontalLayout = new QHBoxLayout(AddSignalDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(AddSignalDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_SignalDevice = new QLineEdit(AddSignalDialog);
        lineEdit_SignalDevice->setObjectName(QString::fromUtf8("lineEdit_SignalDevice"));
        lineEdit_SignalDevice->setEnabled(true);

        gridLayout->addWidget(lineEdit_SignalDevice, 0, 1, 1, 1);

        label_5 = new QLabel(AddSignalDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        lineEdit_SignalName = new QLineEdit(AddSignalDialog);
        lineEdit_SignalName->setObjectName(QString::fromUtf8("lineEdit_SignalName"));
        lineEdit_SignalName->setEnabled(true);

        gridLayout->addWidget(lineEdit_SignalName, 0, 3, 1, 1);

        label_7 = new QLabel(AddSignalDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_SignalFrom = new QLineEdit(AddSignalDialog);
        lineEdit_SignalFrom->setObjectName(QString::fromUtf8("lineEdit_SignalFrom"));
        lineEdit_SignalFrom->setEnabled(true);

        gridLayout->addWidget(lineEdit_SignalFrom, 1, 1, 1, 1);

        label_6 = new QLabel(AddSignalDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        lineEdit_SignalType = new QLineEdit(AddSignalDialog);
        lineEdit_SignalType->setObjectName(QString::fromUtf8("lineEdit_SignalType"));
        lineEdit_SignalType->setEnabled(true);

        gridLayout->addWidget(lineEdit_SignalType, 1, 3, 1, 1);

        label_9 = new QLabel(AddSignalDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        textEdit_SignalMeaning = new QTextEdit(AddSignalDialog);
        textEdit_SignalMeaning->setObjectName(QString::fromUtf8("textEdit_SignalMeaning"));
        textEdit_SignalMeaning->setEnabled(true);
        textEdit_SignalMeaning->setReadOnly(false);

        gridLayout->addWidget(textEdit_SignalMeaning, 2, 1, 1, 1);

        label_8 = new QLabel(AddSignalDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 2, 1, 1);

        textEdit_SignalConnected = new QTextEdit(AddSignalDialog);
        textEdit_SignalConnected->setObjectName(QString::fromUtf8("textEdit_SignalConnected"));
        textEdit_SignalConnected->setEnabled(true);

        gridLayout->addWidget(textEdit_SignalConnected, 2, 3, 1, 1);

        label_11 = new QLabel(AddSignalDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        textEdit_SignalReason = new QTextEdit(AddSignalDialog);
        textEdit_SignalReason->setObjectName(QString::fromUtf8("textEdit_SignalReason"));
        textEdit_SignalReason->setEnabled(true);
        textEdit_SignalReason->setReadOnly(false);

        gridLayout->addWidget(textEdit_SignalReason, 3, 1, 1, 1);

        label_10 = new QLabel(AddSignalDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 3, 2, 1, 1);

        textEdit_SignalHandler = new QTextEdit(AddSignalDialog);
        textEdit_SignalHandler->setObjectName(QString::fromUtf8("textEdit_SignalHandler"));
        textEdit_SignalHandler->setEnabled(true);

        gridLayout->addWidget(textEdit_SignalHandler, 3, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_Save = new QPushButton(AddSignalDialog);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));

        verticalLayout->addWidget(pushButton_Save);

        pushButton_Cancel = new QPushButton(AddSignalDialog);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));

        verticalLayout->addWidget(pushButton_Cancel);

        pushButton_importTemplate = new QPushButton(AddSignalDialog);
        pushButton_importTemplate->setObjectName(QString::fromUtf8("pushButton_importTemplate"));

        verticalLayout->addWidget(pushButton_importTemplate);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(AddSignalDialog);

        QMetaObject::connectSlotsByName(AddSignalDialog);
    } // setupUi

    void retranslateUi(QDialog *AddSignalDialog)
    {
        AddSignalDialog->setWindowTitle(QApplication::translate("AddSignalDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddSignalDialog", "\346\211\200\345\261\236\350\256\276\345\244\207:", 0, QApplication::UnicodeUTF8));
        lineEdit_SignalDevice->setText(QString());
        label_5->setText(QApplication::translate("AddSignalDialog", "\344\277\241\345\217\267\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AddSignalDialog", "\344\277\241\345\217\267\346\235\245\346\272\220:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AddSignalDialog", "\344\277\241\345\217\267\347\261\273\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("AddSignalDialog", "\344\277\241\345\217\267\345\220\253\344\271\211:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AddSignalDialog", "\345\205\263\350\201\224\344\277\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("AddSignalDialog", "\344\272\247\347\224\237\345\216\237\345\233\240:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("AddSignalDialog", "\345\244\204\347\220\206\345\216\237\345\210\231:", 0, QApplication::UnicodeUTF8));
        pushButton_Save->setText(QApplication::translate("AddSignalDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("AddSignalDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_importTemplate->setText(QApplication::translate("AddSignalDialog", "\345\257\274\345\205\245\346\250\241\346\235\277...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddSignalDialog: public Ui_AddSignalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSIGNALDIALOG_H
