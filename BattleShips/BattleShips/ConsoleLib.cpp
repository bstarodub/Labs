/*******************************/
/*                             */
/*       Console library       */
/*       Starodub Bogdan       */
/*                             */
/*******************************/

#include <iostream>
using namespace std;

//#include <windows.h>
#include "ConsoleLib.h"


// Console handles
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);


// Shoe/hide cursor
void showCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), visible };
	SetConsoleCursorInfo(hStdOut, &cci);
}

// Set symbols and background color
void setColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// Move cursor to specific position
void gotoXY(int x, int y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(hStdOut, coord);
}

// Show string in a specific position
void writeStr(int x, int y, const char *str)
{
	gotoXY(x, y);
    cout << str << flush;
}

// Show symbol in a specific position
void writeChar(int x, int y, char ch)
{
	gotoXY(x, y);
	cout << ch;
}

// Show certain amount of symbols in a specific position
void writeChars(int x, int y, char ch, unsigned len)
{
	gotoXY(x, y);
	for (unsigned i = 0; i < len; i++)
		cout << ch;
}

// Show certain amount of symbols in a specific position vertically
void writeCharsV(int x, int y, char ch, int len)
{
	for (int i = 0; i < len; i++)
	{
		gotoXY(x, y + i);
		cout << ch;
	}
}

// change text attributes from a specific position
void changeTextAttr(int x, int y, ConsoleColor text, ConsoleColor background, unsigned len)
{
	COORD coord = { x, y };
	DWORD dwDummy;
	FillConsoleOutputAttribute(hStdOut, (WORD)((background << 4) | text), len, coord, &dwDummy);
}
