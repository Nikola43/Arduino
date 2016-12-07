//SerialPortSensorTemperatura.ino

//Definimos los pines donde van conectados el led y el sensor
#define pinLed 13
#define pinSensorTemperatura A0

//Variable para almacenar el valor leido
int valorLeidoSensorTemperatura = 0;

void setup() 
{
    Serial.begin(9600);
    pinMode(pinLed, OUTPUT);
}

void loop() 
{
    leerTemperatura();

    digitalWrite(pinLed, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(pinLed, LOW);   // turn the LED off by making the voltage LOW
    delay(100);               // wait for a second
}

void leerTemperatura ()
{
	valorLeidoSensorTemperatura = analogRead(pinSensorTemperatura);
}