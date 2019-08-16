#include "ir.h"
#include "motor.h"
#include "color.h"

#define COUNTER_NINETY 35

IR left(A15);
IR center(A14);
IR right(A13);

void setup() {
  setupMotors();
  Serial.begin(9600);
}
int lc= 0;
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
  drive(LEFT);
  delay(150);
  drive(RIGHT);
  delay(150);
  drive(FRONT);
  delay(150);
  drive(BACK);
  delay(150);
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
  int td=200, fd=200;
  drive(RIGHT, td);
  drive(FRONT, fd);
  drive(LEFT, td);
  drive(FRONT, fd);
  drive(LEFT, td);
  drive(FRONT, fd);
  drive(RIGHT, td);
}
