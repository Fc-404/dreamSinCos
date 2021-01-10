#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <windows.h>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //获取表达式编辑展示 List
    showList = ui->ExsShow;
    editList = ui->ExsEdit;

    //initialize data
    data = new Data(this);
    data->setUpTime(16);
    data->setOffset(0.0314);
    data->start();

    //初始化表达式展示和编辑
    this->initExShowEdit();
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
* 描述：   用于初始化编辑展示组，并添加一个结果展示
*
* 参数：   无
*
* 返回值： 无
*/
bool MainWindow::initExShowEdit()
{
    createExViewGroup();

    //创建一个展示结果的 ExShow
    resultShow = new ExShow(this);
    //resultShow->repaint();
    resultShow->setFixedHeight(200);
    ui->resultShow->addWidget(resultShow);

    return true;
}


/**
* 描述：   创建一个表达式编辑展示组，并添加一个表达式到 Data 实例
*
* 参数：   无
*
* 返回值： bool  创建成功会返回 true
*/
bool MainWindow::createExViewGroup()
{
    //create show and edit object
    ExShow* exShowT = new ExShow(this);
    ExEdit* exEditT = new ExEdit(this);
    //create item object
    QListWidgetItem* exShowItemT = new QListWidgetItem(showList);
    QListWidgetItem* exEditItemT = new QListWidgetItem(editList);
    //set item size
    exShowItemT->setSizeHint(QSize(100, 200));
    exEditItemT->setSizeHint(QSize(100, 100));
    //bind show or edit object to item
    showList->setItemWidget(exShowItemT, exShowT);
    editList->setItemWidget(exEditItemT, exEditT);
    //add item to list
    showList->addItem(exShowItemT);
    editList->addItem(exEditItemT);
    //add show or edit to vector
    exShows.append(exShowT);
    exEdits.append(exEditT);
    exShowsItem.append(exShowItemT);
    exEditsItem.append(exEditItemT);

    //add a expression to data examples
    data->addEx(Data::SIN);

    return true;
}


/**
* 描述：   删除一个编辑展示组，并删除一个表达式实例中的索引
*
* 参数：   int index   //表达式索引
*
* 返回值： bool        //删除成功返回 true
*/
bool MainWindow::deleteExViewGroup(int index)
{
    //take item in list
    showList->takeItem(index);
    editList->takeItem(index);

    //get pointer at vector
    ExShow* exShowT = exShows.at(index);
    ExEdit* exEditT = exEdits.at(index);
    QListWidgetItem* exShowItemT = exShowsItem.at(index);
    QListWidgetItem* exEditItemT = exEditsItem.at(index);

    //teke pointer at vector
    exShows.remove(index);
    exEdits.remove(index);
    exShowsItem.remove(index);
    exEditsItem.remove(index);

    //delete the expression in data examples
    data->delEx(index);

    //free pointer
    delete exShowT;
    delete exEditT;
    delete exShowItemT;
    delete exEditItemT;

    return true;
}


/**
* 描述：   实现 Data 的数据更新槽函数
*
* 参数：   QVector<double>     //接受一组表达式的结果点
*
* 返回值： void
*/
void MainWindow::gainPot(QVector<double> pot)
{
    if (pot.isEmpty())
    {
        return;
    }

    int potL = pot.length();
    int exShowL = exShows.length();
    if (potL != exShowL) 
    {
        QMessageBox::warning(NULL, "Error"
                , "\n\n程序有一个错误请重启程序\n\nThere is an error in the program\t\t\nPlease reboot this program\n\n"
                , QMessageBox::Ok);
        this->close();
    }

    double sum = 0;
    for (int i = 0; i < exShowL; ++i)
    {
        sum += pot.at(i);
        exShows.at(i)->gainPot(pot.at(i));
    }

    resultShow->gainPot(sum);
}


/**
* 描述：   实现 ExEdit 中的删除事件槽函数
*
* 参数：   QWidget* m  //传回当前删除的组件
*
* 返回值： void
*/
void MainWindow::removeEx(QWidget* m)
{
    //获取当前组件在编辑组件容器里的索引
    int index = exEdits.indexOf((ExEdit*)m);
    deleteExViewGroup(index);
}


/**
* 描述：   实现 ExEdit 对象改变的响应
* 
* 参数：   int type        //改变的类型
*          double value    //改变的值
* 
* 返回值： 无
*/
void MainWindow::exEditChange(QWidget* m, int type, double value)
{
    //qDebug() << type << value;

    int index = exEdits.indexOf((ExEdit*)m);

    switch (type)
    {
    case 0:
        qDebug() << "activate" << value;
        break;
    case 1:
        data->editExType(index, (Data::fun)value);
        break;
    case 2:
        data->editExA(index, value);
        break;
    case 3:
        data->editExW(index, value);
        break;
    case 4:
        data->editExC(index, value);
        break;
    case 5:
        data->editExH(index, value);
    default:
        break;
    }
}


/**
* 描述：   添加一个表达式添加展示组的事件
*
* 参数：   null
*
* 返回值： void
*/
void MainWindow::on_addEx_clicked()
{
    createExViewGroup();
}
