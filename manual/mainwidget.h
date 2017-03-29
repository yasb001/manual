#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <readdatafromdb.h>
#include <readdatafromxlsx.h>
#include <QTreeWidgetItem>
#include "addsignaldialog.h"
#include "dbhelper.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:
    void on_pushButton_SignalEdit_clicked();

    void on_pushButton_SignalSearch_clicked();

    void on_treeWidget_SearchResult_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_pushButton_AddSignal_clicked();

private:
    void initDb();
    void initUi();
    DBHelper *mDBHelper;
    QList<QString> mDevicesList;
    QList<QString> mSignalList;
    QMap<QString, SignalItemBean*> mSearchResult;

    void updateSignalInfo();

    void UpdateDeviceNameComboBox();
    void UpdateSignalNameSearchEdit();

    Ui::MainWidget *ui;
    AddSignalDialog *mAddDialog;

    QList<QString> mResultUuid;
    QString mCurrentItemUuid;
};

#endif // MAINWIDGET_H
