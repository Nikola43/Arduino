/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Nano w/ ATmega328, Platform=avr, Package=arduino
*/

#define __AVR_ATmega328p__
#define __AVR_ATmega328P__
#define ARDUINO 165
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define F_CPU 16000000L
#define ARDUINO 165
#define ARDUINO_AVR_NANO
#define ARDUINO_ARCH_AVR
extern "C" void __cxa_pure_virtual() {;}

void LEDPIN_Init(void);
void LED_WrCmd(unsigned char cmd);
void LED_Fill(unsigned char bmp_data);
void LED_DLY_ms(unsigned int ms);
void SetStartColumn(unsigned char d);
void SetAddressingMode(unsigned char d);
void SetColumnAddress(unsigned char a, unsigned char b);
void SetPageAddress(unsigned char a, unsigned char b);
void SetStartLine(unsigned char d);
void SetContrastControl(unsigned char d);
void Set_Charge_Pump(unsigned char d);
void Set_Segment_Remap(unsigned char d);
void Set_Entire_Display(unsigned char d);
void Set_Inverse_Display(unsigned char d);
void Set_Multiplex_Ratio(unsigned char d);
void Set_Display_On_Off(unsigned char d);
void SetStartPage(unsigned char d);
void Set_Common_Remap(unsigned char d);
void Set_Display_Offset(unsigned char d);
void Set_Display_Clock(unsigned char d);
void Set_Precharge_Period(unsigned char d);
void Set_Common_Config(unsigned char d);
void Set_VCOMH(unsigned char d);
void Set_NOP(void);
void LED_Init(void);
void LED_P6x8Str(unsigned char x,unsigned char y,char ch[]);
void LED_P8x16Str(unsigned char x,unsigned char y,char ch[]);
void LED_PrintValueFP(unsigned char x, unsigned char y, unsigned int data, unsigned char num);
//
//

#include "C:\Arduino\hardware\arduino\avr\variants\eightanaloginputs\pins_arduino.h" 
#include "C:\Arduino\hardware\arduino\avr\cores\arduino\arduino.h"
#include <..\Oled_china\Oled_china.ino>
