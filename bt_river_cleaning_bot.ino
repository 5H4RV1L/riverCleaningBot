#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <AFMotor.h>

AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // put your setup code here, to run once:
  Dabble.begin(9600, 2, 3);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor2.setSpeed(100);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Dabble.processInput();

  if (GamePad.isUpPressed()) {
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
    delay(100);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  } 
  else if (GamePad.isDownPressed()) {
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
    delay(100);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  } 
  else if (GamePad.isLeftPressed()) {
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    delay(100);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  } 
  else if (GamePad.isRightPressed()) {
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    delay(100);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
  else if(GamePad.isCirclePressed()) {
    motor2.run(FORWARD);
  }
  else if(GamePad.isCrossPressed()) {
    motor2.run(RELEASE);
  }
}