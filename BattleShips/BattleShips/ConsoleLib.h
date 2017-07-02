/*******************************/
/*                             */
/*       Console library       */
/*       Starodub Bogdan       */
/*                             */
/*******************************/

#ifndef __CONSOLELIB_H__
#define __CONSOLELIB_H__

#include <windows.h>

// Console handles
extern HANDLE hStdOut;
extern HANDLE hStdIn;

// Colors
enum ConsoleColor
{
	BLACK         = 0,
	BLUE          = 1,
	GREEN         = 2,
	CYAN          = 3,
	RED           = 4,
	MAGENTA       = 5,
	BROWN         = 6,
	LIGHTGRAY     = 7,
	DARKGRAY      = 8,
	LIGHTBLUE     = 9,
	LIGHTGREEN    = 10,
	LIGHTCYAN     = 11,
	LIGHTRED      = 12,
	LIGHTMAGENTA  = 13,
	YELLOW        = 14,
	WHITE         = 15
};

//Frame symbols
enum FrameType
{
	SINGLE_VERTICAL		 = 179,
	SINGLE_RIGHT_MIDDLE	 = 180,
	SINGLE_RIGHT_TOP	 = 191,
	SINGLE_LEFT_BOTTOM	 = 192,
	SINGLE_MIDDLE_BOTTOM = 193,
	SINGLE_MIDDLE_TOP	 = 194,
	SINGLE_LEFT_MIDDLE	 = 195,
	SINGLE_HORIZONTAL	 = 196,
	SINGLE_INTERSECTION	 = 197,
	SINGLE_RIGHT_BOTTOM	 = 217,
	SINGLE_LEFT_TOP		 = 218,

	DOUBLE_RIGHT_MIDDLE	 = 185,
	DOUBLE_VERTICAL		 = 186,
	DOUBLE_RIGHT_TOP	 = 187,
	DOUBLE_RIGHT_BOTTOM  = 188,
	DOUBLE_LEFT_BOTTOM	 = 200,
	DOUBLE_LEFT_TOP		 = 201,
	DOUBLE_MIDDLE_BOTTOM = 202,
	DOUBLE_MIDDLE_TOP	 = 203,
	DOUBLE_LEFT_MIDDLE	 = 204,
	DOUBLE_HORIZONTAL	 = 205,
	DOUBLE_INTESXECTION  = 206
};

// Shoe/hide cursor
void showCursor(bool visible);

// Set symbols and background color
void setColor(ConsoleColor text, ConsoleColor background);

// Move cursor to specific position
void gotoXY(int x, int y);

// Show string in a specific position
void writeStr(int x, int y, const char *str);

// Show symbol in a specific position
void writeChar(int x, int y, char ch);

// Show certain amount of symbols in a specific position
void writeChars(int x, int y, char ch, unsigned len);

// Show certain amount of symbols in a specific position vertically
void writeCharsV(int x, int y, char ch, int len);

// Change text attributes from a specific position
void changeTextAttr(int x, int y, ConsoleColor text, ConsoleColor background, unsigned len);

#endif // __CONSOLELIB_H__
