#include "dialog.h"
#include "ui_dialog.h"
#include <wiringPi.h>

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
    if (checked) {
        QPixmap pixmap(":/slike/ukljuceno.png");
        ui->label->setPixmap(pixmap);
    }

    else {
        QPixmap pixmap(":/slike/iskljuceno.png");
        ui->label->setPixmap(pixmap);
    }
}

