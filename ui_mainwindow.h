/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QListWidget *ExsShow;
    QVBoxLayout *resultShow;
    QVBoxLayout *verticalLayout;
    QListWidget *ExsEdit;
    QPushButton *addEx;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 412);
        MainWindow->setMinimumSize(QSize(800, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ExsShow = new QListWidget(centralwidget);
        ExsShow->setObjectName(QString::fromUtf8("ExsShow"));

        verticalLayout_2->addWidget(ExsShow);

        resultShow = new QVBoxLayout();
        resultShow->setObjectName(QString::fromUtf8("resultShow"));

        verticalLayout_2->addLayout(resultShow);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ExsEdit = new QListWidget(centralwidget);
        ExsEdit->setObjectName(QString::fromUtf8("ExsEdit"));
        ExsEdit->setEnabled(true);
        ExsEdit->setMinimumSize(QSize(320, 0));

        verticalLayout->addWidget(ExsEdit);

        addEx = new QPushButton(centralwidget);
        addEx->setObjectName(QString::fromUtf8("addEx"));

        verticalLayout->addWidget(addEx);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        addEx->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
