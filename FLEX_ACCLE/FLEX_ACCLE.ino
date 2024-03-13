#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
void setup() {
  Serial.begin(9600);
  if (!accel.begin()) {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  const int numReadings = 100;
  int val1, val2, val3, val4, val5, i=0;
  int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;

  sensors_event_t event;
  accel.getEvent(&event);
  float x = event.acceleration.x;
  float y = event.acceleration.y;
  float z = event.acceleration.z;

  for (int i = 0; i < numReadings; i++) {
    val1 = analogRead(A1);
    val2 = analogRead(A2);
    val3 = analogRead(A3);
    val4 = analogRead(A4);
    val5 = analogRead(A5);

    sum1 += val1;
    sum2 += val2;
    sum3 += val3;
    sum4 += val4;
    sum5 += val5;

    delay(10);
  }
  sum1 = sum1; 
  sum2 = sum2;
  sum3 = sum3;
  sum4 = sum4;
  sum5 = sum5;
  //x = (x+10)/2;
  //y = (y+10)/2;
  // z = (z+10)/2;
  Serial.print(sum1);
  Serial.print(",");
  Serial.print(sum2);
  Serial.print(",");
  Serial.print(sum3);
  Serial.print(",");
  Serial.print(sum4);
  Serial.print(",");
  Serial.print(sum5);
  Serial.print(",");

  Serial.print(x);
  Serial.print(",");

  Serial.print(y);
  Serial.print(",");
  Serial.print(z);
  Serial.println();
  // while(!Serial.available()){

  // }
  // char userInput = Serial.read();
  // char userInput2 = Serial.read();
  delay(2000);  
}