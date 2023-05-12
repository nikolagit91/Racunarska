#include "dialog.h"
#include "ui_dialog.h"


unsigned char decimaltoBCD (int decimal) {

    return (((decimal/10)<<4) | (decimal % 10));
 }


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer=new QTimer(this);
    connect (timer, SIGNAL(timeout()), this,SLOT(update_vremena()));
    timer->setInterval(1000);
    timer->start();
}


Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{

   QTime setovano=QTime::fromString(ui->lineEdit->text(), "hh:mm:ss");

   if (!setovano.isValid())
        QMessageBox::warning(this, "NEPRAVILAN FORMAT", "Unesite vreme u formatu ----> 'hh:mm:ss'.");
   else
   {
        init8563_Store[2]=decimaltoBCD(setovano.hour());
        init8563_Store[1]=decimaltoBCD(setovano.minute());
        init8563_Store[0]=decimaltoBCD(setovano.second());
        P8563_init();
        ui->lineEdit_2->setText(setovano.toString("hh:mm:ss"));
   }
}



void Dialog::update_vremena()
{
    P8563_Readtime();
    QTime novo(g8563_Store[2],g8563_Store[1],g8563_Store[0]);
    ui->lineEdit_2->setText(novo.toString("hh:mm:ss"));

}

