/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDial *dial;
    QSlider *verticalSlider;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1054, 811);
        dial = new QDial(Dialog);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(270, 150, 191, 181));
        dial->setMinimum(0);
        dial->setMaximum(33);
        dial->setPageStep(10);
        dial->setValue(0);
        dial->setSliderPosition(0);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setWrapping(false);
        dial->setNotchTarget(3.700000000000000);
        dial->setNotchesVisible(true);
        verticalSlider = new QSlider(Dialog);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(640, 160, 20, 331));
        verticalSlider->setMaximum(100);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setTickPosition(QSlider::TicksBothSides);
        verticalSlider->setTickInterval(20);
        lcdNumber = new QLCDNumber(Dialog);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(240, 400, 241, 101));
        lcdNumber->setDigitCount(4);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 100, 131, 61));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 100, 181, 51));
        label_2->setFont(font);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 500, 211, 81));
        label_3->setFont(font);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "VOLT", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "OSVETLJENJE", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "TEMPERATURA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
