int ledPin = 13; // Change the pin number based on your Arduino setup

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the serial input
    String receivedText = Serial.readString();
    
    // Print the received text to the Serial Monitor
    Serial.println("Received text: " + receivedText);

    // Check the received text and control the LED
    if (receivedText.trim() == "turn on") {
      digitalWrite(ledPin, HIGH); // Turn on the LED
      delay(5000); // Delay for 1 second (adjust as needed)
      digitalWrite(ledPin, LOW); // Turn off the LED
    } else {
      digitalWrite(ledPin, LOW); // Turn off the LED for any other text
    }
  }
}
