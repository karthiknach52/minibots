/*This code is a basic draft for the minibots code
Currently it just makes the robot move forward */

/* Motor Pin Definitions 
The motor shield is connected to specified pins on the main arduino board which control the DC motor. 
More details can be found here: https://docs.arduino.cc/tutorials/motor-shield-rev3/msr3-controlling-dc-motor/*/
// For channel A (right side of the robot)
int directionPinR = 12;
int pwmPinR = 3;
int brakePinR = 9;

// For channel B (left side of robot)
int directionPinL = 13;
int pwmPinL = 11;
int brakePinL = 8;

//boolean to switch direction
bool directionState;

void setup() {
  // Initialize DC motor pins
  pinMode(directionPinL, OUTPUT);
  pinMode(pwmPinL, OUTPUT);
  pinMode(brakePinL, OUTPUT);

  pinMode(directionPinR, OUTPUT);
  pinMode(pwmPinR, OUTPUT);
  pinMode(brakePinR, OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  //change direction every loop()
  directionState = !directionState;

  //write a low state to the direction pin (13)
  if(directionState == false){
    digitalWrite(directionPinL, LOW);
    digitalWrite(directionPinR, LOW);
  }

  //write a high state to the direction pin (13)
  else{
    digitalWrite(directionPinL, HIGH);
    digitalWrite(directionPinR, HIGH);
  }

  //release breaks
  digitalWrite(brakePinL, LOW);
  digitalWrite(brakePinR, LOW);

  //set work duty for the motor
  analogWrite(pwmPinL, 150);
  analogWrite(pwmPinR, 150);

  delay(2000);

  //activate breaks
  digitalWrite(brakePinL, HIGH);
  digitalWrite(brakePinR, HIGH);

  //set work duty for the motor to 0 (off)
  analogWrite(pwmPinL, 0);
  analogWrite(pwmPinR, 0);

  delay(2000);
}
