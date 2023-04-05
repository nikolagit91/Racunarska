#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <unistd.h>
#include <stdlib.h>

#define changeHexToInt(hex) ((((hex)>>4) *10 ) + ((hex)%16) )

//adrese registara
#define SEK 0x02
#define MINUT 0x03
#define SAT 0x04
#define DAN 0x05
#define MES 0x07
#define GOD 0x08
unsigned char WriteBuf[2];
unsigned char ReadBuf;
unsigned char g8563_Store[6];
                                // sec,min,sat,dan,mes,god
unsigned char init8563_Store[6]={0x00,0x59,0x08,0x01,0x04,0x23};
int fd;


 void P8563_settime()
{
    //WriteBuf[0] = SEK;
    //WriteBuf[1] = g8563_Store[0];
    wiringPiI2CWriteReg8(fd, SEK, g8563_Store[0]); //ako ovo ne upali umjesto fd pises 0x51

    //WriteBuf[0] = MINUT;
   // WriteBuf[1] = g8563_Store[1];
    wiringPiI2CWriteReg8(fd, MINUT, g8563_Store[1]);

   // WriteBuf[0] = SAT;
    //WriteBuf[1] = g8563_Store[2];
    wiringPiI2CWriteReg8(fd, SAT, g8563_Store[2]);

    //WriteBuf[0] = DAN;
    //WriteBuf[1] = g8563_Store[3];
     wiringPiI2CWriteReg8(fd, DAN, g8563_Store[3]);

   // WriteBuf[0] = MES;
    //WriteBuf[1] = g8563_Store[4];
     wiringPiI2CWriteReg8(fd, MES, g8563_Store[4]);

   // WriteBuf[0] = GOD;
   // WriteBuf[1] = g8563_Store[5];
     wiringPiI2CWriteReg8(fd, GOD, g8563_Store[5]);
}



void P8563_init()
{
    unsigned char i;
    for(i=0;i<=5;i++)
        g8563_Store[i]=init8563_Store[i];

    P8563_settime();
    printf("Postavi početno tekuće vreme\n");

    //inicijalizacija RTC-a
    //WriteBuf[0] = 0x0; 
    //WriteBuf[1] = 0x00; //normalni rezim rada
     wiringPiI2CWriteReg8(fd, 0x0, 0x00); 
}



void P8563_Readtime()
{
    unsigned char time[7];
    int n;
    
    //WriteBuf[0] = SEK;
    wiringPiI2CWrite(fd, SEK);  //ako nece to probaj WriteReg8
    
    n=read(fd, time, 7);    //wiringPiI2CRead(fd, time, 7) -> alternativa ili Read8
    if (n < 0)
    {
        perror("Greška pri čitanju!");
        exit(1);
    }

    g8563_Store[0] = time[0] & 0x7f; //sekunde
    g8563_Store[1] = time[1] & 0x7f; //minute
    g8563_Store[2] = time[2] & 0x3f; //sati
    g8563_Store[3] = time[3] & 0x3f; //dani
    g8563_Store[4] = time[5] & 0x1f; //mjeseci
    g8563_Store[5] = time[6];        //godine   

    g8563_Store[0] = changeHexToInt(g8563_Store[0]);
    g8563_Store[1] = changeHexToInt(g8563_Store[1]);
    g8563_Store[2] = changeHexToInt(g8563_Store[2]);
    g8563_Store[3] = changeHexToInt(g8563_Store[3]);
    g8563_Store[4] = changeHexToInt(g8563_Store[4]);
    g8563_Store[5] = changeHexToInt(g8563_Store[5]);

}


int main(int argc, char **argv)
{
    fd = wiringPiI2CSetup(0x51);
    if (fd == -1)
        return 1;

    if (wiringPiSetup() < 0){
      printf ("Ne valja");
    return 1 ;
    }

     
    printf("start..........\n");
    P8563_init() ;

    while(1)
    {
        P8563_Readtime();
        printf("Godine: %d Mjeseci: %d Dani: %d Sati: %d Minuti: %d Sekunde: %d\n",g8563_Store[5],g8563_Store[4],g8563_Store[3],g8563_Store[2],g8563_Store[1],g8563_Store[0]);
        delay(5000);
    }

 return 0;
}
