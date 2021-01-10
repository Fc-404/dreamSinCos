/********************************************************************************
** Form generated from reading UI file 'exshow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXSHOW_H
#define UI_EXSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExShow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *exText;
    QLabel *exShow;
    QFrame *line;

    void setupUi(QWidget *ExShow)
    {
        if (ExShow->objectName().isEmpty())
            ExShow->setObjectName(QString::fromUtf8("ExShow"));
        ExShow->resize(400, 300);
        gridLayout = new QGridLayout(ExShow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        exText = new QLabel(ExShow);
        exText->setObjectName(QString::fromUtf8("exText"));

        verticalLayout->addWidget(exText);

        exShow = new QLabel(ExShow);
        exShow->setObjectName(QString::fromUtf8("exShow"));
        exShow->setStyleSheet(QString::fromUtf8("border: 1px solid #666;"));

        verticalLayout->addWidget(exShow);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        line = new QFrame(ExShow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 1);


        retranslateUi(ExShow);

        QMetaObject::connectSlotsByName(ExShow);
    } // setupUi

    void retranslateUi(QWidget *ExShow)
    {
        ExShow->setWindowTitle(QApplication::translate("ExShow", "Form", nullptr));
        exText->setText(QApplication::translate("ExShow", "\345\207\275\346\225\260\350\241\250\350\276\276\345\274\217", nullptr));
        exShow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExShow: public Ui_ExShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXSHOW_H
