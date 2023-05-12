#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QTimer>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <QDebug>
#include <cmath>




QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void update_parametara();


private:
    Ui::Dialog *ui;
    QTimer *timer;
};
#endif // DIALOG_H
