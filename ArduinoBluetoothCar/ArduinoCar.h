#include "ArduinoMotorShieldR3.h"
#include <Arduino.h>

#ifndef __ARDUINOCAR_H__
#define __ARDUINOCAR_H__
class ArduinoCar
{
  private:
    ArduinoMotorShieldR3 motor;
    ArduinoCar( const ArduinoCar &c );
    ArduinoCar& operator=( const ArduinoCar &c );
    
  public:
  	 	ArduinoCar();
  	 	~ArduinoCar();
  	 	void marchaAdelante();
      void marchaAdelantePlus();
  	 	void marchaAtras();
  	 	void girarDerecha();
  	 	void girarIzquierda();
      void pararGiro();
  	 	void tocarBocina();
      void pararBocina();
  	 	void encenderIntermitenteIzquierdo();
      void apagarIntermitenteIzquierdo();
  	 	void encenderIntermitenteDerecho();
      void apagarIntermitenteDerecho();
  	 	void encenderLucesDelanteras();
      void apagarLucesDelanteras();
  		void parar();
}; //ArduinoCar

#endif //__ARDUINOCAR_H__
