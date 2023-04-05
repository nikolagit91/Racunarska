#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char level0[8] = { 0b11111, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001};
char level1[8] = { 0b11111, 0b01000, 0b01000, 0b01111, 0b01001, 0b01001, 0b01001, 0b01001};
char level2[8] = { 0b10010, 0b10010, 0b10010, 0b10010, 0b10010, 0b10010, 0b10010, 0b00001};
char level3[8] = { 0b10101, 0b10101, 0b10101, 0b10101, 0b10101, 0b10101, 0b10101, 0b11111};
char level4[8] = { 0b00000, 0b01110, 0b01010, 0b01010, 0b11111, 0b10001, 0b10001, 0b10001};
char level5[8] = { 0b11110, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000};
char level6[8] = { 0b10001, 0b10001, 0b10001, 0b10001, 0b11111, 0b00001, 0b00001, 0b00001};
char level7[8] = { 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b00100};
#define COLUMNS 16
#define LCD_RS 3
#define LCD_E 14
#define LCD_D4 4
#define LCD_D5 12
#define LCD_D6 13
#define LCD_D7 6


void volume(void);
int count =0;
char *temp;
int lcd;



int main()
{
    wiringPiSetup();
    if(lcd = lcdInit(2, 16, 4, LCD_RS, LCD_E, LCD_D4,LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0)){
        printf ("lcdInit nije uspeo! \n");
        return -1 ;
    }

    int uptimeTimer;
    
    while(1){

        lcdClear (lcd);
        volume();
        sleep(1);
       
 }
}


void volume(void)
{
    //Definicija specijalnih karaktera za Volume
    lcdCharDef (lcd, 0, level0);
    lcdCharDef (lcd, 1, level1);
    lcdCharDef (lcd, 2, level2);
    lcdCharDef (lcd, 3, level3);
    lcdCharDef (lcd, 4, level4);
    lcdCharDef (lcd, 5, level5);
    lcdCharDef (lcd, 6, level6);
    lcdCharDef (lcd, 7, level7);
    lcdClear (lcd);

    int i;
    int k=0;
    lcdPosition (lcd, 0,0);

    for (i = 0; i < 8; i++){
        lcdPosition (lcd, k, 0);
        lcdPutchar (lcd, i);
        k=k+2;
        usleep(400000);
        
 }
}


