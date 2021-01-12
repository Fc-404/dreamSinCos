#ifndef EXSHOW_H
#define EXSHOW_H

#include <QWidget>
#include <QPainter>
#include <QQueue>

namespace Ui {
class ExShow;
}


/**
* ������   ���ڼ�¼���������������ʵ�ʻ�ͼ�����λ�ã��Լ���������������
* 
* ������   QPoint LeftTop;         //����λ��
*          QPoint LeftBottom;      //����λ��
*          QPoint RightTop;        //����λ��
*          QPoint RightBottom;     //����λ��
*          QPoint LeftCentre;      //����λ��
*          QPoint RightCentre;     //����λ��
*          QPoint TopCentre;       //����λ��
*          QPoint BottomCentre;    //����λ��
* 
*          int width;              //���
*          int height;             //�߶�
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
    //���ܵ����ݲ����л���
    void gainPot(double);

protected:
    void paintEvent(QPaintEvent* m);

private:
    Ui::ExShow *ui;
    int precision;//����
    QQueue<double> cachePots;//�����
    Board board;//���������Ϣ

private:
    //���»����������
    void updateBoard();
};

#endif // EXSHOW_H
