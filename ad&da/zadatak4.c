#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <lcd.h>
#include <unistd.h>
#include <softPwm.h>

const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;

const char PCF8591 = 0x48; 
int fd, osvjetljenje;
const char *nivo[]={"NOCNO","SLABO","DNEVNO"};
int i=0;

int main() {

	if (wiringPiSetup () == -1) exit (1);
		fd = wiringPiI2CSetup(PCF8591);
	
	int lcd;
	lcd = lcdInit(2, 16, 4, RS, EN, D0, D1, D2,D3, D0, D1, D2, D3);
	
	if (softPwmCreate(28,0,100)!=0)
		exit(2);
		
	pinMode(25,OUTPUT);


while (1) {

	//pali diodu
	digitalWrite(25,0); // isprobaj hoce li raditi isto sa LOW ili HIGH umjesto 0
	
	
	// procitaj trimer pot sa AIN0 ulaza - senzor svjetla
	osvjetljenje = wiringPiI2CReadReg8(fd, PCF8591 + 0) ;
	
	
	if (osvjetljenje > 220 && osvjetljenje < 231) {
		softPwmWrite (28,100);
		i=2;
	}
	
	if (osvjetljenje > 230 && osvjetljenje < 241) {
		softPwmWrite (28,50);
		i=1;
	}
	
	if (osvjetljenje > 240 && osvjetljenje < 256) {
		softPwmWrite (28,10);
		i=0;
	}


	lcdClear(lcd);
	lcdPosition(lcd, 0,0);
	lcdPrintf(lcd,"Osvjetljenje je:");
	lcdPosition(lcd, 0,1);
	lcdPrintf(lcd,"%s", nivo[i]);
	delay(50);
}


return 0;
}
