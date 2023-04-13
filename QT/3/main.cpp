#include "dialog.h"
#include <wiringPi.h>
#include <QApplication>

int main(int argc, char *argv[])
{


    if (wiringPiSetup() == -1)
      exit(1);


    pinMode(25,OUTPUT);
    pinMode(26,OUTPUT);
    pinMode(27,OUTPUT);
    pinMode(28,OUTPUT);



    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
