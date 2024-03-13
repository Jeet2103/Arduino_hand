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
  int val1, val2, val3, val4, val5;
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
    // sum3*=2;
    sum4 += val4;
    // sum4/=2;
    sum5 += val5;

    delay(10);
  }

  // Serial.print("Analog Sums: ");
  Serial.print(sum1);
  Serial.print("\t");
  Serial.print(sum2);
  Serial.print("\t");
  Serial.print(sum3);
  Serial.print("\t");
  Serial.print(sum4);
  Serial.print("\t");
  Serial.print(sum5);
  Serial.print("\t");

  Serial.print("Accelerometer Values: ");
  Serial.print("X: ");
  Serial.print((x+10)/2);
  Serial.print("\t");
  // Serial.print("Y: ");
  Serial.print((y+10)/2);
  Serial.print("\t");
  // Serial.print("Z: ");
  Serial.print((z+10)/2);
  // Serial.println();
  // if (Serial.available() > 0) {
  //   int userInput = Serial.read();
  //   // Process the user input as needed
  //   // Serial.print("User Input: ");
  //   // Serial.println(userInput);
  // }
  // delay(1000); // Adjust delay as needed
}
