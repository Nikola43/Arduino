#include "ArduinoCar.h"
#include <SoftwareSerial.h>
#include "notas.h"

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
	motor.setM2Speed(-200);
}

void ArduinoCar::marchaAdelantePlus()
{
  motor.setM2Speed(-400);
}

void ArduinoCar::marchaAtras()
{
	motor.setM2Speed(400);
}

void ArduinoCar::girarDerecha()
{
	motor.setM1Speed(400);
}

void ArduinoCar::girarIzquierda()
{
	motor.setM1Speed(-400);
}

void ArduinoCar::pararGiro()
{
  motor.setM1Speed(0);
}

void ArduinoCar::parar()
{
	motor.setM2Speed(0);
}

void ArduinoCar::tocarBocina()
{
	
}

void ArduinoCar::pararBocina()
{
  
}
void ArduinoCar::encenderIntermitenteIzquierdo()
{
	
}

void ArduinoCar:: apagarIntermitenteIzquierdo()
{
  
}

void ArduinoCar::encenderIntermitenteDerecho()
{
	
}

void ArduinoCar::apagarIntermitenteDerecho()
{
  
}

void ArduinoCar::apagarLucesDelanteras()
{
  
}
void ArduinoCar::encenderLucesDelanteras()
{
	
}
