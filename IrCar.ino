// #define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <IRremote.h>

const int forwardPin = 8;
const int backwardPin = 12;
const int readPin = A5;
const int delayTime = 15;

void turnMotorOn();
void turnMotorOff();

unsigned long lastSignal = 0;

IRrecv irrecv(readPin);
decode_results results;

void setup() {
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  /*
  // For raw IR reading
  pinMode(readPin, INPUT);
  */
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received: ");
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  /*
  // Print out sensor reads as bits
  int sensorValue = analogRead(readPin);
  float voltage = sensorValue * (5.0 / 1024.0);
  delay(delayTime);
  if ((voltage >= 0) && (voltage <= 0.4)) {
    Serial.print("1");
    lastSignal = millis();
  } else if ((voltage > 0.4) && (voltage <= 2)) {
    Serial.print("1");
  } else {
    Serial.print("0");
  }
  */

  /*
  // For raw IR reading
  int sensorValue = analogRead(readPin);
  float voltage = sensorValue * (5.0 / 1024.0);
  Serial.println(sensorValue);

  delay(delayTime);
  // the lower the voltage, the brighter it is
  if ((voltage >= 0) && (voltage <= 0.4)) {
    Serial.print("it is light - ");
    lastSignal = millis();
  } else if ((voltage > 0.4) && (voltage <= 2)) {
    Serial.print("it is bright - ");
  } else {
    Serial.print("it is dark - ");
  }

  if (millis() - lastSignal < 750) {
    turnMotorOn();
    } else {
      turnMotorOff();
      }
  */
  
}

void turnMotorOn() {
  digitalWrite(forwardPin, HIGH);
    digitalWrite(backwardPin, HIGH);
  }

void turnMotorOff() {
  digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);
}
