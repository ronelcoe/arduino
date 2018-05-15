#include <Servo.h>

Servo rightServo, leftServo;
int interval = 2000, pos = 0, swingPosition = 60, leftswingPosition = 60;

void setup() {
  rightServo.attach(9);
  leftServo.attach(11);
  setInitialPosition(); 
}

void loop() {
  stepForward(rightServo);
  delay(interval);
  stepLeftForward(leftServo);
}

void setInitialPosition() {
 rightServo.write(0);
 leftServo.write(swingPosition);
}

void stepForward(Servo servo) {
 for (pos = 0; pos <= swingPosition; pos += 1) {
    servo.write(pos);
    delay(5);
  }
  stepBackward(servo);
}

void stepBackward(Servo servo) {
  for (pos = swingPosition; pos > 0; pos--) {
    servo.write(pos);
    delay(15);
  }
}

void stepLeftForward(Servo servo) {
 for (pos = leftswingPosition; pos <= 0; pos -= 1) {
    servo.write(pos);
    delay(5);
  }
  stepLeftBackward(servo);
}

void stepLeftBackward(Servo servo) {
  for (pos = 0; pos <= leftswingPosition; pos+=1) {
    servo.write(pos);
    delay(15);
  }
}

