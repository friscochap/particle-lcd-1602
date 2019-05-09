// Example usage for LCD_1602 library by Starwave Software.

#include "../../src/LCD_1602.h"

// Initialize objects from the lib
LCD_1602 lCD_1602;

void setup() {
  pinMode(LCD_RS, OUTPUT);
  pinMode(LCD_E, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  lCD_1602.init(false);

  lCD_1602.writeLine("Library 0.0.3",LCD_LINE_1);
  lCD_1602.writeLine("Initialized",LCD_LINE_2);

  delay(3000);

  lCD_1602.writeLine("Clearing        ",LCD_LINE_1);
  lCD_1602.writeLine("Display         ",LCD_LINE_2);

  delay(3000);
  lCD_1602.clear();

  delay(1000);

  lCD_1602.writeLine("Showing",LCD_LINE_1);
  lCD_1602.writeLine("Cursor",LCD_LINE_2);

  delay(3000);

  lCD_1602.cursorShow(false);

  delay(3000);
  lCD_1602.clear();

  delay(3000);

  lCD_1602.writeLine("Blinking",LCD_LINE_1);
  lCD_1602.writeLine("Cursor",LCD_LINE_2);

  delay(3000);
  lCD_1602.cursorShow(true);

  delay(3000);

  lCD_1602.clear();

  lCD_1602.writeLine("Cursor",LCD_LINE_1);
  lCD_1602.writeLine("Home",LCD_LINE_2);

  lCD_1602.cursorHome();

  delay(3000);

  lCD_1602.clear();
  lCD_1602.writeLine("Hiding",LCD_LINE_1);
  lCD_1602.writeLine("Cursor",LCD_LINE_2);

  lCD_1602.cursorHide();

  delay(3000);
  
  lCD_1602.clear();
  lCD_1602.writeLine("Turning Off",LCD_LINE_1);
  lCD_1602.writeLine("Display",LCD_LINE_2);

  delay(3000);

  lCD_1602.turnOff();

  delay(3000);
  lCD_1602.clear();
  
  lCD_1602.writeLine("Display",LCD_LINE_1);
  lCD_1602.writeLine("Turned On",LCD_LINE_2);

  delay(3000);

  lCD_1602.turnOn();

  delay(3000);
  lCD_1602.clear();
  
  lCD_1602.writeLine("Clear",LCD_LINE_1);
  lCD_1602.writeLine("Line",LCD_LINE_2);

  delay(3000);

  lCD_1602.lineClear(LCD_LINE_1);

  delay(2000);

  lCD_1602.lineClear(LCD_LINE_2);

  delay(2000);

  lCD_1602.clear();

  lCD_1602.writeLine("Demo",LCD_LINE_1);
  lCD_1602.writeLine("Complete",LCD_LINE_2);
}

void loop() {
}
