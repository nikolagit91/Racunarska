#include "dialog.h"
#include <QApplication>

#define changeHexToInt(hex) ((((hex)>>4) *10 ) + ((hex)%16) )

//adrese registara
#define SEK 0x02
#define MINUT 0x03
#define SAT 0x04
#define DAN 0x05
#define MES 0x07
#define GOD 0x08


const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;
unsigned char init8563_Store[3];
unsigned char g8563_Store[3];

int fd;
int lcd;


void P8563_settime()
{
   wiringPiI2CWriteReg8(fd, SEK, g8563_Store[0]); //ako ovo ne upali umjesto fd pises 0x51


   wiringPiI2CWriteReg8(fd, MINUT, g8563_Store[1]);


   wiringPiI2CWriteReg8(fd, SAT, g8563_Store[2]);
}


void P8563_init()
{
    unsigned char i;
    for(i=0;i<=2;i++)
        g8563_Store[i]=init8563_Store[i];

    P8563_settime();

    //inicijalizacija RTC-a
    wiringPiI2CWriteReg8(fd, 0x0, 0x00);
}


void P8563_Readtime()
{
    unsigned char time[3];
    int n;


    wiringPiI2CWrite(fd, SEK);

    n=read(fd, time, 3);
    if (n < 0)
    {
        perror("Greška pri čitanju!");
        exit(1);
    }

    g8563_Store[0] = time[0] & 0x7f; //sekunde
    g8563_Store[1] = time[1] & 0x7f; //minute
    g8563_Store[2] = time[2] & 0x3f; //sati


    g8563_Store[0] = changeHexToInt(g8563_Store[0]);
    g8563_Store[1] = changeHexToInt(g8563_Store[1]);
    g8563_Store[2] = changeHexToInt(g8563_Store[2]);
}



int main(int argc, char *argv[])
{

    fd = wiringPiI2CSetup(0x51);
         if (fd == -1)
             return 1;

         if (wiringPiSetup() < 0){
           printf ("Ne valja");
         return 1 ;
         }



     lcd = lcdInit(2, 16, 4, RS, EN, D0, D1, D2,D3, D0, D1, D2, D3);
     lcdClear(lcd);

     pinMode(25, OUTPUT);

    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
