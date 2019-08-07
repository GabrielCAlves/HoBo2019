#include <Ultrasonic.h>

// Sensor US Frente
byte usFTrig = 3;
byte usFEcho = 4;
Ultrasonic usFront(usFTrig, usFEcho);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(usDetect(usFront));
  Serial.print("\n");
  delay(100);
}
