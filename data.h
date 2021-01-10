/**
* �������ڹ�����ʽ
* ��ʵ�ֱ��ʽֵ���Զ�����
* ������Ҫ���봴����ָ�룬���ڰ󶨲�
* �����ڵ�������ʵ�� gainPot() �ۺ���
* ÿ�θ�����Ϣ��ᷢ���źŵ� gainPot() ��
*/

#ifndef DATA_H
#define DATA_H

#include <QVector>
#include <QPoint>
#include <QTimer>
#include <QObject>

#define PI 3.1415926535898

//�������Ǻ������ʽ�ṹ��
struct expression{
    //���ʽΪ��
    // y = A type(wx + C) + h
    int funName;    //���Ǻ�������
    double A;       //��� A
    double w;       //���� w
    double C;       //��λ C  ��ˮƽƫ�ƣ�
    double h;       //ƫ�� h  ����ֱƫ�ƣ�
};

class Data : public QObject
{
    Q_OBJECT
public:
    enum fun {SIN, COS, TAN};   //ö�ٳ������Ǻ�������

public:
    Data(QObject *parent);
    ~Data();

    //���һ�����ʽ�����ʽ����
    bool addEx(fun funName, double A = 1, double w = 1, double C = 0, double h = 0);
    //�༭ָ�����ʽ�Ĳ���
    Data& editExType(int index, fun funName);
    Data& editExA(int index, double A);
    Data& editExW(int index, double w);
    Data& editExC(int index, double C);
    Data& editExH(int index, double h);

    //�ڱ��ʽ����ɾ��һ�����ʽ
    bool delEx(int index);
    //����ԭ�� x ֵ
    bool setOx(double Ox);
    //���ø���ʱ��
    bool setUpTime(int MS);
    //���� x ƫ��
    bool setOffset(long double offset);
    //��ȡĳ���� y��
    double getPot(int index);
    //��ȡ���е�
    QVector<double> getPotAll();
    //��ʼ����
    bool start();
    //ֹͣ����
    bool stop();

private:
    //���ʽ����
    QVector<expression> funs;
    //���������
    QVector<double> funsPot;
    //���յ�����
    QPoint finalPot;
    //���¶�ʱ��
    QTimer *upDateT;
    //���¼��
    int upTime;
    //ԭ�� x
    double Ox;
    // x ƫ��
    long double offset;

private:
    //��������Ƿ񳬳����ʽ������Χ
    inline bool checkIndex(int index);
    //���� sin ���ʽ
    double sinEx(double A = 1, double w = 1, double C = 0, double h = 0);
    //���� cos ���ʽ
    double cosEx(double A = 1, double w = 1, double C = 0, double h = 0);
    //���� tan ���ʽ
    double tanEx(double A = 1, double w = 1, double C = 0, double h = 0);

signals:
    //���͵�����
    void sendPot(QVector<double> result);

private slots:
    //��ʱ����
    void upData();
};

#endif // DATA_H
