/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created: Wed Apr 5 14:49:10 2017
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_DeviceName;
    QLabel *label_2;
    QLineEdit *lineEdit_SignalName_Search;
    QCheckBox *checkBox_Blur;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_SignalSearch;
    QPushButton *pushButton_SignalEdit;
    QPushButton *pushButton_AddSignal;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTreeWidget *treeWidget_SearchResult;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_12;
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

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(920, 624);
        verticalLayout_4 = new QVBoxLayout(MainWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MainWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox_DeviceName = new QComboBox(MainWidget);
        comboBox_DeviceName->setObjectName(QString::fromUtf8("comboBox_DeviceName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_DeviceName->sizePolicy().hasHeightForWidth());
        comboBox_DeviceName->setSizePolicy(sizePolicy);
        comboBox_DeviceName->setMinimumSize(QSize(200, 0));
        comboBox_DeviceName->setEditable(false);

        horizontalLayout->addWidget(comboBox_DeviceName);

        label_2 = new QLabel(MainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_SignalName_Search = new QLineEdit(MainWidget);
        lineEdit_SignalName_Search->setObjectName(QString::fromUtf8("lineEdit_SignalName_Search"));

        horizontalLayout->addWidget(lineEdit_SignalName_Search);


        horizontalLayout_2->addLayout(horizontalLayout);

        checkBox_Blur = new QCheckBox(MainWidget);
        checkBox_Blur->setObjectName(QString::fromUtf8("checkBox_Blur"));

        horizontalLayout_2->addWidget(checkBox_Blur);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_SignalSearch = new QPushButton(MainWidget);
        pushButton_SignalSearch->setObjectName(QString::fromUtf8("pushButton_SignalSearch"));
        pushButton_SignalSearch->setAutoDefault(false);

        verticalLayout->addWidget(pushButton_SignalSearch);

        pushButton_SignalEdit = new QPushButton(MainWidget);
        pushButton_SignalEdit->setObjectName(QString::fromUtf8("pushButton_SignalEdit"));
        pushButton_SignalEdit->setCheckable(true);
        pushButton_SignalEdit->setChecked(false);

        verticalLayout->addWidget(pushButton_SignalEdit);

        pushButton_AddSignal = new QPushButton(MainWidget);
        pushButton_AddSignal->setObjectName(QString::fromUtf8("pushButton_AddSignal"));
        pushButton_AddSignal->setCheckable(false);

        verticalLayout->addWidget(pushButton_AddSignal);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_3 = new QLabel(MainWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAutoFillBackground(true);

        verticalLayout_3->addWidget(label_3);

        treeWidget_SearchResult = new QTreeWidget(MainWidget);
        treeWidget_SearchResult->setObjectName(QString::fromUtf8("treeWidget_SearchResult"));
        treeWidget_SearchResult->setSortingEnabled(false);
        treeWidget_SearchResult->header()->setCascadingSectionResizes(false);
        treeWidget_SearchResult->header()->setDefaultSectionSize(100);

        verticalLayout_3->addWidget(treeWidget_SearchResult);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_12 = new QLabel(MainWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_12);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(MainWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_SignalDevice = new QLineEdit(MainWidget);
        lineEdit_SignalDevice->setObjectName(QString::fromUtf8("lineEdit_SignalDevice"));
        lineEdit_SignalDevice->setEnabled(false);

        gridLayout->addWidget(lineEdit_SignalDevice, 0, 1, 1, 1);

        label_5 = new QLabel(MainWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        lineEdit_SignalName = new QLineEdit(MainWidget);
        lineEdit_SignalName->setObjectName(QString::fromUtf8("lineEdit_SignalName"));
        lineEdit_SignalName->setEnabled(false);

        gridLayout->addWidget(lineEdit_SignalName, 0, 3, 1, 1);

        label_7 = new QLabel(MainWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_SignalFrom = new QLineEdit(MainWidget);
        lineEdit_SignalFrom->setObjectName(QString::fromUtf8("lineEdit_SignalFrom"));
        lineEdit_SignalFrom->setEnabled(false);

        gridLayout->addWidget(lineEdit_SignalFrom, 1, 1, 1, 1);

        label_6 = new QLabel(MainWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        lineEdit_SignalType = new QLineEdit(MainWidget);
        lineEdit_SignalType->setObjectName(QString::fromUtf8("lineEdit_SignalType"));
        lineEdit_SignalType->setEnabled(false);

        gridLayout->addWidget(lineEdit_SignalType, 1, 3, 1, 1);

        label_9 = new QLabel(MainWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        textEdit_SignalMeaning = new QTextEdit(MainWidget);
        textEdit_SignalMeaning->setObjectName(QString::fromUtf8("textEdit_SignalMeaning"));
        textEdit_SignalMeaning->setEnabled(false);
        textEdit_SignalMeaning->setReadOnly(false);

        gridLayout->addWidget(textEdit_SignalMeaning, 2, 1, 1, 1);

        label_8 = new QLabel(MainWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 2, 1, 1);

        textEdit_SignalConnected = new QTextEdit(MainWidget);
        textEdit_SignalConnected->setObjectName(QString::fromUtf8("textEdit_SignalConnected"));
        textEdit_SignalConnected->setEnabled(false);

        gridLayout->addWidget(textEdit_SignalConnected, 2, 3, 1, 1);

        label_11 = new QLabel(MainWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        textEdit_SignalReason = new QTextEdit(MainWidget);
        textEdit_SignalReason->setObjectName(QString::fromUtf8("textEdit_SignalReason"));
        textEdit_SignalReason->setEnabled(false);
        textEdit_SignalReason->setReadOnly(false);

        gridLayout->addWidget(textEdit_SignalReason, 3, 1, 1, 1);

        label_10 = new QLabel(MainWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 3, 2, 1, 1);

        textEdit_SignalHandler = new QTextEdit(MainWidget);
        textEdit_SignalHandler->setObjectName(QString::fromUtf8("textEdit_SignalHandler"));
        textEdit_SignalHandler->setEnabled(false);

        gridLayout->addWidget(textEdit_SignalHandler, 3, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 4);

        verticalLayout_4->addLayout(horizontalLayout_4);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWidget", "\346\211\200\345\261\236\350\256\276\345\244\207:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWidget", "\344\277\241\345\217\267\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        checkBox_Blur->setText(QApplication::translate("MainWidget", "\346\250\241\347\263\212\345\214\271\351\205\215", 0, QApplication::UnicodeUTF8));
        pushButton_SignalSearch->setText(QApplication::translate("MainWidget", "\344\277\241\345\217\267\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        pushButton_SignalEdit->setText(QApplication::translate("MainWidget", "\344\277\241\345\217\267\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        pushButton_AddSignal->setText(QApplication::translate("MainWidget", "\345\242\236\345\212\240\344\277\241\345\217\267", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_SearchResult->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWidget", "\344\277\241\345\217\267\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWidget", "\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWidget", "\344\277\241\345\217\267\350\257\246\346\203\205", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWidget", "\346\211\200\345\261\236\350\256\276\345\244\207:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWidget", "\344\277\241\345\217\267\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWidget", "\344\277\241\345\217\267\346\235\245\346\272\220:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWidget", "\344\277\241\345\217\267\347\261\273\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWidget", "\344\277\241\345\217\267\345\220\253\344\271\211:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWidget", "\345\205\263\350\201\224\344\277\241\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWidget", "\344\272\247\347\224\237\345\216\237\345\233\240:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWidget", "\345\244\204\347\220\206\345\216\237\345\210\231:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
