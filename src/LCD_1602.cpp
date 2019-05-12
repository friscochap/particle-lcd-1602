/* LCD_1602 library by Starwave Software
 */
#include "LCD_1602.h"

const int CMD_DELAY = 50;
const int ENABLE_DELAY = 5;
const byte DISPLAY_ON = 0x0C;
const byte DISPLAY_OFF = 0x08;
const byte DISPLAY_CLEAR = 0x01;
const char *BLANK_LINE = "                                        ";
/**
 * Constructor.
 */
LCD_1602::LCD_1602(int rs, int e, int d4, int d5, int d6, int d7)
{
    m_RS = rs;
    m_E = e,
    m_D4 = d4;
    m_D5 = d5;
    m_D6 = d6;
    m_D7 = d7;
}

void LCD_1602::init()
{
    pinMode(m_RS, OUTPUT);
    pinMode(m_E, OUTPUT);
    pinMode(m_D4, OUTPUT);
    pinMode(m_D5, OUTPUT);
    pinMode(m_D6, OUTPUT);
    pinMode(m_D7, OUTPUT);

    write(0x33, LCD_CMD); // Set to 4-bit mode
    write(0x32, LCD_CMD); // Set to 4-bit mode

    write(0x06, LCD_CMD); // Cursor move direction
    write(0x0C, LCD_CMD); // Turn cursor off
    write(0x28, LCD_CMD); // 2 line display
    clear();
    delay(CMD_DELAY); //Delay to allow commands to process
}

void LCD_1602::turnOn()
{
    writeCommand(DisplayOn);
}
void LCD_1602::turnOff()
{
    writeCommand(DisplayOff);
}
void LCD_1602::clear()
{
    writeCommand(DisplayClear);
}

void LCD_1602::lineClear(byte line)
{
    writeLine(BLANK_LINE, line);
}

void LCD_1602::cursorShow(bool blinkCursor)
{
    byte cmdCode = (blinkCursor) ? 0x0F : 0x0E;

    write(cmdCode, LCD_CMD);
    delay(CMD_DELAY);
}

void LCD_1602::cursorHide()
{
    byte cmdCode = 0x0C;

    write(cmdCode, LCD_CMD);
    delay(CMD_DELAY);
}

void LCD_1602::cursorHome()
{
    writeCommand(CursorHome);
}

void LCD_1602::writeLine(const char *text, byte line)
{

    write(line, LCD_CMD);

    for (unsigned int i = 0; i < strlen(text); i++)
    {
        write(text[i], LCD_CHR);
    }

    delay(CMD_DELAY);
}

void LCD_1602::writeChar(char c)
{
    //write()
}

void LCD_1602::write(byte bits, byte mode)
{
    digitalWrite(m_RS, mode);

    digitalWrite(m_D4, (bits & 0x10));
    digitalWrite(m_D5, (bits & 0x20));
    digitalWrite(m_D6, (bits & 0x40));
    digitalWrite(m_D7, (bits & 0x80));

    toggle_enable();

    digitalWrite(m_D4, (bits & 0x01));
    digitalWrite(m_D5, (bits & 0x02));
    digitalWrite(m_D6, (bits & 0x04));
    digitalWrite(m_D7, (bits & 0x08));

    toggle_enable();
}

void LCD_1602::writeCommand(Command cmd)
{
    write(cmd, LCD_CMD);
    delay(CMD_DELAY);
}

void LCD_1602::toggle_enable()
{
    digitalWrite(m_E, HIGH);
    delay(ENABLE_DELAY);
    digitalWrite(m_E, LOW);
}
