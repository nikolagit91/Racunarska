#include "dialog.h"
#include "ui_dialog.h"
using namespace std;



unsigned char decimaltoBCD (int decimal) {

    return (((decimal/10)<<4) | (decimal % 10));
 }

int p=0;
int am_pm=0;
int alarm_flag=0;




Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    timer=new QTimer(this);
    connect (timer, SIGNAL(timeout()), this,SLOT(update_vremena()));
    timer->setInterval(1000);
    timer->start();


    timer2=new QTimer(this);
    connect (timer2, SIGNAL(timeout()), this,SLOT(lcd_ispis()));
    timer2->setInterval(500);
    timer2->start();
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
    trenutno.setHMS(g8563_Store[2],g8563_Store[1],g8563_Store[0]);
    ui->lineEdit_2->setText(trenutno.toString("hh:mm:ss"));

    if (trenutno==alarm){
        alarm_flag=1;
    }


    if (alarm_flag){

        static int stanje=HIGH;
        digitalWrite(25,stanje);
        stanje=(stanje==HIGH) ? LOW : HIGH;

        static int i=0;
        i++;
        if (i==10) {
            alarm_flag=0;
            i=0;
         }
    }
}



void Dialog::lcd_ispis()
{
    if (am_pm==0) {
        string=trenutno.toString("hh:mm:ss");
    }
    if (am_pm==1) {
        string=trenutno.toString("h:m:s a");
    }

    lcdClear(lcd);
    lcdPosition(lcd,0,p);
    lcdPrintf(lcd,"%s", string.toLatin1().constData());
}



void Dialog::on_checkBox_stateChanged(int arg1)
{
    if (arg1==2)
        p=1;
    else
        p=0;
}



void Dialog::on_radioButton_clicked()
{
     am_pm=0;
}



void Dialog::on_radioButton_2_clicked()
{
     am_pm=1;
}



void Dialog::on_pushButton_2_clicked()
{
    alarm=QTime::fromString(ui->lineEdit_3->text(), "hh:mm:ss");

    if (!alarm.isValid())
         QMessageBox::warning(this, "NEPRAVILAN FORMAT", "Unesite vreme u formatu ----> 'hh:mm:ss'.");

}

