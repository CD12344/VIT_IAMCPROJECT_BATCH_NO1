#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 3;
const int distanceThreshold = 20; // distance in cm

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0); // lid closed
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  if (distance <= distanceThreshold) {
    myServo.write(90); // lid open
    delay(5000); // keep the lid open for 5 seconds
    myServo.write(0); // lid closed
  }
  
  delay(200);
}
