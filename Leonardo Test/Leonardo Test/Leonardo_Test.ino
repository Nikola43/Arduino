/*
 * Leonardo_Test.ino
 *
 * Created: 11/9/2014 5:17:28 PM
 * Author: paulo
 */ 

void setup()
{

	  /* add setup code here, setup code runs once when the processor starts */
	  Serial.begin(9600);
	  while(!Serial);
	  Serial.println("Init\n");
	  pinMode(13, 1);

}

void loop()
{
	digitalWrite(13, 1);
	delay(1000);
	digitalWrite(13, 0);
	delay(1000);
	  /* add main program code here, this code starts again each time it ends */
}
