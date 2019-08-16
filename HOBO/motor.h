#ifndef __MOTOR_H
#define __MOTOR_H

#define MOTOR_DELAY 3500
#define REG_TIMES 5
#define TURN_TIMES 5
#define BACK_TIMES 0

#define FRONT 1542
#define LEFT 3254
#define RIGHT 5217
#define BACK 5454
  
int portsR[] = {28, 26, 24, 22};
int portsL[] = {29, 27, 25, 23};

void setupMotors() {
  for (int i = 0; i < 4; i++) {
    pinMode(portsL[i], OUTPUT);
    pinMode(portsR[i], OUTPUT);
  }
}

void drive(int dir=FRONT, int times=REG_TIMES, int d=MOTOR_DELAY) {
  if (((dir == RIGHT) || (dir == LEFT)) && times == REG_TIMES) times == TURN_TIMES;
  while (times--) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int onL = ( ((dir==FRONT) || (dir==RIGHT)) ? i : 3-i);
        int onR = ( ((dir==FRONT) || (dir==LEFT)) ? i : 3-i);
        digitalWrite(portsL[j], (j == onL ? HIGH : LOW));
        digitalWrite(portsR[j], (j == onR ? HIGH : LOW));
      }
      delayMicroseconds(d);
    }
  }
  if ((dir == RIGHT) || (dir == LEFT)) drive(BACK, BACK_TIMES, MOTOR_DELAY);
}

#endif
