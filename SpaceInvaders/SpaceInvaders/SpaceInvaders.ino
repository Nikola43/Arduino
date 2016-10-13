/*
 * SpaceInvaders.ino
 *
 * Created: 9/28/2014 8:20:43 PM
 * Author: Paulo
 */ 

#include <SMARTGPU.h>     //include the SMARTGPU library!

SMARTGPU lcd;             //create our object called LCD

char pixelArray[3];

//Each time we use the touchscreen we must define a int array that stores the X and Y readed or touched coordinates.
int touch[2];
//Each time we use the touchicon we must define a char array that stores the name of the touched icon.
char icon[3];


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define btnIZQ  2
#define btnUP   3
#define btnDER  4
#define btnDOWN 5
#define btnA	6
#define btnB	7


//Screen size
#define LCD_WIDTH 320
#define LCD_HEIGHT 240

//Max X, Y values depending on orientation definitions
#define MAX_X_LANDSCAPE LCD_WIDTH-1
#define MAX_Y_LANDSCAPE LCD_HEIGHT-1
#define MAX_X_PORTRAIT  LCD_HEIGHT-1
#define MAX_Y_PORTRAIT  LCD_WIDTH-1

//OSCILLOSCOPE DEFINES
#define WIN_HORIZONTAL_START 2            //start pixel for the horizontal window
#define WIN_VERTICAL_START   2            //start pixel for the vertical window
#define WIN_HORIZONTAL_END  LCD_WIDTH-2   //size in pixels of the vertical window
#define WIN_VERTICAL_END    LCD_HEIGHT-2  //size in pixels of the vertical window

void setup()
{
	lcd.init();  //configure the serial and pinout of arduino board for SMARTGPU support
	lcd.start(); //initialize the SMARTGPU processor
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(6, INPUT);
	pinMode(7, INPUT);
}

void loop()
{
	lcd.baudChange(115200);
	while(1)
	{
		lcd.imageSD(50,50,"frenteman"); 
	}
}

void readBtn()
{
	int btnStatus[6] = {0,0,0,0,0,0};
	int buttons[6] = {btnIZQ, btnUP, btnDER, btnDOWN, btnA, btnB};
	int i;
	for(i=0; i<=5; i++)
		btnStatus[i] = digitalRead(buttons[i]);
}