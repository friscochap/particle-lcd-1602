// Example usage for LCD_1602 library by Starwave Software.

#include "../../src/LCD_1602.h"

// Initialize objects from the lib
LCD_1602 lCD_1602;

void setup() {
    // Call functions on initialized library objects that require hardware
    lCD_1602.init();
    lCD_1602.writeLine("Hello", LCD_LINE_1);
    lCD_1602.writeLine("World", LCD_LINE_2);
}

void loop() {
}
