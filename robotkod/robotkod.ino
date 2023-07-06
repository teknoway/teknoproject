
#include "deneyap.h"
#include "NewPing.h" 
#include <Deneyap_Servo.h>
#define bzr D9
#define led D4
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
#define trigPin 14
#define echoPin 13
long duration;
float distanceCm;
float distanceInch;
Servo servo1;
Servo servo2;


void setup() {
  servo1.attach(D0);
  servo2.attach(D1);
  pinMode(bzr,OUTPUT);
  pinMode(led,OUTPUT);
   pinMode(D14,OUTPUT);
  pinMode(D13,INPUT);
    pinMode(D8,INPUT);

}
void mesafe_olc() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED/2;
  distanceInch = distanceCm * CM_TO_INCH;
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  delay(1000);
}
void ileri(){
  int sw1=digitalRead(D8);
  Serial.println(sw1);
  if(sw1==0||distanceCm<10)
  {
  servo1.write(90);
  delay(500);
  servo2.write(90);
  }
}
void loop() {
mesafe_olc(); 
ileri();

}
