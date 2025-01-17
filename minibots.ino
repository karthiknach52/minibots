#include "Motor.h"
#include "Gate.h"
#include <Servo.h>
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

Motor motor;

Servo servoL;

void setup() {
  servoL.attach(1);

  Serial.begin(9600);
  // while (!Serial){};

  Wire.begin();
  sensor.setTimeout(500);

  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

  sensor.startContinuous();

  servoL.write(180);

}

void loop() {
  
  Serial.print(sensor.readRangeContinuousMillimeters());

  if (sensor.readRangeContinuousMillimeters() < 100) {
    servoL.write(90);
    motor.drive();
    delay(1000);
    motor.brake(HIGH);
    servoL.write(180);
  }

  Serial.println();

}