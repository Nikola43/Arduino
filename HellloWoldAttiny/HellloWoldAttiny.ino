void setup()
{
	//Serial.begin(9600);
  /* add setup code here */
  pinMode(0, OUTPUT	);
}

void loop()
{

  /* add main program code here */
	digitalWrite(0, 1);
	delay(1000);
	digitalWrite(0,0);
	delay(1000);
}
