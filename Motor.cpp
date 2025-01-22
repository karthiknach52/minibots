// https://docs.arduino.cc/tutorials/motor-shield-rev3/msr3-controlling-dc-motor/

#include "Motor.h"
#include <Arduino.h>
#include <stdint.h>
#include "Gate.h"

Gate gate;

const int MOTOR_POWER = 150;

Motor::Motor() {
  // Set pins as outputs
  pinMode(directionPinL, OUTPUT);
  pinMode(pwmPinL, OUTPUT);
  pinMode(brakePinL, OUTPUT);

  pinMode(directionPinR, OUTPUT);
  pinMode(pwmPinR, OUTPUT);
  pinMode(brakePinR, OUTPUT);
}

// Setting arg HIGH turns it on and LOW turns it off
void Motor::brake(uint8_t state) {

  gate.open()

  if (state == HIGH) {
      analogWrite(pwmPinL, 0);
      analogWrite(pwmPinR, 0);
  }

  digitalWrite(brakePinL, state);
  digitalWrite(brakePinR, state);
}

void Motor::drive() {
  digitalWrite(directionPinL, HIGH);
  digitalWrite(directionPinR, HIGH);
  
  brake(LOW);

  analogWrite(pwmPinL, MOTOR_POWER); // Speed ranges from 0-100 or 0-255??
  analogWrite(pwmPinR, MOTOR_POWER);
}

void Motor::turn(int direction) {
  int turnTime = 750; // Time in milliseconds to turn for

  if (direction == RIGHT) {
      digitalWrite(directionPinL, HIGH);
      digitalWrite(directionPinR, LOW);
  } else if (direction == LEFT) {
      digitalWrite(directionPinL, LOW);
      digitalWrite(directionPinR, HIGH);
  }

  brake(LOW);

  analogWrite(pwmPinL, MOTOR_POWER);
  analogWrite(pwmPinR, MOTOR_POWER);

  delay(turnTime);

  brake(HIGH);
}