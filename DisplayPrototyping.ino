
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <Adafruit_GFX.h>    // Core graphics library
#include "src/DisplayPrototyping.h""

// TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3    // Chip Select goes to Analog 3
#define LCD_CD A2    // Command/Data goes to Analog 2
#define LCD_WR A1    // LCD Write goes to Analog 1
#define LCD_RD A0    // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

// Using two fonts since numbers are nice when bold
// #define LABEL1_FONT &FreeSansOblique12pt7b // Key label font 1
// #define LABEL2_FONT &FreeSansBold12pt7b    // Key label font 2


serialDisplay sDisplay(&tft);

//------------------------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);

  tft.begin();
  tft.setRotation(0);

  // tft.setFreeFont(LABEL2_FONT);

  //Buffer Limit from the Serial Monitor is 64 bytes
  sDisplay.runCommands(F("x;ts2;sc10,10;#17e0;thDisplay Prototyping;"));
  sDisplay.runCommands(F("sc10,30;ts1;thLibrary v1.0;"));
  sDisplay.runCommands(F("sc10,10;tvVertical Center;sc10,80;ttNormal text;"));
  sDisplay.runCommands(F("#f804;ch20,60,10;#ffe0;cf50,60,10;"));
  sDisplay.runCommands(F("#05ff;gh70,50,90,60,70,70;#ffff;gf100,50,120,60,100,70;"));
  sDisplay.runCommands(F("#fc7c;rh130,50,20,20;#263c;rf160,50,20,20;#efe0;ri10,100,40,40,10;"));
  sDisplay.runCommands(F("#f9e0;rj60,100,40,40,13;#1f9d;lv2,45,280;#07ff;lh2,170,240;"));
  sDisplay.runCommands(F("#ded8;dl2,170,240,320;"));
  // // Clear the screen
  // tft.fillScreen(TFT_BLACK);

  // // Draw keypad background
  // tft.fillRect(0, 0, 240, 320, TFT_DARKGREY);

  // // Draw number display area and frame
  // tft.fillRect(DISP_X, DISP_Y, DISP_W, DISP_H, TFT_BLACK);
  // tft.drawRect(DISP_X, DISP_Y, DISP_W, DISP_H, TFT_WHITE);

  // // Draw keypad
  // drawKeypad();
}

void loop(void) {

  sDisplay.readCommandsFromSerial();
}