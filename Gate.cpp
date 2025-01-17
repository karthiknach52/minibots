#include <Arduino.h>
#include "Gate.h"

Gate::Gate() {
  servoL.attach(1);
  servoR.attach(2);

  servoL.write(90);
  servoR.write(90);

  delay(1000);
}

void Gate::open() {
  const int openTime = 500;

  servoL.write(180);
  servoR.write(0);

  delay(openTime);

  servoL.write(90);
  servoR.write(90);

  delay(1000);
}