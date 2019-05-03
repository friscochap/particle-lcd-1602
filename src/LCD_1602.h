#pragma once
#include "Particle.h"

/* LCD_1602 library by Starwave Software
 */

// This will load the definition for common Particle variable types

const int LCD_RS = A0;
const int LCD_E = A1;
const byte LCD_CHR = HIGH;
const byte LCD_CMD = LOW;
const byte LCD_CHARS = 16;    // Characters per line (16 max)
const byte LCD_LINE_1 = 0x80; // LCD memory location for 1st line
const byte LCD_LINE_2 = 0xC0; // LCD memory location 2nd line

enum Command : byte {
    DisplayOn    = 0x0C,    
    DisplayOff   = 0x08,
    DisplayClear = 0x01,

    CursorHome   = 0x02
};

// This is your main class that users will import into their application
class LCD_1602
{
public:
  /**
   * Constructor
   */
  LCD_1602();

  void init();
  void init(bool mode8Bit);

  /**
   * Cursor Methods
   */
  void cursorShow(bool blinkCursor);
  void cursorHide();
  void cursorHome();

  void turnOff();
  void turnOn();
  /**
   * Output routines
   **/
  void writeChar(char c);
  void writeLine(const char *text, byte line);

  void clear();

private:
  void toggle_enable();
  void writeCommand(Command cmd);
  void write(byte bits, byte mode);

};
