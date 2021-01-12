#include "exshow.h"
#include "ui_exshow.h"
#include <QDebug>

ExShow::ExShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExShow),
    precision(100)
{
    ui->setupUi(this);
}

ExShow::~ExShow()
{
    delete ui;
}


/**
* 描述：   重载基类的绘制函数，以绘制想要的结果
* 
* 参数：   QPaintEvent* m      //绘制事件
* 
* 返回值： 无
*/
void ExShow::paintEvent(QPaintEvent* m)
{
    //实时更新绘制设备尺寸
    if (board.width != ui->exShow->width() - 2)
    {
        //qDebug() << "updata board";
        updateBoard();
    }

    /* Standard TEST
    QPainter p(this);
    p.drawLine(board.LeftTop, board.RightBottom);
    p.drawLine(board.RightTop, board.LeftBottom);
    p.drawLine(board.TopCentre, board.BottomCentre);
    p.drawLine(board.LeftCentre, board.RightCentre);
    */

    //QPainter p(this);
    QPainterPath pPath;
    QPainter p(this);
    pPath.moveTo(board.LeftCentre);

    int chchePotsL = cachePots.length();
    double maxPot = 0;

    //find max point
    for (int i = 0; i < chchePotsL; ++i)
    {
        double absPot = 0;
        absPot = (cachePots.at(i) * 2) / 2;
        if (absPot > maxPot)
        {
            maxPot = absPot;
        }
    }

    //draw
    for (int i = 0; i < chchePotsL; ++i)
    {
        QPoint nextPot;
        nextPot.rx() = i + board.LeftCentre.x();
        nextPot.ry() = board.LeftCentre.y() - (cachePots.at(i) / maxPot) * (board.height / 2);
        //qDebug() << nextPot;
        pPath.lineTo(nextPot);
    }

    p.drawPath(pPath);
}


/**
* 描述：   用于更新绘制面板，它是获取绘制面板的高宽以及边距，重新计算可以绘制的区域
* 
* 参数：   无
* 
* 返回值： 无
*/
void ExShow::updateBoard()
{
    int leftOffset = 10;
    int topOffset = ui->exText->height() + 16;
    int width = ui->exShow->width() - 2;
    int height = ui->exShow->height() - 2;
    board.width = width;
    board.height = height;
    board.LeftTop = QPoint(leftOffset, topOffset);
    board.RightTop = QPoint(leftOffset + width, topOffset);
    board.RightBottom = QPoint(leftOffset + width, topOffset + height);
    board.LeftBottom = QPoint(leftOffset, topOffset + height);
    board.LeftCentre = QPoint(leftOffset, topOffset + height / 2);
    board.RightCentre = QPoint(leftOffset + width, topOffset + height / 2);
    board.TopCentre = QPoint(leftOffset + width / 2, topOffset);
    board.BottomCentre = QPoint(leftOffset + width / 2, topOffset + height);
}


/**
* 描述：   获取点的槽函数，它可以根据绘制面板的宽度进行调节缓存点队列
* 
* 参数：   double pot      //新的点
* 
* 返回值： 无
*/
void ExShow::gainPot(double pot)
{
    int mayPotL = board.width;
    int chchePotsL = cachePots.length();

    //添加/删除缓存点
    if (mayPotL < chchePotsL)
    {
        if (!cachePots.empty())
        {
            int offset = chchePotsL - mayPotL;
            for (int i = 0; i < offset; ++i)
            {
                cachePots.dequeue();
            }
            cachePots.enqueue(pot);
        }
    }
    else
    {
        cachePots.enqueue(pot);
    }
    
    //qDebug() << cachePots.length();

    //update draw of paintEvent
    repaint();
}