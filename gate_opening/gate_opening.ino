/* This code opens the gate if the bottom ultrasonic sensor detects something and the top does not.
It will print "Top detection" if the only the top sensor detects an object, "Bottom detection" if only the bottom detects and "Both detection" if both and "No detection" if neither
*/
// Initializing pins for ultrasonic sensor
const int trigPinBot = 7;  
const int echoPinBot = 8; 
const int trigPinTop = 9;  
const int echoPinTop = 10; 
float durationTop, distanceTop, durationBot, distanceBot;  
const int detectionThreshold = 20;  // Threshold for detecting an object (in cm)

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPinTop, OUTPUT);  
  pinMode(echoPinTop, INPUT);  
  pinMode(trigPinBot, OUTPUT);  
  pinMode(echoPinBot, INPUT);  
  Serial.begin(9600);  
}

void loop() {
  // Get the top sensor's distance
  digitalWrite(trigPinTop, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinTop, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinTop, LOW);
  
  durationTop = pulseIn(echoPinTop, HIGH);
  distanceTop = (durationTop * 0.0343) / 2;
  
  // Get the bottom sensor's distance
  digitalWrite(trigPinBot, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinBot, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinBot, LOW);
  
  durationBot = pulseIn(echoPinBot, HIGH);
  distanceBot = (durationBot * 0.0343) / 2;
  
  // Print the distances
  Serial.print("Top Distance: ");
  Serial.print(distanceTop);
  Serial.print(" cm, ");
  Serial.print("Bottom Distance: ");
  Serial.println(distanceBot);

  // Check for detection based on the distance threshold
  bool topDetected = (distanceTop < detectionThreshold);  // Top sensor detects if distance is less than threshold
  bool bottomDetected = (distanceBot < detectionThreshold);  // Bottom sensor detects if distance is less than threshold
  
  // Determine what to print based on the sensor states
  if (topDetected && bottomDetected) {
    Serial.println("Both detection");
  } else if (topDetected) {
    Serial.println("Top detection");
  } else if (bottomDetected) {
    Serial.println("Bottom detection");
  } else {
    Serial.println("No detection");
  }
  
  delay(100);  // Short delay before the next loop
}

