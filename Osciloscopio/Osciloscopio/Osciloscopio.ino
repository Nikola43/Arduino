/*********************************************************
VIZIC TECHNOLOGIES. COPYRIGHT 2014.
THE DATASHEETS, SOFTWARE AND LIBRARIES ARE PROVIDED "AS IS." 
VIZIC EXPRESSLY DISCLAIM ANY WARRANTY OF ANY KIND, WHETHER 
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
OR NONINFRINGEMENT. IN NO EVENT SHALL VIZIC BE LIABLE FOR 
ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF 
PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, 
ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO 
ANY DEFENCE THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION,
OR OTHER SIMILAR COSTS.
*********************************************************/

/********************************************************
 IMPORTANT : This Example is created for the Arduino 1.0 Software IDE
 -------------MINIMUM INPUT VOLTAGE IS 0 VOLTS--------------------
--------------MAX INPUT VOLTAGE IS 3.3 VOLTS----------------------
********************************************************/

#include <SMARTGPU.h>                     //include the SMARTGPU2 library!

SMARTGPU lcd;                             //create our object called LCD

#define GRAY 0x528A                        //GRAY colour of the grid

#define  LCD_WIDTH 320
#define LCD_HEIGHT 240

//Max X, Y values depending on orientation definitions
#define MAX_X_LANDSCAPE LCD_WIDTH-1
#define MAX_Y_LANDSCAPE LCD_HEIGHT-1
#define MAX_X_PORTRAIT  LCD_HEIGHT-1
#define MAX_Y_PORTRAIT  LCD_WIDTH-1

//OSCILLOSCOPE DEFINES
#define WIN_HORIZONTAL_START 10            //start pixel for the horizontal window
#define WIN_VERTICAL_START   25            //start pixel for the vertical window
#define WIN_HORIZONTAL_END  LCD_WIDTH-10   //size in pixels of the vertical window
#define WIN_VERTICAL_END    LCD_HEIGHT-25  //size in pixels of the vertical window

#define PROBE_INPUT         A0             //select the input pin for the oscilloscope - A0 analog pin
#define MAX_INPUT_VOLTAGE   5.0            //maximum input voltage to the PROBE_INPUT pin
#define MAX_SAMPLES         WIN_HORIZONTAL_END - WIN_HORIZONTAL_START  //must be the substraction of those 2 numbers

unsigned int sampleBuffer[MAX_SAMPLES];                                //array to store ADC probe samples

int touch[2];
float voltaje;


char *floatToString(char * outstr, float value, int places, int minwidth=0, boolean rightjustify=false)
{
	// this is used to write a float value to string, outstr.  oustr is also the return value.
	int digit;
	float tens = 0.1;
	int tenscount = 0;
	int i;
	float tempfloat = value;
	int c = 0;
	int charcount = 1;
	int extra = 0;
	// make sure we round properly. this could use pow from <math.h>, but doesn't seem worth the import
	// if this rounding step isn't here, the value  54.321 prints as 54.3209

	// calculate rounding term d:   0.5/pow(10,places)
	float d = 0.5;
	if (value < 0)
	d *= -1.0;
	// divide by ten for each decimal place
	for (i = 0; i < places; i++)
	d/= 10.0;
	// this small addition, combined with truncation will round our values properly
	tempfloat +=  d;

	// first get value tens to be the large power of ten less than value
	if (value < 0)
	tempfloat *= -1.0;
	while ((tens * 10.0) <= tempfloat) {
		tens *= 10.0;
		tenscount += 1;
	}

	if (tenscount > 0)
	charcount += tenscount;
	else
	charcount += 1;

	if (value < 0)
	charcount += 1;
	charcount += 1 + places;

	minwidth += 1; // both count the null final character
	if (minwidth > charcount){
		extra = minwidth - charcount;
		charcount = minwidth;
	}

	if (extra > 0 and rightjustify) {
		for (int i = 0; i< extra; i++) {
			outstr[c++] = ' ';
		}
	}

	// write out the negative if needed
	if (value < 0)
	outstr[c++] = '-';

	if (tenscount == 0)
	outstr[c++] = '0';

	for (i=0; i< tenscount; i++) {
		digit = (int) (tempfloat/tens);
		itoa(digit, &outstr[c++], 10);
		tempfloat = tempfloat - ((float)digit * tens);
		tens /= 10.0;
	}

	// if no places after decimal, stop now and return

	// otherwise, write the point and continue on
	if (places > 0)
	outstr[c++] = '.';


	// now write out each decimal place by shifting digits one by one into the ones place and writing the truncated value
	for (i = 0; i < places; i++) {
		tempfloat *= 10.0;
		digit = (int) tempfloat;
		itoa(digit, &outstr[c++], 10);
		// once written, subtract off that digit
		tempfloat = tempfloat - (float) digit;
	}
	if (extra > 0 and not rightjustify) {
		for (int i = 0; i< extra; i++) {
			outstr[c++] = ' ';
		}
	}


	outstr[c++] = '\0';
	return outstr;
}

/*********************************************************/
void initSampleBuffer(void){
  unsigned int i;
  for(i=0; i < MAX_SAMPLES; i++) sampleBuffer[i] = WIN_VERTICAL_END;
  sampleBuffer[0]= getScaledSample();  //get first sample
}

/*********************************************************/
void showIntro(void){
  int aux=5,xs,ys,i, time=50;

  lcd.string(2,2,MAX_X_LANDSCAPE,MAX_Y_LANDSCAPE, RED, FONT3, 1, "SmartGPU: Osciloscopio");
  lcd.string(20,MAX_Y_LANDSCAPE-35,MAX_X_LANDSCAPE,MAX_Y_LANDSCAPE, RED, FONT3, 1, "Paulo Soares");
  while(time--){
    //draw next circle
    xs=(sin(((aux*24)*3.14)/180)) * 40;
    ys=(cos(((aux*24)*3.14)/180)) * 40;
    lcd.drawCircle((LCD_WIDTH/2)+xs,(LCD_HEIGHT/2)-ys,2,BLUE,FILL); 
    //erase previous circle
    xs=(sin((((aux-5)*24)*3.14)/180)) * 40;
    ys=(cos((((aux-5)*24)*3.14)/180)) * 40;
    lcd.drawCircle((LCD_WIDTH/2)+xs,(LCD_HEIGHT/2)-ys,3,BLACK,FILL);    
    //increase vaiable aux
    if(aux++ > 13) aux=0;        
    delay(100);
  }
  lcd.erase();               //erase screen before exit 
}

/*********************************************************/
unsigned int getScaledSample(void)
{                       
    float value;
    value = analogRead(PROBE_INPUT);                         //Take a sample from the PROBE
    value = value * MAX_INPUT_VOLTAGE;                       //scale to max input voltage
    value = value / 1023;                                    //divide by the max input value of ADC
    voltaje = value;
    value = value * ((WIN_VERTICAL_END - WIN_VERTICAL_START) / 5); //multiply value by the grid division value in pixels
    if(value > (WIN_VERTICAL_END - WIN_VERTICAL_START)) return WIN_VERTICAL_START;
    return WIN_VERTICAL_END - value;                         //return window vertical end substracting the scaled value
}

/*********************************************************/
void drawGrid()
{
   unsigned int i;
   for(i=WIN_HORIZONTAL_START; i<=WIN_HORIZONTAL_END; i+=(WIN_HORIZONTAL_END - WIN_HORIZONTAL_START)/5)
       lcd.drawLine(i,WIN_VERTICAL_START,i,WIN_VERTICAL_END,GRAY);
   for(i=WIN_VERTICAL_START; i<=WIN_VERTICAL_END; i+=(WIN_VERTICAL_END - WIN_VERTICAL_START)/5)
       lcd.drawLine(WIN_HORIZONTAL_START,i,WIN_HORIZONTAL_END,i,GRAY);
}

/*********************************************************/
void updateScreen(void)
{
    static int drawPointer= 0;
    sampleBuffer[drawPointer+1]= getScaledSample();                                              //store a scaled sample
    lcd.drawLine(drawPointer+WIN_HORIZONTAL_START, sampleBuffer[drawPointer], drawPointer+WIN_HORIZONTAL_START+1, sampleBuffer[drawPointer+1], YELLOW);        //draw fresh sample
    drawPointer++;
    if((drawPointer+2) >= MAX_SAMPLES)
	{
        drawGrid();                                                                              //re-draw Grid
        drawPointer = 0;  
    }
    lcd.drawLine(drawPointer+WIN_HORIZONTAL_START+1, sampleBuffer[drawPointer+1], drawPointer+WIN_HORIZONTAL_START+2, sampleBuffer[drawPointer+2], BLACK);         //erase old sample
  
  
  lcd.string(20,MAX_Y_LANDSCAPE-20,MAX_X_LANDSCAPE,MAX_Y_LANDSCAPE, RED, FONT3, 1, "Volts/Div:");
  char b1[25];
  floatToString(b1, voltaje, 5);
  lcd.string(100 ,MAX_Y_LANDSCAPE-20, MAX_X_LANDSCAPE ,MAX_Y_LANDSCAPE, RED, FONT3, 1, b1);
}

/*********************************************************/
void drawInterface(void)
{
    lcd.drawRectangle(WIN_HORIZONTAL_START, WIN_VERTICAL_START, WIN_HORIZONTAL_END, WIN_VERTICAL_END, BLACK, FILL);   //draw plotting area
    drawGrid();
    lcd.string(2,2,MAX_X_LANDSCAPE,30, RED, FONT3, 1, "SmartGPU 2 - Simple Oscilloscope");
}

void setup() 
{ 
    //Those two functions must always be called for SMARTGPU2 support
    lcd.init();  //configure the serial and pinout of arduino board for SMARTGPU2 support
    lcd.start(); //initialize the SMARTGPU2 processor
  
    //oscilloscope configurations
    //set analog reference as EXTERNAL to avoid damage to arduino boards when using smartGPU2 as shield, this is already done in the smartGPU2 library
    //analogReference(EXTERNAL); //which AREF is connected to 3.3V of SmartGPU2 board
    pinMode(PROBE_INPUT, INPUT);
  
    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: 250.000 kHz
    // Mode: Normal top=0xFFFF
    TCCR1A=0x00;
    TCCR1B=0x03;  //timer will increase count one step every 4 microseconds
}

/*********************************************************/
/*********************************************************/
/*********************************************************/
/*********************************************************/
void loop()
{ 
    lcd.baudChange(115200); //for fast drawing we need a big baudRate
  
    showIntro();           //a Small intro  
    drawInterface();       //draws all the oscilloscope body and interface
    initSampleBuffer();    //initialize the sample Buffer to lowest value possible
   
    while(1)
	{
      delay(1);
      updateScreen(); 
    }
}
