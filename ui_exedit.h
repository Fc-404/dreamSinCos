/********************************************************************************
** Form generated from reading UI file 'exedit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXEDIT_H
#define UI_EXEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExEdit
{
public:
    QGridLayout *gridLayout_2;
    QFrame *line;
    QGridLayout *gridLayout;
    QPushButton *delete_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *exW;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *exD;
    QComboBox *exSelect;
    QRadioButton *isShow;
    QLineEdit *exC;
    QLineEdit *exA;
    QLabel *exText;
    QLabel *label_5;

    void setupUi(QWidget *ExEdit)
    {
        if (ExEdit->objectName().isEmpty())
            ExEdit->setObjectName(QString::fromUtf8("ExEdit"));
        ExEdit->resize(320, 104);
        ExEdit->setMaximumSize(QSize(999999, 104));
        ExEdit->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(ExEdit);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        line = new QFrame(ExEdit);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 3, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        delete_2 = new QPushButton(ExEdit);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setMaximumSize(QSize(999999, 16777215));

        gridLayout->addWidget(delete_2, 0, 5, 1, 1);

        label = new QLabel(ExEdit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("border: none;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(ExEdit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("border: none;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        exW = new QLineEdit(ExEdit);
        exW->setObjectName(QString::fromUtf8("exW"));

        gridLayout->addWidget(exW, 1, 4, 1, 2);

        label_4 = new QLabel(ExEdit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("border: none;"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 2, 3, 1, 1);

        label_3 = new QLabel(ExEdit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("border: none;"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        exD = new QLineEdit(ExEdit);
        exD->setObjectName(QString::fromUtf8("exD"));

        gridLayout->addWidget(exD, 2, 4, 1, 2);

        exSelect = new QComboBox(ExEdit);
        exSelect->addItem(QString());
        exSelect->addItem(QString());
        exSelect->addItem(QString());
        exSelect->setObjectName(QString::fromUtf8("exSelect"));
        exSelect->setEnabled(true);
        exSelect->setMaximumSize(QSize(999999, 16777215));

        gridLayout->addWidget(exSelect, 0, 4, 1, 1);

        isShow = new QRadioButton(ExEdit);
        isShow->setObjectName(QString::fromUtf8("isShow"));
        isShow->setTabletTracking(true);
        isShow->setAcceptDrops(false);
        isShow->setAutoFillBackground(false);
        isShow->setChecked(true);

        gridLayout->addWidget(isShow, 0, 0, 1, 1);

        exC = new QLineEdit(ExEdit);
        exC->setObjectName(QString::fromUtf8("exC"));

        gridLayout->addWidget(exC, 2, 1, 1, 2);

        exA = new QLineEdit(ExEdit);
        exA->setObjectName(QString::fromUtf8("exA"));

        gridLayout->addWidget(exA, 1, 1, 1, 2);

        exText = new QLabel(ExEdit);
        exText->setObjectName(QString::fromUtf8("exText"));
        exText->setMinimumSize(QSize(106, 0));
        exText->setStyleSheet(QString::fromUtf8("border: none;"));

        gridLayout->addWidget(exText, 0, 1, 1, 2);

        label_5 = new QLabel(ExEdit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(13, 0));

        gridLayout->addWidget(label_5, 0, 3, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(4, 1);
        gridLayout->setColumnStretch(5, 1);

        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(ExEdit);

        QMetaObject::connectSlotsByName(ExEdit);
    } // setupUi

    void retranslateUi(QWidget *ExEdit)
    {
        ExEdit->setWindowTitle(QApplication::translate("ExEdit", "Form", nullptr));
        delete_2->setText(QApplication::translate("ExEdit", "delete", nullptr));
        label->setText(QApplication::translate("ExEdit", "A", nullptr));
        label_2->setText(QApplication::translate("ExEdit", "w", nullptr));
        exW->setText(QApplication::translate("ExEdit", "1", nullptr));
        label_4->setText(QApplication::translate("ExEdit", "D", nullptr));
        label_3->setText(QApplication::translate("ExEdit", "C", nullptr));
        exD->setText(QApplication::translate("ExEdit", "0", nullptr));
        exSelect->setItemText(0, QApplication::translate("ExEdit", "SIN", nullptr));
        exSelect->setItemText(1, QApplication::translate("ExEdit", "COS", nullptr));
        exSelect->setItemText(2, QApplication::translate("ExEdit", "TAN", nullptr));

        isShow->setText(QString());
        exC->setText(QApplication::translate("ExEdit", "0", nullptr));
        exA->setInputMask(QString());
        exA->setText(QApplication::translate("ExEdit", "1", nullptr));
        exText->setText(QApplication::translate("ExEdit", "expression", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExEdit: public Ui_ExEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXEDIT_H
