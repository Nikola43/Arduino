/*
 * ArduinoBluetooth.ino
 *
 * Created: 2/13/2015 1:09:13 AM
 * Author: Paulo
 */ 

/*

AUTHOR: Hazim Bitar (techbitar)
DATE: Aug 29, 2013
LICENSE: Public domain (use at your own risk)
CONTACT: techbitar at gmail dot com (techbitar.com)

*/


//ArduinoRemote.ino

#include <IRremote.h>

#define RECV_PIN   A0
#define STATUS_LED 13
#define RELAY 12


IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
	pinMode(STATUS_LED, OUTPUT);
	pinMode(RELAY, OUTPUT);
	Serial.begin(9600);
	irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
	if (irrecv.decode(&results))
	{
		//digitalWrite(STATUS_LED, HIGH);
		Serial.println(results.value, HEX);
		irrecv.resume(); // Receive the next value
	}

	switch(results.value)
	{
		case 0xD051C301 : digitalWrite(STATUS_LED, HIGH); digitalWrite(RELAY, HIGH); break;
		case 0xD051C301 : digitalWrite(STATUS_LED, LOW);  digitalWrite(RELAY, LOW);  break;

		case 0x801 : digitalWrite(STATUS_LED, HIGH); digitalWrite(RELAY, HIGH); break;
		case 0x1 : digitalWrite(STATUS_LED, HIGH); digitalWrite(RELAY, HIGH); break;

		case 0x800 : digitalWrite(STATUS_LED, HIGH); digitalWrite(RELAY, LOW); break;
		case 0x0 : digitalWrite(STATUS_LED, HIGH); digitalWrite(RELAY, LOW); break;


		//default : Serial.println("Ese boton no esta configurado");
	}
}
