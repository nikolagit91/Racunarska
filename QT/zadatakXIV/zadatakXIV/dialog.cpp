#include "dialog.h"
#include "ui_dialog.h"


float napon=0;
float temp=0;
float svetlo=0;
int adc1=0;
int r6=0;

void read_sensors(){
    const char PCF8591 = 0x48;
    int fd;

    if (wiringPiSetup () == -1) exit (1);
    fd = wiringPiI2CSetup(PCF8591);

    napon= wiringPiI2CReadReg8(fd, PCF8591 + 3);
    napon= wiringPiI2CReadReg8(fd, PCF8591 + 3);
    adc1= wiringPiI2CReadReg8(fd, PCF8591 + 1);
    adc1= wiringPiI2CReadReg8(fd, PCF8591 + 1);
    svetlo=wiringPiI2CReadReg8(fd, PCF8591 + 0);
    svetlo=wiringPiI2CReadReg8(fd, PCF8591 + 0);
}



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->dial->setDisabled(true);
    ui->verticalSlider->setDisabled(true);

    timer=new QTimer(this);
    connect (timer, SIGNAL(timeout()), this,SLOT(update_parametara()));
    timer->setInterval(200);
    timer->start();
}


Dialog::~Dialog()
{
    delete ui;
}




void Dialog::update_parametara()
{
    read_sensors();

    // pretvaranje napona u volte
    napon=(napon*3.3/255)*10;

    //pretvaranje adc1 u temp
    r6=(1000*adc1)/(256-adc1);
    temp=(298.15*3950)/(3950 + log(r6/10000));
    temp=temp-273.15; // U celzijuse

    //pretvaranje svetlosti u procente
    svetlo=(svetlo/255)*100;

    //ispis na ekran
    ui->dial->setValue(napon);
    ui->verticalSlider->setValue(svetlo);
    ui->lcdNumber->display(temp);
}

