#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
String receivedText,rtn;
U8G2_SSD1309_128X64_NONAME0_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/10, /* dc=*/9, /* reset=*/8);
void setup(void) {
  u8g2.begin();
  Serial.begin(9600);
}


void loop(void) {
  rtn = Serial.readString();
  if(rtn.length()>0)
  {
    receivedText=rtn;
    Serial.print("Received");
    Serial.print(receivedText);
    // Read the serial input
    u8g2.clearBuffer();                  // clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr);  // choose a suitable font
    u8g2.drawStr(0, 10,receivedText.c_str());

    // write something to the internal memory
    u8g2.sendBuffer();  // transfer internal memory to the display
    delay(1000);
  }
}
