#include <Wire.h>
#include <SoftwareSerial.h>

//HC05 Pins
#define BT_TXD 11
#define BT_RXD 10

typedef struct MPU_DATA
{
	int acelX, acelY, acelZ, giroX, giroY, giroZ, temp;
};

//Direccion I2C 
const int MPU_ADDRESS = 0x68;

MPU_DATA MPU;

//Creamos puerto serie virtual para leer los datos del blueetooh
SoftwareSerial BTSerial(BT_RXD, BT_TXD); // RX | TX

void imprimirLecturaMPU(MPU_DATA MPU);

void setup()
{
	//Iniciamos el puerto serie del arduino y del bluetooth
	Serial.begin(115200);
	BTSerial.begin(115200);
	
	//Inicializamos la comunicacion I2C con el MPU
	Wire.begin();
	Wire.beginTransmission(MPU_ADDRESS);
	Wire.write(0x6B);
	
	//Inicializamos el MPU-6050
	Wire.write(0);
	Wire.endTransmission(true);
}

void loop()
{
    //Iniciamos la transmision
    Wire.beginTransmission(MPU_ADDRESS);
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);
  
    //Solicitamos los datos del sensor
    Wire.requestFrom(MPU_ADDRESS, 14, true);
  
  	//Leemos los datos del sensor
  	MPU.acelX = Wire.read() << 8 | Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  	MPU.acelY = Wire.read() << 8 | Wire.read(); //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  	MPU.acelZ = Wire.read() << 8 | Wire.read(); //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  	MPU.temp  = Wire.read() << 8 | Wire.read(); //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  	MPU.giroX = Wire.read() << 8 | Wire.read(); //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  	MPU.giroY = Wire.read() << 8 | Wire.read(); //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  	MPU.giroZ = Wire.read() << 8 | Wire.read(); //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  	if(BTSerial.available())
  	{
        Serial.println("Recibiendo datos");
  		  Serial.write(BTSerial.read());
  	}
  	  
  	if(Serial.available())
  	{
        Serial.println("Enviando datos");
  		  BTSerial.write(Serial.read());
  	}

    ///imprimirLecturaMPU(MPU);
	  delay(50);
}

void imprimirLecturaMPU(MPU_DATA MPU)
{
	Serial.print("Acel. X = ");     Serial.print(MPU.acelX);
	Serial.print("   | Y = ");      Serial.print(MPU.acelY);
	Serial.print("   | Z = ");      Serial.print(MPU.acelZ);
	Serial.print("   | Gir. X = "); Serial.print(MPU.giroX);
	Serial.print("   | Y = ");      Serial.print(MPU.giroY);
	Serial.print("   | Z = ");      Serial.print(MPU.giroZ);
	Serial.print("   | Temp = ");   Serial.println(MPU.temp/340.00+36.53);
}
