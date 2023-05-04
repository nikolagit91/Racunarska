//#include <QDebug>
#include "dialog.h"
#include "ui_dialog.h"
#include <wiringPi.h>
#include <lcd.h>
#include <string.h>



string string1;
string string2;


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    //u objekate linija1 i linija2 smjesti text iz lineEdit polja
    QString linija1= ui->lineEdit->text();
    QString linija2= ui->lineEdit_2->text();

    // obrisi lineEdit polje
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();

    //prebaci objekat u standardni string
    string1=linija1.toStdString();
    string2=linija2.toStdString();

    //ispis na LCD
    lcdClear(lcd);
    lcdPosition(lcd, 0,0);
    lcdPrintf(lcd,"%s", string1.c_str());
    lcdPosition(lcd, 0,1);
    lcdPrintf(lcd,"%s", string2.c_str());
}

