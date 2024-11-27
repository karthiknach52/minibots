// https://docs.arduino.cc/tutorials/motor-shield-rev3/msr3-controlling-dc-motor/


// Motor Pin Definitions
int directionPinL = 12;
int pwmPinL = 3;
int brakePinL = 9;
int directionPinR = 13;
int pwmPinR = 11;
int brakePinR = 8;


void setup() {
  
pinMode(directionPinL, OUTPUT);
pinMode(pwmPinL, OUTPUT);
pinMode(brakePinL, OUTPUT);

pinMode(directionPinR, OUTPUT);
pinMode(pwmPinR, OUTPUT);
pinMode(brakePinR, OUTPUT);

}

void drive() {
  digitalWrite(directionPinL, HIGH);
  digitalWrite(directionPinR, HIGH);

  digitalWrite(brakePinL, LOW);
  digitalWrite(brakePinR, LOW);

  analogWrite(pwmPinL, 100);
  analogWrite(pwmPinR, 100);
}

void brake() {
  digitalWrite(brakePinL, HIGH);
  digitalWrite(brakePinR, HIGH);

  analogWrite(pwmPinL, 0);
  analogWrite(pwmPinR, 0);
}


// Left is 1, Right is 2
void turn(int direction) {

  if (direction == 1):
    digitalWrite(directionPinL, LOW);
    digitalWrite(directionPinR, HIGH);
  else:
    digitalWrite(directionPinL, HIGH);
    digitalWrite(directionPinR, LOW);

  digitalWrite(brakePinL, LOW);
  digitalWrite(brakePinR, LOW);

  analogWrite(pwmPinL, 100);
  analogWrite(pwmPinR, 100);

  delay(500);

  brake();

}

void loop() {

  drive();

  delay(2000);

  brake();

  delay(2000);

  turn(1);

  delay(2000);

}