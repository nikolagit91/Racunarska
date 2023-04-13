#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <softPwm.h>
using namespace std;


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


void Dialog::on_horizontalSlider_sliderMoved(int position)
{
    softPwmWrite(28, position);
    cout << "Ispuna je: " << position << endl;
}

