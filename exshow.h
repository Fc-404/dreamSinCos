#ifndef EXSHOW_H
#define EXSHOW_H

#include <QWidget>
#include <QPainter>
#include <QQueue>

namespace Ui {
class ExShow;
}


/**
* 描述：   用于记录绘制面板特征点在实际绘图界面的位置，以及绘制面板基本属性
* 
* 参数：   QPoint LeftTop;         //左上位置
*          QPoint LeftBottom;      //右上位置
*          QPoint RightTop;        //右上位置
*          QPoint RightBottom;     //右下位置
*          QPoint LeftCentre;      //左中位置
*          QPoint RightCentre;     //右中位置
*          QPoint TopCentre;       //上中位置
*          QPoint BottomCentre;    //下中位置
* 
*          int width;              //宽度
*          int height;             //高度
*/
struct Board
{
    QPoint LeftTop;
    QPoint LeftBottom;
    QPoint RightTop;
    QPoint RightBottom;
    QPoint LeftCentre;
    QPoint RightCentre;
    QPoint TopCentre;
    QPoint BottomCentre;

    int width;
    int height;
};


class ExShow : public QWidget
{
    Q_OBJECT

public:
    explicit ExShow(QWidget *parent = nullptr);
    ~ExShow();
    //接受点数据并进行绘制
    void gainPot(double);

protected:
    void paintEvent(QPaintEvent* m);

private:
    Ui::ExShow *ui;
    int precision;//精度
    QQueue<double> cachePots;//缓存点
    Board board;//绘制面板信息

private:
    //更新绘制面板数据
    void updateBoard();
};

#endif // EXSHOW_H
