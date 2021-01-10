#include "data.h"
#include "QtMath"

#include <QDebug>


/**
* 描述：   构造函数
*          在这里初始化了更新间隔为 1000 毫秒，原点 x 为 0 ，偏移为 0.1；
*          并且绑定了调用者的更新点容器槽函数；
*          实现 void gainPot(QVector<double>) 槽函数，请妥善处理参数 QVector<double> ，此参数是所有表达式值的容器，索引 length - 1 的值为容器内值的和；
* 
* 参数：   0、QObiect *parent  //请传调用者指针，用于绑定更新槽函数，所以首先确保调用者是 QObject 派生类，然后请实现 void gainPot(QVector<double>) 槽函数；
*/
Data::Data(QObject *parent):
    upTime(1000),
    Ox(0),
    offset(0.1)
{
    connect(this, SIGNAL(sendPot(QVector<double>)), parent, SLOT(gainPot(QVector<double>)));
}

Data::~Data()
{

}


/**
* 描述：   添加一个表达式到表达式容器
* 
* 参数：   int funName  //表达式类型，建议使用类内枚举 fun{SIN, COS, TAN}
*          double A     //振幅 A
*          double w     //周期 w
*          double C     //相位 C  （水平偏移）
*          double h     //偏移 h  （垂直偏移）
* 
* 返回值： bool         //添加成功返回 true
*/
bool Data::addEx(fun funName, double A, double w, double C, double h)
{
    expression temp;
    temp.funName = funName;
    temp.A = A;
    temp.w = w;
    temp.C = C;
    temp.h = h;
    funs.append(temp);
    funsPot.append(0);
    return true;
}


/**
* 描述：   以下函数可更改表达式容器中的某个表达式的值
* 
* 参数：   int index               //表达式容器索引
*          {int, double} context   //根据表达式参数上下文决定
* 
* 返回值： Data&                   //返回当前对象，此功能可以复合编辑操作
*/
Data& Data::editExType(int index, fun funName)
{
    if (!checkIndex(index))
        return *this;

    funs[index].funName = funName;

    return *this;
}

Data& Data::editExA(int index, double A)
{
    if (!checkIndex(index))
        return *this;

    funs[index].A = A;

    return *this;
}

Data& Data::editExW(int index, double w)
{
    if (!checkIndex(index))
        return *this;

    funs[index].w = w;

    return *this;
}

Data& Data::editExC(int index, double C)
{
    if (!checkIndex(index))
        return *this;

    funs[index].C = C;

    return *this;
}

Data& Data::editExH(int index, double h)
{
    if (!checkIndex(index))
        return *this;

    funs[index].h = h;

    return *this;
}


/**
* 描述：   在表达式容器删除一个表达式
*
* 参数：   int index   //表达式容器中表达式的索引
*
* 返回值： bool        //如果索引值在容器范围内，则返回 true ，否则返回 false
*/
bool Data::delEx(int index)
{
    if (!checkIndex(index))
        return false;
    //remove appoint the expression at expression vector
    funs.remove(index);
    //remove result point the appoint at vector the result point
    funsPot.remove(index);
    return true;
}


/**
* 描述：   设置原点 x 值
*
* 参数：   double Ox   //需要设置的值，初始化值为 0 
*
* 返回值： bool        //设置成功返回 true
*/
bool Data::setOx(double Ox)
{
    this->Ox = Ox;
    return true;
}


/**
* 描述：   设置更新时间
* 
* 参数：   int MS  //毫秒
* 
* 返回值： bool    //设置成功返回 true
*/
bool Data::setUpTime(int MS)
{
    this->upTime = MS;
    return true;
}


/**
* 描述：   设置 x 递增偏移
*
* 参数：   double offset   //偏移量，默认值为0.1
*
* 返回值： bool            //设置成功返回 true
*/
bool Data::setOffset(long double offset)
{
    this->offset = offset;
    return true;
}


/**
* 描述：   获取某个表达式结果点
*
* 参数：   int index   //结果点索引
*
* 返回值： bool        //如果索引不在结果点容器范围内，则返回 false ，否则返回 true
*/
double Data::getPot(int index)
{
    if (index < 0 || index >= funs.length())
        return false;
    return funsPot.at(index);
}


/**
* 描述：   获取所有表达式结果点
*
* 参数：   无
*
* 返回值： QVector<double>  //返回所有表达式点的容器
*/
QVector<double> Data::getPotAll()
{
    return funsPot;
}


/**
* 描述：   开始进行更新
*          如果你希望你传进来的所有表达式能依据偏移量和更新时间去计算表达式结果，那么请你创建对象后开启这个任务
*
* 参数：   无
*
* 返回值： bool  //如果开启成功则返回 true
* 返回值： bool  //如果开启成功则返回 true
*/
bool Data::start()
{
    //创建定时器
    upDateT = new QTimer();
    connect(upDateT, SIGNAL(timeout()), this, SLOT(upData()));
    upData();
    upDateT->start(upTime);
    return true;
}


/**
* 描述：   停止计时器，执行此操作会停止表达式的更新
*
* 参数：   无
*
* 返回值： bool  //执行成功会返回 true
*/
bool Data::stop()
{
    upDateT->stop();
    return true;
}


/**
* 描述：   定时器任务函数
*          它先清空表达式结果点容器，然后依据表达式容器重新计算结果点
*
* 参数：   无
*
* 返回值： 无
*/
void Data::upData(){
    int funLength = funs.length();
    for (int i = 0; i < funLength; ++i)
    {
        int funType = funs.at(i).funName;
        switch (funType)
        {
        case SIN:
            funsPot[i] = sinEx(funs.at(i).A,
                               funs.at(i).w,
                               funs.at(i).C,
                               funs.at(i).h);
            break;
        case COS:
            funsPot[i] = cosEx(funs.at(i).A,
                               funs.at(i).w,
                               funs.at(i).C,
                               funs.at(i).h);
            break;
        case TAN:
            funsPot[i] = sinEx(funs.at(i).A,
                               funs.at(i).w,
                               funs.at(i).C,
                               funs.at(i).h);
            break;
        }
    }
    emit sendPot(funsPot);
    Ox += offset;
    //qDebug() << funsPot;
}

/**
* 描述：   次函数可以检查传入的索引是否在表达式容器范围内
* 
* 参数：   int index   //索引值
* 
* 返回值： bool        //如果在范围内则返回 true ，否则返回 false
*/
bool Data::checkIndex(int index)
{
    if (index < 0 || index >= funs.length())
        return false;
    return true;
}


/**
* 描述：   Sin 方程计算
*
* 参数：   double A    //传入振幅变量 A
*          double w    //传入周期变量 w
*          double C    //传入相位变量 C
*          double h    //传入偏移变量 h
*
* 返回值： double      //依据表达式返回计算后的值
*/
double Data::sinEx(double A, double w, double C, double h)
{
    return A * sin(w * Ox + C) + h;
}

/**
* 描述：   Cos 方程计算
*
* 参数：   double A    //传入振幅变量 A
*          double w    //传入周期变量 w
*          double C    //传入相位变量 C
*          double h    //传入偏移变量 h
*
* 返回值： double      //依据表达式返回计算后的值
*/
double Data::cosEx(double A, double w, double C, double h)
{
    return A * cos(w * Ox + C) + h;
}

/**
* 描述：   Tan 方程计算
*
* 参数：   double A    //传入振幅变量 A
*          double w    //传入周期变量 w
*          double C    //传入相位变量 C
*          double h    //传入偏移变量 h
*
* 返回值： double      //依据表达式返回计算后的值
*/
double Data::tanEx(double A, double w, double C, double h)
{
    return A * tan(w * Ox + C) + h;
}
