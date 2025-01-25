#include <Arduino.h>
#include "Gate.h"

Gate::Gate() {
  servo.attach(1);
  open();
}

void Gate::open() {
  servo.write(180);
}

void Gate::close() {
  servo.write(90);
}