#include "dialog.h"
#include "ui_dialog.h"
#include <wiringPi.h>


void toggleLED() {
    static bool stanje = true;
    digitalWrite(25, stanje ? HIGH : LOW);
    stanje = !stanje;
}

//int stanje=0;

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
     /*if (stanje==0) {
     digitalWrite(25, stanje);
     stanje = 1;
     }

     if (stanje==1) {
     digitalWrite(25, stanje);
     stanje = 0;
     }*/

    toggleLED();


}

