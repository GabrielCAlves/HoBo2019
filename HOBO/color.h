#ifndef __COLOR_H
#define __COLOR_H

struct Sensor {
  int s[4];
  int out;

  Sensor(int _s[4], int _out) {
    out = _out;
    pinMode(out, INPUT);

    for (int i = 0; i < 4; i++) {
      s[i] = _s[i];
      pinMode(s[i], OUTPUT);
    }

    digitalWrite(s[0], HIGH);
    digitalWrite(s[1], LOW);
  }

  void setSensors(int a, int b) {
    digitalWrite(s[2], a);
    digitalWrite(s[3], b);
  }

  bool isGreen() {
    int R, G, B;
    R = G = B = -1;

    setSensors(LOW, LOW);
    R = pulseIn(out, LOW);
    delay(10);

    setSensors(HIGH, HIGH);
    G = pulseIn(out, LOW);
    delay(10);

    setSensors(LOW, HIGH);
    B = pulseIn(out, LOW);
    delay(10);

    int redMin = 21, redMax = 84;
    int greenMin = 23, greenMax = 92;
    int blueMin = 19, blueMax = 81;

    int r = map(R, redMin, redMax, 255, 0);
    int g = map(G, greenMin, greenMax, 255, 0);
    int b = map(B, blueMin, blueMax, 255, 0);

    if ( ((g - b) > 30) && ((g - r) > 30) && (abs(g - 80) < 40)) {
      //Serial.println("GREEN ");
      return true;
    } else {
      /*Serial.print("NOT GREEN");
      if (((g - b) <= 30)) Serial.print("BECAUSE BLUE ");
      if (((g - r) <= 30)) Serial.print("BECAUSE RED ");
      if (abs(g - 80) >= 40) Serial.print("BECAUSE ABS");
      Serial.println();
*/
      return false;
    }
  }
};

int ls[] = {36, 37, 38, 39};
int rs[] = {30, 31, 32, 33};

Sensor leftSensor(ls, 35);
Sensor rightSensor(rs, 34);

#endif
