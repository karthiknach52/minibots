// https://docs.arduino.cc/tutorials/motor-shield-rev3/msr3-controlling-dc-motor/

int directionPinA = 12;
int pwmPinA = 3;
int brakePinA = 9;

int directionPinB = 13;
int pwmPinB = 11;
int brakePinB = 8;

//boolean to switch direction
bool directionState;

void setup() {
  
//define pins as outputs
pinMode(directionPinA, OUTPUT);
pinMode(pwmPinA, OUTPUT);
pinMode(brakePinA, OUTPUT);

pinMode(directionPinB, OUTPUT);
pinMode(pwmPinB, OUTPUT);
pinMode(brakePinB, OUTPUT);

}

void loop() {

//change direction every loop()
directionState = !directionState;

//write a low state to the direction pin (13)
if(directionState == false){
  digitalWrite(directionPinA, LOW);
  digitalWrite(directionPinB, LOW);
}

//write a high state to the direction pin (13)
else{
  digitalWrite(directionPinA, HIGH);
  digitalWrite(directionPinB, HIGH);
}

//release breaks
digitalWrite(brakePinA, LOW);
digitalWrite(brakePinB, LOW);

//set work duty for the motor
analogWrite(pwmPinA, 100);
analogWrite(pwmPinB, 100);

delay(2000);

//activate breaks
digitalWrite(brakePinA, HIGH);
digitalWrite(brakePinB, HIGH);

//set work duty for the motor to 0 (off)
analogWrite(pwmPinA, 0);
analogWrite(pwmPinB, 0);

delay(2000);
}