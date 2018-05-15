#include <Servo.h>

Servo rockingServo;
int interval = 5000, pos = 0, swingPosition = 110;

void setup() {
  rockingServo.attach(9);
  setInitialPosition(); 
}

void loop() {
  setSwingPosition();
  delay(interval);
}

void setInitialPosition() {
 rockingServo.write(0);
}

void setSwingPosition() {
 for (pos = 0; pos <= swingPosition; pos += 2) {
    rockingServo.write(pos);
    delay(5);
  }
  setInitialPosition();
}

