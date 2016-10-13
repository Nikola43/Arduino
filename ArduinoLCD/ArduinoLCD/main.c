/*
 * ArduinoLCD.c
 *
 * Created: 07/11/2015 14:49:01
 * Author : Paulo
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include "lcd.h"


int counter;

int main(void)
{
	lcd_init(LCD_DISP_ON_CURSOR); /* initialize lcd, display on, cursor on */
	
	
	DDRB |= (1<<PB7);
	DDRE &= (1<<PE4);
	
	PORTB &= (1<<PB7);

	// OR DDRD = 0x00; //Makes all pins of PORTD input
	while(1) //infinite loop
	{
		char buffer[10] = "";
		if (!(PINE & (1<<PE4)))
		{
			counter++;;
			DDRB |= (1<<PB7);
		}
		else
		{
			DDRB &= (1<<PB7);
		}
		
		//Convert int to string
		itoa(counter, buffer, 10);

		lcd_clrscr();             /* clear screen of lcd */
		lcd_home();               /* bring cursor to 0,0 */
		lcd_puts("Pasos: ");        /* type something random */
		lcd_gotoxy(0,1);          /* go to 2nd row 1st col */
		lcd_puts(buffer);         /* print buffer */
		_delay_ms(500);            /* wait 50ms */
		lcd_clrscr();
	}
}