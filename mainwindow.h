#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "data.h"
#include "exshow.h"
#include "exedit.h"
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // ExShow 容器
    QVector<ExShow*> exShows;
    // ExEdit 容器
    QVector<ExEdit*> exEdits;
    // 放置上述组件载体和 List
    QVector<QListWidgetItem*> exShowsItem;
    QVector<QListWidgetItem*> exEditsItem;
    QListWidget* showList;
    QListWidget* editList;
    //Data 实例
    Data* data;

private:
    //初始化表达式编辑展示组
    bool initExShowEdit();
    //创建一个表达式编辑展示组
    bool createExViewGroup();
    //删除一个表达式编辑展示组
    bool deleteExViewGroup(int index);
    //结果展示组件
    ExShow* resultShow;

public slots:
    //实现 Data 需要绑定的接受数据点槽函数
    void gainPot(QVector<double> pot);
    //实现 ExEdit 组件中 delete 事件
    void removeEx(QWidget* m);
    //实现 ExEdit 的变化
    void exEditChange(QWidget* m, int type, double value);
private slots:
    void on_addEx_clicked();
};
#endif // MAINWINDOW_H
