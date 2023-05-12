#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <unistd.h>
#include <stdlib.h>

extern unsigned char init8563_Store[3];
extern unsigned char g8563_Store[3];
extern  void P8563_settime();
extern void P8563_init();
extern void P8563_Readtime();


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
    void on_pushButton_clicked();

    void update_vremena();

private:
    Ui::Dialog *ui;
    QTimer * timer;



};
#endif // DIALOG_H
