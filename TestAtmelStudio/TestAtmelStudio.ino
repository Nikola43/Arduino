int byteRecibido = 0;
int led = 13;

void setup()
{
	Serial.begin(9600);
	pinMode(led, OUTPUT);
}

void loop()
{
	if (Serial.available() > 0)
	{
		byteRecibido = Serial.read();
	}
	
	if ( byteRecibido == '1' )
	{
		digitalWrite(led, HIGH);
		Serial.write('1');
	}
	else if( byteRecibido == '2' )
	{
		digitalWrite(led, LOW);
		Serial.write('2');
	}
	else
	{
		Serial.write('3');
	}
	delay(100);
}