#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <readdatafromdb.h>
#include <readdatafromxlsx.h>
#include <QTreeWidgetItem>

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

private:
    void updateSignalInfo();

    Ui::MainWidget *ui;

    ReadDataFromDB *mDBReader;
    ReadDataFromXlsx *mXlsxReader;

    QList<QString> mResultUuid;
    QString mCurrentItemUuid;
};

#endif // MAINWIDGET_H
