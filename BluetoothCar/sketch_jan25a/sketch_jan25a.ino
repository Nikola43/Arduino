#include "Coche.h"
#include <SoftwareSerial.h>
#include "ArduinoMotorShieldR3.h"
#define TXD 4
#define RXD 5

SoftwareSerial BTSerial(RXD, TXD); // RX | TX
ArduinoMotorShieldR3 md;
int datosRecibidos = 0;
int datosEnviados = 0;

void setup()
{
  Serial.begin(115200);
  BTSerial.begin(115200);
  md.init();
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
      datosEnviados = Serial.read()
      BTSerial.write( datosEnviados );
      BTSerial.println();
  }

  if ( datosRecibidos != 0 )
  {
      switch()
      {
          case '1' : marchaAdelante(); break;
          case '1' : marchaAtras(); break;
          case '1' : girarDerecha(); break;
          case '1' : girarIzquierda(); break;
          case '1' : tocarBocina(); break;
          case '1' : encenderIntermitenteDerecho(); break;
          case '1' : encenderIntermitenteIzquierdo(); break;
          case '1' : encenderLucesDelanteras(); break;
          
          
          
      }
  }
}

void marchaAdelante()
{
    Serial.println("M1 Speed 100% Forward");
    md.setM1Speed(400);
}

void marchaAtras()
{
    Serial.println("M1 Speed 100% Backward");
    md.setM1Speed(-400);
}

void girarDerecha()
{
      Serial.println("M2 Speed 100% Forward");
      md.setM2Speed(400);
}

void girarIzquierda()
{
      Serial.println("M2 Speed 100% Forward");
      md.setM2Speed(-400);
}

void tocarBocina()
{
  
}

void encenderIntermitenteIzquierdo()
{
  
}

void encenderIntermitenteDerecho()
{
  
}

void encenderLucesDelanteras()
{
  
}

void moverMotor()
{
  
  Serial.println("M1 Speed 100% Forward");
  md.setM1Speed(400);
  Serial.println("M2 Speed 100% Forward");
  md.setM2Speed(400);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);

  Serial.println("M1 Speed 100% Backward");
  md.setM1Speed(-400);
  Serial.println("M2 Speed 100% Backward");
  md.setM2Speed(-400);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);
  
  Serial.println("M1 Speed 50% Forward");
  md.setM1Speed(200);
  Serial.println("M2 Speed 50% Forward");
  md.setM2Speed(200);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);

  Serial.println("M1 Speed 50% Backward");
  md.setM1Speed(-200);
  Serial.println("M2 Speed 50% Backward");
  md.setM2Speed(-200);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);
  
  Serial.println("M1 Speed 0%");
  md.setM1Speed(0);
  Serial.println("M2 Speed 0%");
  md.setM2Speed(0);
  Serial.print("M1 current: ");
  Serial.println(md.getM1CurrentMilliamps());
  Serial.print("M2 current: ");
  Serial.println(md.getM2CurrentMilliamps());
  delay(2000);
}

