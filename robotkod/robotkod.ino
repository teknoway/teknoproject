#include "deneyap.h"
#include <Deneyap_Servo.h>
#include "NewPing.h"
#define TRIGGER_PIN D1
#define ECHO_PIN D0
#define MAX_DISTANCE 400  
#define srv1 D12
#define srv2 D13
#define srv3 D14
#define bzr D9
Servo servo1;
Servo servo2;
Servo servo3;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;
void mesafeolc()
{

  distance = sonar.ping_cm();
  
  Serial.print("Mesafe = ");
if(distance<10){
  tone(bzr,155);
  delay(50);
  noTone(bzr);
  servo1.write(-180);
  
  delay(100);
}
else{
    servo1.write(-180);

}
  delay(500);
}
void ileri()
{
  int sw1=digitalRead(D8);
  Serial.println(sw1);
  if(sw1==0){
  servo1.write(360);
  delay(100);
  servo2.write(360);
  }
delay(100);

}
 
void setup() 
{
  Serial.begin(9600);
  servo1.attach(srv1);
  servo2.attach(srv2);
  servo3.attach(srv3);
  servo1.write(0);
  servo2.write(180);
  servo3.write(180);
  pinMode(D4,INPUT);
   pinMode(D8,INPUT);
}
void loop() 
{
  mesafeolc();
  ileri();
}