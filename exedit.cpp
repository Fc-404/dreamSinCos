#include "exedit.h"
#include "ui_exedit.h"
#include <QDebug>

ExEdit::ExEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExEdit)
{
    ui->setupUi(this);

    QDoubleValidator* lim = new QDoubleValidator(-999.000, 999.000, 3, this);
    lim->setNotation(QDoubleValidator::ScientificNotation);//bug
    ui->exA->setValidator(lim);
    ui->exC->setValidator(lim);
    ui->exD->setValidator(lim);
    ui->exW->setValidator(lim);

    //绑定调用者的移出组件功能
    connect(this, SIGNAL(removeEvent(QWidget*)), parent, SLOT(removeEx(QWidget*)));
    //绑定自身的改变到调用者
    connect(this, SIGNAL(sendChange(QWidget*, int, double)), parent, SLOT(exEditChange(QWidget*, int, double)));
}

ExEdit::~ExEdit()
{
    delete ui;
}

void ExEdit::on_delete_2_clicked()
{
    emit removeEvent(this);
}

void ExEdit::on_exSelect_currentIndexChanged(int index)
{
    emit sendChange(this, FUN, index);
}

void ExEdit::on_isShow_clicked(bool is)
{
    emit sendChange(this, ACTIVATE, is);
}

void ExEdit::on_exA_textChanged(QString m)
{
    emit sendChange(this, A, m.toDouble());
}

void ExEdit::on_exW_textChanged(QString m)
{
    emit sendChange(this, W, m.toDouble());
}

void ExEdit::on_exC_textChanged(QString m)
{
    emit sendChange(this, C, m.toDouble());
}

void ExEdit::on_exH_textChanged(QString m)
{
    emit sendChange(this, H, m.toDouble());
}


