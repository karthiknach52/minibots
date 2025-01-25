#include "Gate.h"
#include <Arduino.h>
#include <Servo.h>

Servo servo;

const int GATE_HIGH = 90;
const int GATE_LOW = 180;

Gate::Gate() {
  servo.attach(1);
  servo.write(GATE_LOW);
  delay(1000);
}

void Gate::close() {
  servo.write(GATE_LOW);
}

void Gate::open() {
  servo.write(GATE_HIGH);
}