/* YourDuinoStarter Example: 2 Stepper Motors
 - WHAT IT DOES: Runs 2 28BYJ-48 stepper motors with AccelStepper Library
 - Motors accelerate and decelerate simultaneously in opposite rotations
 - SEE the comments after "//" on each line below
 -  Derived from example code by Mike McCauley
 -  modified by Celem for single stepper
 -  modified by lowres for two steppers 
 NOTE: This may not run 2 motors from USB. 
       May need separate +5 Supply for motors
 - CONNECTIONS: See Pin definitions below

 - V1.01 11/30/2013
   Questions: terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <AccelStepper.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define FULLSTEP 4
#define HALFSTEP 8
// motor pins
#define motorPin1  A0     // Blue   - 28BYJ48 pin 1
#define motorPin2  A1     // Pink   - 28BYJ48 pin 2
#define motorPin3  A2     // Yellow - 28BYJ48 pin 3
#define motorPin4  A3     // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
                        
#define motorPin5  8     // Blue   - 28BYJ48 pin 1
#define motorPin6  9     // Pink   - 28BYJ48 pin 2
#define motorPin7  10    // Yellow - 28BYJ48 pin 3
#define motorPin8  11    // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
/*-----( Declare objects )-----*/
// NOTE: The sequence 1-3-2-4 is required for proper sequencing of 28BYJ48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

/*-----( Declare Variables )-----*/
//none

#include <Ultrasonic.h>

Ultrasonic ultrasonic(5,6); // (Trig PIN,Echo PIN)

void setup()   /****** SETUP: RUNS ONCE ******/
{
  stepper1.setMaxSpeed(5000.0);
  stepper1.setAcceleration(50.0);
  stepper1.setSpeed(20);
  stepper1.moveTo(1024);  // 1 revolution 
  
  stepper2.setMaxSpeed(5000.0);
  stepper2.setAcceleration(50.0);
  stepper2.setSpeed(20);
  stepper2.moveTo(-1024);  // 1 revolution 

    Serial.begin(9600);
  pinMode(4, OUTPUT); // VCC pin
  pinMode(7, OUTPUT); // GND ping
  digitalWrite(4, HIGH); // VCC +5V mode  
  digitalWrite(7, LOW);  // GND mode

}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{

    Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );

  //Change direction at the limits

    if (stepper2.distanceToGo() == 0) 
    stepper2.moveTo(-stepper2.currentPosition());
  
  stepper1.run();
  stepper2.run();

}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/
//none
//*********( THE END )***********
