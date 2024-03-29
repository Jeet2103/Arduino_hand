int sensor = A0; // Connected to digital output of KY-038 sound sensor module
int led = 13; // Connected to postive of led
boolean is_on = false; //To determine/track if led is on or off

void setup() {
  pinMode(sensor, INPUT); //Setting the pin to input for reading data
  pinMode(led, OUTPUT); //Setting the pin to output for turning the led on/off
  Serial.begin(9600);

}

void loop() {

  int data = analogRead(sensor); //Reading data from sensor and storing in variable
  Serial.println(data);
  // Serial.println("noob");
  if (data == 1) { // 1 is sent from sensor when loud noise is detected
    if (is_on == true) { // If led is on then turn it off
      digitalWrite(led, LOW);
      is_on = false;
    }
    else { // else if led is off then turn it on
      digitalWrite(led, HIGH);
      is_on = true;
    }
  }
  // delay(200);
  
}
