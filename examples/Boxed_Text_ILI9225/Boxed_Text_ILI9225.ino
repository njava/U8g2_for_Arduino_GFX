/*

  Boxed_Text_ILI9225.ino

  Demonstrates how to draw a fitting box around a text.

  List of all U8g2 fonts: https://github.com/olikraus/u8g2/wiki/fntlistall
      
*/
#include <Arduino_GFX_Library.h>
#include <U8g2_for_Arduino_GFX.h>

// ILI9225 LCD 176x220
Arduino_DataBus *bus = new Arduino_ESP32PAR8(5 /*TFT_DC*/, 25 /*TFT_CS*/, 26 /* WR */, 13 /* RD */, 19, 21, 22, 23, 18, 12, 14, 15);
Arduino_ILI9225 *gfx = new Arduino_ILI9225(bus, 27/*TFT_RST*/, 2);
U8G2_FOR_ARDUINO_GFX u8g2_for_arduino_gfx;

void setup() {
    gfx->begin();
	u8g2_for_arduino_gfx.begin(*gfx);                 // connect u8g2 procedures to Adafruit GFX
}

void loop() {  
  const char s[] = "gfx LCD";
  /* width and height of the text */
  int16_t height;
  int16_t width;
  /* desired position of the text */
  int16_t x = 4;
  int16_t y = 25;
  gfx->fillScreen(BLACK);                               // clear the graphcis buffer  
  u8g2_for_arduino_gfx.setFont(u8g2_font_helvB14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2_for_arduino_gfx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_arduino_gfx.setFontDirection(0);            // left to right (this is default)
  u8g2_for_arduino_gfx.setForegroundColor(WHITE);      // apply Adafruit GFX color
  u8g2_for_arduino_gfx.setCursor(x, y);                // start writing at this position
  u8g2_for_arduino_gfx.print(s);
  /* calculate the size of the box into which the text will fit */
  height = u8g2_for_adafruit_gfx.getFontAscent() - u8g2_for_adafruit_gfx.getFontDescent();
  width = u8g2_for_adafruit_gfx.getUTF8Width(s);
  /* draw the box around the text*/
  gfx->drawRect(x, y-u8g2_for_adafruit_gfx.getFontAscent(), width, height, WHITE);
                                     // make everything visible
  delay(2000);
} 
