#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include <stdbool.h>

// Register select (0 for instructions 1 for data)
#define RS 0b00000001
// Read-write bit
#define RW 0b00000010
// Start data read-write bit
#define E 0b00000100
// Backlight bit
#define BL 0b00001000

#define POWER_ON_DELAY 50 //milliseconds
#define INIT_DELAY1 5 //milliseconds
#define INIT_DELAY2 120 //microseconds
#define COMMAND_DELAY 40 //microseconds
#define HOME_CLEAR_DELAY 2 //milliseconds

#define INIT_BYTE 0b00000011

// See 44780 datasheet page 25-27 for symbol explanations
#define ENTRY_MODE 0b00000100
#define ID         0b00000010
#define S          0b00000001

#define DISPLAY_CONTROL 0b00001000
#define D               0b00000100
#define C               0b00000010
#define B               0b00000001

#define CURSOR_SHIFT 0b00010000
#define SC           0b00001000
#define RL           0b00000100

#define FUNCTION_SET 0b00100000
#define DL           0b00010000
#define N            0b00001000
#define F            0b00000100

#define SET_DDRAM_ADDR 0b10000000

#define CLEAR 0b00000001
#define HOME 0b00000010

#define BLANK_LINE "                "

void lcd_baseInit();
void _lcd_write(uint8_t command, uint8_t rs);
void lcd_writeCommand(uint8_t command);
void lcd_writeCharacter(uint8_t character);
void lcd_writeString(char string[]);
void lcd_setCursor(uint8_t x, uint8_t y);
void lcd_writeLines(char lineOne[], char lineTwo[], bool clear);

#endif // LCD_H
