

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

//declare the ug82 object specific to the screen we use
U8G2_LS027B7DH01_M0_400X240_F_4W_HW_SPI u8g2(U8G2_R2, /* cs=*/ SHARP_SS, /* dc=*/ U8X8_PIN_NONE); //works but the colors are inverted
//u8g2_uint_t cursorY = 0;

String jamoTest = "ㄴ";
String characterTest = "녕";

void setup() {
  while(!Serial){}//wait for the serial to be open
  u8g2.begin();
  u8g2.enableUTF8Print();    // enable UTF8 support for the Arduino print() function
  u8g2.setFont(unifont_jamo_compatibility);  
  u8g2.setFontMode(BLACK);
  u8g2.setDrawColor(WHITE);
  u8g2.setFontDirection(0);

  u8g2.firstPage();
  u8g2.drawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); 
  u8g2.setCursor(PAGE_MARGIN, u8g2.getMaxCharHeight());
  Serial.println("Finished Display Setup");

  //draws the jamo's glyph (lower-level proof)
  u8g2.print("Glyph Test: ");
  int x = 40;
  int y = 10; 
  int glyph = 0x3130; //compatibiliyt chars are: 3130—318F
  for(int index = 0; index <16; index++){
    for(int insideIndex = 0; insideIndex <6; insideIndex++){
      u8g2.drawGlyph(y,x, glyph); //comes from where?
      x+=12;
      glyph++;
    }
    y+=20;
    x=40;
  }
  
  
 
  u8g2.nextPage();
}

void doubleprint(String message) 
{
  //Serial.println(message);
  u8g2.println(); 
  u8g2.println(message);

  u8g2_uint_t newY = u8g2.getCursorY() + u8g2.getMaxCharHeight();
  u8g2.setCursor(PAGE_MARGIN, newY);

}

void loop() {
  // put your main code here, to run repeatedly:
}
