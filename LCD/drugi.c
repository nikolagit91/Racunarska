// kompajlirati sa -lwiringPi -lwiringPiDev
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <lcd.h>

// dodela vrednosti za konkretne pinove
// prema gornjoj tabeli i semi DVK512
const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;

int taster=0;
int taster_prethodni;
int taster_pritisnut=0;


int main(){

 
    if (wiringPiSetup() < 0){
        fprintf (stderr, "Greška pri inicijalizaciji:%s\n", strerror (errno)) ;
    return 1 ;
    }
    
    int lcd;
    int x=0;
    int y=0;
    lcd = lcdInit(2, 16, 4, RS, EN, D0, D1, D2,D3, D0, D1, D2, D3);
    pinMode (21, INPUT); //key_0
    pinMode (22, INPUT); //key_1
    pinMode (23, INPUT); //key_2
    pinMode (24, INPUT); //key_3

    while (1) {
   
    if (digitalRead(21)==0) taster_pritisnut=1;
    if (digitalRead(22)==0) taster_pritisnut=2;
    if (digitalRead(23)==0) taster_pritisnut=3;
    if (digitalRead(24)==0) taster_pritisnut=4;



    taster_prethodni=taster;
    taster=taster_pritisnut;
    
    if  (taster!=taster_prethodni && taster_pritisnut) {

        if (taster_pritisnut==1) {
            x++;
                if (x>15) x=0;
        }


         if (taster_pritisnut==2) {
            x--;
                if (x<0) x=15;
        }


         if (taster_pritisnut==3) {
            y++;
                if (y>1) y=0;
        }


         if (taster_pritisnut==4) {
            y--;
                if (y<0) y=0;
        }
    }
    taster_pritisnut=0;


    lcdPosition(lcd, x,y);
    lcdCursor(lcd,1);
    delay(200);     
    }
return 0; 
}
