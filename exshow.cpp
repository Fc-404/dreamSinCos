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
* ������   ���ػ���Ļ��ƺ������Ի�����Ҫ�Ľ��
* 
* ������   QPaintEvent* m      //�����¼�
* 
* ����ֵ�� ��
*/
void ExShow::paintEvent(QPaintEvent* m)
{
    //ʵʱ���»����豸�ߴ�
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
* ������   ���ڸ��»�����壬���ǻ�ȡ�������ĸ߿��Լ��߾࣬���¼�����Ի��Ƶ�����
* 
* ������   ��
* 
* ����ֵ�� ��
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
* ������   ��ȡ��Ĳۺ����������Ը��ݻ������Ŀ�Ƚ��е��ڻ�������
* 
* ������   double pot      //�µĵ�
* 
* ����ֵ�� ��
*/
void ExShow::gainPot(double pot)
{
    int mayPotL = board.width;
    int chchePotsL = cachePots.length();

    //���/ɾ�������
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