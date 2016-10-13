
const int LDR = A0;  // Analog input pin that the potentiometer is attached to
const int LED = 13; // Analog output pin that the LED is attached to
const int RELE = 2;


int LDRValue = 0;        // value read from the pot

void setup()
{
	// initialize serial communications at 9600 bps:
	Serial.begin(9600);
	pinMode(LDR, INPUT);
	pinMode(LED, OUTPUT);
	pinMode(RELE, OUTPUT);
}

void loop()
{
		LDRValue = analogRead(LDR);

		Serial.print("Valor LDR = " );
		Serial.println(LDRValue);
		
		if(LDRValue < 500)
		{
			digitalWrite(RELE, HIGH);
		}
		else
		{
			digitalWrite(RELE, LOW);
		}

		delay(5);
}