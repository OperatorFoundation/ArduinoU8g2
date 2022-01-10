

#include <hangul.h>
#include <inttypes.h>
#include <U8g2lib.h>

// Pin definitions
#define SHARP_SS 19 // TFT's chip select line
#define BLACK 1
#define WHITE 2
#define PAGE_MARGIN 2

#define SCREEN_WIDTH 400 // display width, in pixels
#define SCREEN_HEIGHT 240 // display height, in pixels

U8G2_LS027B7DH01_M0_400X240_F_4W_HW_SPI u8g2Display(U8G2_R2, /* cs=*/ SHARP_SS, /* dc=*/ U8X8_PIN_NONE); //works but the colors are inverted
//u8g2_uint_t cursorY = 0;

String jamoTest = "ㄴ";
String characterTest = "녕";


void setup() {
  u8g2Display.begin();
  u8g2Display.enableUTF8Print();    // enable UTF8 support for the Arduino print() function
  u8g2Display.setFont(u8g2_font_unifont_t_korean_jamo);  
  u8g2Display.setFontMode(BLACK);
  u8g2Display.setDrawColor(WHITE);
  u8g2Display.setFontDirection(0);

  u8g2Display.firstPage();
  u8g2Display.drawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); 
  u8g2Display.setCursor(PAGE_MARGIN, u8g2Display.getMaxCharHeight());

  Serial.println("Finished Display Setup");
  u8g2Display.print("Jamo Test: ");
  println(jamoTest);
  u8g2Display.print("Character Test: ");
  println(characterTest);
  
  u8g2Display.nextPage();
}

void println(String message) 
{
  Serial.println(message);
  u8g2Display.println(); 
  u8g2Display.println(message);

  u8g2_uint_t newY = u8g2Display.getCursorY() + u8g2Display.getMaxCharHeight();
  u8g2Display.setCursor(PAGE_MARGIN, newY);
}

void loop() {
  // put your main code here, to run repeatedly:

}
