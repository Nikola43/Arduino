#include "ArduinoCar.h"
#include <SoftwareSerial.h>

// default constructor
ArduinoCar::ArduinoCar()
{
	motor.init();
} //ArduinoCar

// default destructor
ArduinoCar::~ArduinoCar()
{
	
} //~ArduinoCar

void ArduinoCar::marchaAdelante()
{
	motor.setM1Speed(400);
  delay(1);
}

void ArduinoCar::marchaAtras()
{
	motor.setM1Speed(-400);
  delay(1);
}

void ArduinoCar::girarDerecha()
{
	motor.setM1Speed(400);
  delay(1);
}

void ArduinoCar::girarIzquierda()
{
	motor.setM1Speed(-400);
  delay(1);
}

void ArduinoCar::parar()
{
	motor.setM1Speed(0);
  delay(1);
}

void ArduinoCar::tocarBocina()
{
	
}

void ArduinoCar::encenderIntermitenteIzquierdo()
{
	
}

void ArduinoCar::encenderIntermitenteDerecho()
{
	
}

void ArduinoCar::encenderLucesDelanteras()
{
	
}


