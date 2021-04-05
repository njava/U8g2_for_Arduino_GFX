/*

  Hello_Adafruit_ILI9341.ino

  Demonstrates how to connect U8g2_for_Adafruit_GFX to Adafruit SSD1306 library.

  U8g2_for_Adafruit_GFX:
    - Use U8g2 fonts with Adafruit GFX
    - Support for UTF-8 in print statement
    - 90, 180 and 270 degree text direction

  List of all U8g2 fonts: https://github.com/olikraus/u8g2/wiki/fntlistall

*/
#include <Arduino_GFX_Library.h>
#include <U8g2_for_Arduino_GFX.h>

// ILI9225 LCD 176x220
Arduino_DataBus *bus = new Arduino_ESP32PAR8(5 /*TFT_DC*/, 25 /*TFT_CS*/, 26 /* WR */, 13 /* RD */, 19, 21, 22, 23, 18, 12, 14, 15);
Arduino_GFX *gfx = new Arduino_ILI9225(bus, 27/*TFT_RST*/, 2);
U8G2_FOR_ARDUINO_GFX u8g2_for_arduino_gfx;

void setup() {
  gfx->begin();
  u8g2_for_arduino_gfx.begin(*gfx);                 // connect u8g2 procedures to Arduino GFX
  gfx->fillScreen(BLACK);
}

unsigned long x = 0;

void loop() {
  u8g2_for_arduino_gfx.setFontMode(0);                 // use u8g2 none transparent mode
  u8g2_for_arduino_gfx.setFontDirection(0);            // left to right (this is default)
  u8g2_for_arduino_gfx.setForegroundColor(WHITE);      // apply Adafruit GFX color
  u8g2_for_arduino_gfx.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2_for_arduino_gfx.setCursor(0, 20);               // start writing at this position
  u8g2_for_arduino_gfx.print("Hello World");
  u8g2_for_arduino_gfx.setCursor(0, 40);               // start writing at this position
  u8g2_for_arduino_gfx.print("Umlaut ÄÖÜ");            // UTF-8 string with german umlaut chars

  u8g2_for_arduino_gfx.setFont(u8g2_font_inb63_mn);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2_for_arduino_gfx.setFontMode(0);                 // use u8g2 none transparent mode
  u8g2_for_arduino_gfx.setCursor(0, 220);               // start writing at this position
  u8g2_for_arduino_gfx.print(x);            // UTF-8 string with german umlaut chars
  x++;
  delay(1000);
}