#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4

#define OLED_DC 9
#define OLED_CS 10

// For SPI, use SPI_BEGIN or SPI_FULL_SPEED for the last parameter
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_RESET, OLED_DC, OLED_CS, OLED_RESET);
void setup() {
  Serial.begin(9600);

  // Replace SSD1306_I2C_ADDRESS with the actual I2C address of your display (e.g., 0x3C)
  if (!display.begin(0x3C, OLED_RESET, OLED_DC, OLED_CS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.display();
}


void loop() {
  // Your main code here

  // Clear the display
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Set the cursor position
  display.setCursor(0, 0);

  // Print "Hello, World!" on the OLED screen
  display.print(F("Hello, World!"));

  // Show the display
  display.display();

  // Delay for 2 seconds
  delay(2000);
}

