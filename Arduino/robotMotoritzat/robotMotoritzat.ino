#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>

#define ledPin            2

#define forwardLeft       12
#define reverseLeft       13

#define forwardRight      15
#define reverseRight      16

#define echoSensorLeft    4
#define echoSensorRight   5
#define triggerSensors    14

#define groundSensor      A0

#define unused1           9
#define usused2           10

#define GROUND_COLOR      200

void goForward (){
  digitalWrite (forwardLeft, HIGH);
  digitalWrite (reverseLeft, LOW);
  
  digitalWrite (forwardRight, HIGH);
  digitalWrite (reverseRight, LOW);
}

void goReverse (){
  digitalWrite (forwardLeft, LOW);
  digitalWrite (reverseLeft, HIGH);
  
  digitalWrite (forwardRight, LOW);
  digitalWrite (reverseRight, HIGH);
}

void turnLeft (){
  digitalWrite (forwardLeft, LOW);
  digitalWrite (reverseLeft, HIGH);
  
  digitalWrite (forwardRight, HIGH);
  digitalWrite (reverseRight, LOW);
}

void turnRight (){
  digitalWrite (forwardLeft, HIGH);
  digitalWrite (reverseLeft, LOW);
  
  digitalWrite (forwardRight, LOW);
  digitalWrite (reverseRight, HIGH);
}

void readUltrasonicSensors (int& left, int& right){
  digitalWrite(triggerSensors, HIGH);        // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  
  digitalWrite(triggerSensors, LOW);         // Clears the trigPin
  
  int leftDuration = pulseIn(echoSensorLeft, HIGH);
  left = leftDuration * 0.034 / 2;   // Reads the echoPin, returns the sound wave travel time in microseconds and calculating the distance
  
  //int rightDuration = pulseIn(echoSensorRight, HIGH);
  //right =  rightDuration * 0.034 / 2; // Reads the echoPin, returns the sound wave travel time in microseconds and calculating the distance
}

bool readGroundOk (){
  return analogRead (groundSensor) >= GROUND_COLOR;
}

void setup() {
  delay(2000);
  
  Serial.begin(115200);

  pinMode (ledPin, OUTPUT);
  digitalWrite (ledPin, HIGH);

  pinMode (forwardLeft, OUTPUT);
  pinMode (reverseLeft, OUTPUT);

  pinMode (forwardRight, OUTPUT);
  pinMode (reverseRight, OUTPUT);

  pinMode (echoSensorLeft, INPUT);
  pinMode (echoSensorRight, INPUT);
  pinMode (triggerSensors, OUTPUT);
  digitalWrite(triggerSensors, LOW);
  
  pinMode (groundSensor, INPUT);
}

int leftSensor, rightSensor;

void loop() {
  
  /*readUltrasonicSensors (leftSensor, rightSensor);
  if (! readGroundOk ()){
    Serial.println ("Go Reverse");
    goReverse();
    delay (100);

    Serial.println ("Turn Left");
    turnLeft ();
    delay (1000);
  }

  if (leftSensor < 20 || rightSensor < 20){
  //if (leftSensor < 20){
    Serial.println ("Go Reverse");
    goReverse();
    delay (100);
  }
  while (leftSensor < 20 || rightSensor < 20){
  //while (leftSensor < 20){
    Serial.println ("Turn Left");
    turnLeft ();
    delay (100);
    readUltrasonicSensors (leftSensor, rightSensor);
  }*/

  Serial.println ("Go Forward");
  goForward ();
  delay(3000);

  Serial.println ("Go Reverse");
  goReverse ();
  delay(3000);

  Serial.println ("Turn Right");
  turnRight ();
  delay(3000);

  Serial.println ("Turn Left");
  turnLeft ();
  delay(3000);
}
