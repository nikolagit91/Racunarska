#include "dialog.h"
#include <wiringPi.h>
#include "ui_dialog.h"




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


void Dialog::on_pushButton_clicked(bool checked)
{
    digitalWrite(25, checked ? HIGH : LOW);

}


void Dialog::on_pushButton_2_clicked(bool checked)
{
    digitalWrite(26, checked ? HIGH : LOW);

}


void Dialog::on_pushButton_3_clicked(bool checked)
{

    digitalWrite(27, checked ? HIGH : LOW);

}


void Dialog::on_pushButton_4_clicked(bool checked)
{

    digitalWrite(28, checked ? HIGH : LOW);
}

