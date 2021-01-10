/**
* 此类用于管理表达式
* 可实现表达式值的自动更新
* 不过需要传入创建类指针，用于绑定槽
* 并且在调用类中实现 gainPot() 槽函数
* 每次更新信息便会发出信号到 gainPot() 槽
*/

#ifndef DATA_H
#define DATA_H

#include <QVector>
#include <QPoint>
#include <QTimer>
#include <QObject>

#define PI 3.1415926535898

//声明三角函数表达式结构体
struct expression{
    //表达式为：
    // y = A type(wx + C) + h
    int funName;    //三角函数类型
    double A;       //振幅 A
    double w;       //周期 w
    double C;       //相位 C  （水平偏移）
    double h;       //偏移 h  （垂直偏移）
};

class Data : public QObject
{
    Q_OBJECT
public:
    enum fun {SIN, COS, TAN};   //枚举常用三角函数类型

public:
    Data(QObject *parent);
    ~Data();

    //添加一个表达式到表达式容器
    bool addEx(fun funName, double A = 1, double w = 1, double C = 0, double h = 0);
    //编辑指定表达式的参数
    Data& editExType(int index, fun funName);
    Data& editExA(int index, double A);
    Data& editExW(int index, double w);
    Data& editExC(int index, double C);
    Data& editExH(int index, double h);

    //在表达式容器删除一个表达式
    bool delEx(int index);
    //设置原点 x 值
    bool setOx(double Ox);
    //设置更新时间
    bool setUpTime(int MS);
    //设置 x 偏移
    bool setOffset(long double offset);
    //获取某个点 y点
    double getPot(int index);
    //获取所有点
    QVector<double> getPotAll();
    //开始更新
    bool start();
    //停止更新
    bool stop();

private:
    //表达式容器
    QVector<expression> funs;
    //结果点容器
    QVector<double> funsPot;
    //最终点容器
    QPoint finalPot;
    //更新定时器
    QTimer *upDateT;
    //更新间隔
    int upTime;
    //原点 x
    double Ox;
    // x 偏移
    long double offset;

private:
    //检测索引是否超出表达式容器范围
    inline bool checkIndex(int index);
    //计算 sin 表达式
    double sinEx(double A = 1, double w = 1, double C = 0, double h = 0);
    //计算 cos 表达式
    double cosEx(double A = 1, double w = 1, double C = 0, double h = 0);
    //计算 tan 表达式
    double tanEx(double A = 1, double w = 1, double C = 0, double h = 0);

signals:
    //发送点容器
    void sendPot(QVector<double> result);

private slots:
    //定时器槽
    void upData();
};

#endif // DATA_H
