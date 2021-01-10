#ifndef EXEDIT_H
#define EXEDIT_H

#include <QWidget>
#include "data.h"

namespace Ui {
class ExEdit;
}

class ExEdit : public QWidget
{
    Q_OBJECT

public:
    enum selectType {ACTIVATE, FUN, A, W, C, H};

public:
    explicit ExEdit(QWidget *parent = nullptr);
    ~ExEdit();

private:
    Ui::ExEdit *ui;

signals:
    //移出组件信号
    void removeEvent(QWidget* m);
    //改变信号
    void sendChange(QWidget* m, int type, double value);

private slots:
    void on_delete_2_clicked();
    void on_exSelect_currentIndexChanged(int index);
    void on_isShow_clicked(bool is);
    void on_exA_textChanged(QString m);
    void on_exW_textChanged(QString m);
    void on_exC_textChanged(QString m);
    void on_exH_textChanged(QString m);
};

#endif // EXEDIT_H
