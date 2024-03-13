#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // I2C address for 128x64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Declare the bitmaps
const uint8_t image_Lock_7x8_bits[] PROGMEM = {0x1c, 0x22, 0x22, 0x7f, 0x7f, 0x77, 0x7f, 0x3e};
const uint8_t image_Bluetooth_Idle_5x8_bits[] PROGMEM = {0x04, 0x0d, 0x16, 0x0c, 0x0c, 0x16, 0x0d, 0x04};
const uint8_t image_Volup_8x6_bits[] PROGMEM = {0x48, 0x8c, 0xaf, 0xaf, 0x8c, 0x48};
const uint8_t image_Alert_9x8_bits[] PROGMEM = {0x10, 0x00, 0x38, 0x00, 0x28, 0x00, 0x6c, 0x00, 0x6c, 0x00, 0xfe, 0x00, 0xee, 0x00, 0xff, 0x01};

int progress = 0; // progress of the progressbar
char buffer[32]; // helper buffer to construct a string to be displayed

void setup(void) {
  Serial.begin(9600);

  if (!display.begin(SSD1306_I2C_ADDRESS)) 
 {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.display();
  delay(2000);  // Pause for 2 seconds
  display.clearDisplay();
}

void loop(void) {
  display.clearDisplay();					// clear the internal memory

  display.drawRect(12, 21, 104, 20, SSD1306_WHITE);
  display.fillRect(14, 23, progress, 16, SSD1306_WHITE); // draw the progressbar fill
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  sprintf(buffer, "Progress: %d%%", progress); // construct a string with the progress variable
  display.setCursor(33, 53);
  display.print(buffer); // display the string

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 7);
  display.print(F("Progress Bar Screen"));

  display.drawLine(0, 9, 127, 9, SSD1306_WHITE);
  display.drawBitmap(100, 0, image_Lock_7x8_bits, 7, 8, SSD1306_WHITE);
  display.drawBitmap(111, 0, image_Bluetooth_Idle_5x8_bits, 5, 8, SSD1306_WHITE);
  display.drawBitmap(120, 1, image_Volup_8x6_bits, 8, 6, SSD1306_WHITE);
  display.drawBitmap(22, 45, image_Alert_9x8_bits, 9, 8, SSD1306_WHITE);

  display.display();					// transfer internal memory to the display

  // increase the progress value to go over 0-100
  progress = progress + 1;
  if (progress > 100) {
    progress = 0;
  }

  delay(100);  // Adjust the delay based on your needs
}
