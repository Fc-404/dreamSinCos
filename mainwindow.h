#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "data.h"
#include "exshow.h"
#include "exedit.h"
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // ExShow ����
    QVector<ExShow*> exShows;
    // ExEdit ����
    QVector<ExEdit*> exEdits;
    // ���������������� List
    QVector<QListWidgetItem*> exShowsItem;
    QVector<QListWidgetItem*> exEditsItem;
    QListWidget* showList;
    QListWidget* editList;
    //Data ʵ��
    Data* data;

private:
    //��ʼ�����ʽ�༭չʾ��
    bool initExShowEdit();
    //����һ�����ʽ�༭չʾ��
    bool createExViewGroup();
    //ɾ��һ�����ʽ�༭չʾ��
    bool deleteExViewGroup(int index);
    //���չʾ���
    ExShow* resultShow;

public slots:
    //ʵ�� Data ��Ҫ�󶨵Ľ������ݵ�ۺ���
    void gainPot(QVector<double> pot);
    //ʵ�� ExEdit ����� delete �¼�
    void removeEx(QWidget* m);
    //ʵ�� ExEdit �ı仯
    void exEditChange(QWidget* m, int type, double value);
private slots:
    void on_addEx_clicked();
};
#endif // MAINWINDOW_H
