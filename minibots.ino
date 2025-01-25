#include "Motor.h"
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
Motor motor;

const int wallDistance = 100;

void setup() {

  Serial.begin(9600);
  while (!Serial){};

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
  
  motor.drive();

  if (sensor.readRangeContinuousMillimeters() < wallDistance) {
    motor.brake(HIGH);
    delay(500);
    motor.turn(LEFT);
  }

  Serial.println(sensor.readRangeContinuousMillimeters());

}