#define caudalPin A0
int caudal;
int porcentajeCaudal;

void setup() {
  // put your setup code here, to run once:
  pinMode(caudalPin, INPUT);
  Serial.begin(9600);  
}

void loop() {
  caudal = analogRead(caudalPin);  
  porcentajeCaudal =  map(caudal, 0, 1023, 0, 100);
  Serial.print("Porcentaje Caudal: "); Serial.print(porcentajeCaudal);
  Serial.print("\t");
  Serial.print("Caudal: ");Serial.println(caudal);  
  delay(100);
}
