/* LCD_1602 library by Starwave Software
 */
#include "LCD_1602.h"

#define DISPLAY_ON      0x0C
#define DISPLAY_OFF     0x08
#define DISPLAY_CLEAR   0x01
/**
 * Constructor.
 */
LCD_1602::LCD_1602()
{
    // be sure not to call anything that requires hardware be initialized here, put those in begin()
}

void LCD_1602::init()
{
    init(false);
}

void LCD_1602::init(bool mode8Bit)
{
    if (false == mode8Bit)
    {
        write(0x33, LCD_CMD); // Set to 4-bit mode
        write(0x32, LCD_CMD); // Set to 4-bit mode
    }

    write(0x06, LCD_CMD); // Cursor move direction
    write(0x0C, LCD_CMD); // Turn cursor off
    write(0x28, LCD_CMD); // 2 line display
    clear();
    delay(50);                //Delay to allow commands to process
}

void LCD_1602::turnOn()
{
    write(DISPLAY_ON, LCD_CMD); 
    delay(50);


}
void LCD_1602::turnOff()
{
    write(DISPLAY_OFF, LCD_CMD); // Clear display
    delay(50);

}
void LCD_1602::clear() 
{
    write(DISPLAY_CLEAR, LCD_CMD); // Clear display
    delay(50);
}

void LCD_1602::showCursor(bool blinkCursor)
{
    byte cmdCode = (blinkCursor) ? 0x0F : 0x0E;

    write(cmdCode, LCD_CMD); 
    delay(50);

}

void LCD_1602::hideCursor()
{
    byte cmdCode = 0x0C;

    write(cmdCode, LCD_CMD); 
    delay(50);

}

void LCD_1602::write(byte bits, byte mode)
{
    digitalWrite(LCD_RS, mode);

    digitalWrite(D4, (bits & 0x10));
    digitalWrite(D5, (bits & 0x20));
    digitalWrite(D6, (bits & 0x40));
    digitalWrite(D7, (bits & 0x80));

    toggle_enable();

    digitalWrite(D4, (bits & 0x01));
    digitalWrite(D5, (bits & 0x02));
    digitalWrite(D6, (bits & 0x04));
    digitalWrite(D7, (bits & 0x08));

    toggle_enable();
}

void LCD_1602::toggle_enable()
{
    digitalWrite(LCD_E, HIGH);
    delay(5);
    digitalWrite(LCD_E, LOW);
}

void LCD_1602::writeLine(const char *text, byte line)
{

    write(line, LCD_CMD);

    for (unsigned int i = 0; i < strlen(text); i++)
    {
        write(text[i], LCD_CHR);
    }

    delay(50);
}
