/*

  Hello_Adafruit_SSD1306.ino

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
}

void loop() {  
   gfx->fillScreen(BLACK);   
  u8g2_for_arduino_gfx.setFontDirection(0);            // left to right (this is default)
  u8g2_for_arduino_gfx.setForegroundColor(WHITE);      // apply Adafruit GFX color
  
  u8g2_for_arduino_gfx.setFont(u8g2_font_siji_t_6x10);  // icon font
  u8g2_for_arduino_gfx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_arduino_gfx.drawGlyph(0, 10, 0x0e200);  // Power Supply
  u8g2_for_arduino_gfx.drawGlyph(12, 10, 0x0e201);  // Charging
  u8g2_for_arduino_gfx.drawGlyph(24, 10, 0x0e10a);  // Right Arrow
  u8g2_for_arduino_gfx.drawGlyph(36, 10, 0x0e24b);  // full Battery

  u8g2_for_arduino_gfx.setFont(u8g2_font_7x13_te);  // extended font
  u8g2_for_arduino_gfx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_arduino_gfx.setCursor(0,40);                // start writing at this position
  u8g2_for_arduino_gfx.print("<Ȧǀʘ>");            // UTF-8 string: "<" 550 448 664 ">"
 
  delay(2000);
} 

