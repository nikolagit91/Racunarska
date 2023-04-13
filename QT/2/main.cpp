#include "dialog.h"
#include <wiringPi.h>
#include <softPwm.h>
//#include <stdio.h>

#include <QApplication>

int main(int argc, char *argv[])
{

      if (wiringPiSetup() == -1)
        exit(1);

      if (softPwmCreate(28, 0, 100) != 0)
        exit (2);

      pinMode(25,OUTPUT);
      digitalWrite(25, HIGH);



    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
