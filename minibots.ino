#include "Motor.h"
#include <Wire.h>
#include <VL53L0X.h>
#include <math.h>

VL53L0X sensor;
Motor motor;

const int BALL_MAX_DISTANCE = 100;
int detection_len{};

void setup() {

  Serial.begin(9600);
  //while (!Serial){};
  Serial.println("START");

  Wire.begin();
  sensor.setTimeout(500);

  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

  sensor.startContinuous();
}

void loop() {

  Serial.println(sensor.readRangeContinuousMillimeters());

  motor.drive();

  delay(1);

}