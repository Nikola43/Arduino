void setup()
{

  /* add setup code here */
  pinMode(13, OUTPUT);

}

void loop()
{

  /* add main program code here */
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(13,0);
  delay(1000);

}
