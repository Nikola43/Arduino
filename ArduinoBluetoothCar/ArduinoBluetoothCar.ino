#include "ArduinoCar.h"
#include <SoftwareSerial.h>
#define TXD 4
#define RXD 5

SoftwareSerial BTSerial(RXD, TXD); // RX | TX
ArduinoCar * coche = new ArduinoCar();

char datosRecibidos = '0';
char datosEnviados = '0';

void setup()
{
	Serial.begin(115200);
	BTSerial.begin(115200);
}

void loop()
{
	// Leia la salida del HC-05 and envie al Monitor Serial del Arduino
	if (BTSerial.available())
	{
		Serial.print("Datos Recibidos: ");
		datosRecibidos = BTSerial.read();
		Serial.write(datosRecibidos);
		Serial.println();
	}
	
	// Leia el que  fue  digitado en el Monitor Serial del Arduino y envie al HC-05
	if (Serial.available())
	{
		Serial.print("Datos Enviados: ");
		datosEnviados = Serial.read();
		BTSerial.write( datosEnviados );
		BTSerial.println();
	}
	
	if ( datosRecibidos != 0 )
	{
		if ( datosRecibidos == '1' )
		{
			coche->marchaAdelante()	;
		}
		if ( datosRecibidos == '3' )
		{
			coche->marchaAtras();
		}
		if ( datosRecibidos == '2' )
		{
      
			coche->parar();
		}
	}

  delay(1);
  datosRecibidos = 0;
	
}
