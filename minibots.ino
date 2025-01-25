#include "Motor.h"
#include <Wire.h>
#include <VL53L0X.h>
#include <math.h>
#include <Servo.h>

Servo servo;

const int GATE_HIGH = 90;
const int GATE_LOW = 180;
VL53L0X sensor;
Motor motor;

const int OBJECT_MIN_DISTANCE = 100;
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
  

  servo.attach(1);
  servo.write(GATE_HIGH);
  sensor.startContinuous();
}

void loop() {

  Serial.println(sensor.readRangeContinuousMillimeters());
  
  motor.drive();
  if (sensor.readRangeContinuousMillimeters()<OBJECT_MIN_DISTANCE){
    motor.brake(HIGH);
    Serial.println("OBJECT DETECTED");
    servo.write(GATE_LOW);
    motor.turn(RIGHT);
    delay(500);
    servo.write(GATE_HIGH);
    delay(500);
    
  }
  delay(100);

}