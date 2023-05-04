#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
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
#include <string.h>
#include <lcd.h>

extern unsigned char init8563_Store[3];
extern unsigned char g8563_Store[3];
extern  void P8563_settime();
extern void P8563_init();
extern void P8563_Readtime();
extern int lcd;


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

    void on_checkBox_stateChanged(int arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void update_vremena();

    void lcd_ispis();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QTimer * timer;
    QTimer * timer2;
    QTime trenutno;
    QTime alarm;
    QString string;

};
#endif // DIALOG_H
