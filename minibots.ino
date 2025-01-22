#include "Motor.h"
#include "Gate.h"
#include <Servo.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <math.h>

VL53L0X sensor;

Motor motor;

Servo servoL;

const int BALL_MAX_DISTANCE = 100;
const int GATE_UP = 90;
const int GATE_LOW = 180;



int detection_len{};

void setup() {
  servoL.attach(1);

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

  servoL.write(GATE_LOW);

}

void loop() {
  // detection_len = sensor.readRangeSingleMillimeters();

  Serial.println(sensor.readRangeContinuousMillimeters());

  motor.drive();

  if (sensor.readRangeContinuousMillimeters() < BALL_MAX_DISTANCE) {
    
    servoL.write(GATE_UP);
    delay(1000);
    servoL.write(GATE_LOW);
  }
  delay(1);


}