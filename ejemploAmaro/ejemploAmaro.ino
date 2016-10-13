#define LED 13
#define VOLUMEN A0

int valorLeido = 0;


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Inicio del programa");
  pinMode(LED, OUTPUT);
  pinMode(VOLUMEN, INPUT);
}

void loop()
{
   valorLeido = analogRead(VOLUMEN);
   
   
   
   Serial.print("valorLeido = ");
   Serial.println(valorLeido);
   delay(100);


  if(valorLeido > 500)
      digitalWrite(LED, HIGH);
  else
      digitalWrite(LED, LOW);
   
}
