#include "color.h"
#include "motor.h"
#include "ir.h"
#include "Ultrasonic.h"

#define COUNTER_NINETY 35

IR left(A15);
IR center(A14);
IR right(A13);

Ultrasonic us(9, 8);

void setup() {
  setupMotors();
  Serial.begin(9600);
}

int lc = 0;

void loop() {
  /*
    Serial.print(left.readVal());
    Serial.print(" ");
    Serial.print(center.readVal());
    Serial.print(" ");
    Serial.print(right.readVal());
    Serial.print(" ");
    Serial.print("\n");
  */

  /*
     if (!((lc++)%6)) {
       if (rightSensor.isGreen()) {
         delay(50);
         if (rightSensor.isGreen())
           delay(10000);
       }
     } */
  /*
      if (!right.isBlack() && !left.isBlack()) drive(FRONT);
      else if (right.isBlack()) {
      int counter = 0;
      do { drive(RIGHT); counter++; }
      while (!center.isBlack());
      if (counter > COUNTER_NINETY) {
               delay(1000);
         drive(FRONT, 35);
      }
      }
      else if (left.isBlack()) {
      int counter = 0;
      do { drive(LEFT); counter++; }
      while (!center.isBlack());
      if (counter > COUNTER_NINETY) {
        delay(1000);
        drive(FRONT, 50);
      }
      }
      else drive(FRONT);
  */
  int diff = right.readVal() - left.readVal();

  int sensibility = 40;
  int maxSpeed = 2500;
  int maxSpeedFrom = 80;

  if (diff > sensibility) drive(LEFT, 5, max(maxSpeed, maxSpeed / (diff / maxSpeedFrom)));
  else if (diff < -sensibility) drive(RIGHT, 5, max(maxSpeed, maxSpeed / (diff / maxSpeedFrom)));
  else drive(FRONT);

  if ((++lc % 20) == 0) {
    int dist = us.read();
    Serial.println(dist);
  
    if ((dist < 4) && (dist > 0)) {
      Serial.println("ENGAGE!!!!!");
      int td = 350, fd = 200;
      drive(BACK, 50);
      drive(RIGHT, td);
      drive(FRONT, fd);
      drive(LEFT, td);
      drive(FRONT, fd);
      drive(LEFT, td);
      drive(FRONT, fd);
      drive(RIGHT, td);
  
    }
  }
 
}
