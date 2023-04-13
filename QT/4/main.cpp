#include "dialog.h"
#include <QApplication>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
    if (wiringPiSetup() == -1)
        exit(1);


    pinMode(25,OUTPUT);

    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
