#include <conio.h>
#include "GameGraphics.h"
#include "ConsoleLib.h"


GameGraphics::GameGraphics()
{
	/*HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = {DEF_CONSOLE_WIDTH, DEF_CONSOLE_HEIGHT};

	SetConsoleScreenBufferSize(hWnd, bufferSize);
	MoveWindow(hWnd, 100, 50, DEF_CONSOLE_WIDTH, DEF_CONSOLE_HEIGHT, FALSE);*/
	system("mode 100, 60");
}

void GameGraphics::drawGamefieldInfo()
{
	setColor(WHITE, BLACK);
	writeChar(DEF_USER_X_POS, DEF_PLAYERS_INFO_Y_POS, SINGLE_LEFT_TOP);
	writeChars(DEF_USER_X_POS + SINGLE_OFFSET, DEF_PLAYERS_INFO_Y_POS, SINGLE_HORIZONTAL, DEF_PLAYERS_INFO_WIDHT);
	writeChar(DEF_USER_X_POS + DEF_PLAYERS_INFO_WIDHT, DEF_PLAYERS_INFO_Y_POS, SINGLE_RIGHT_TOP);

	writeChar(DEF_USER_X_POS, DEF_PLAYERS_INFO_Y_POS + DEF_PLAYERS_INFO_HEIGHT, SINGLE_LEFT_BOTTOM);
	writeChars(DEF_USER_X_POS + SINGLE_OFFSET, DEF_PLAYERS_INFO_Y_POS + DEF_PLAYERS_INFO_HEIGHT, SINGLE_HORIZONTAL, DEF_PLAYERS_INFO_WIDHT);
	writeChar(DEF_USER_X_POS + DEF_PLAYERS_INFO_WIDHT, DEF_PLAYERS_INFO_Y_POS + DEF_PLAYERS_INFO_HEIGHT, SINGLE_RIGHT_BOTTOM);

	for (int y = SINGLE_OFFSET; y < DEF_PLAYERS_INFO_HEIGHT; y++)
	{
		for (int x = SINGLE_OFFSET; x < DEF_PLAYERS_INFO_WIDHT; x++)
		{
			writeChar(DEF_USER_X_POS + x, DEF_PLAYERS_INFO_Y_POS + y, ' ');
		}
	}

	writeCharsV(DEF_USER_X_POS, DEF_PLAYERS_INFO_Y_POS + SINGLE_OFFSET, SINGLE_VERTICAL, DEF_PLAYERS_INFO_HEIGHT - SINGLE_OFFSET);
	writeCharsV(DEF_USER_X_POS + DEF_SHIPS_INFO_WIDHT, DEF_PLAYERS_INFO_Y_POS + SINGLE_OFFSET, SINGLE_VERTICAL, DEF_PLAYERS_INFO_HEIGHT - SINGLE_OFFSET);
	writeCharsV(DEF_USER_X_POS + DEF_PLAYERS_INFO_WIDHT, DEF_PLAYERS_INFO_Y_POS + SINGLE_OFFSET, SINGLE_VERTICAL, DEF_PLAYERS_INFO_HEIGHT - SINGLE_OFFSET);
	writeCharsV(DEF_USER_X_POS + DEF_PLAYERS_INFO_WIDHT - DEF_SHIPS_INFO_WIDHT, DEF_PLAYERS_INFO_Y_POS + SINGLE_OFFSET, SINGLE_VERTICAL, DEF_PLAYERS_INFO_HEIGHT - SINGLE_OFFSET);

}

void GameGraphics::drawTitle()
{
	int i = ZERO;

	setColor(WHITE, BLACK);
	writeStr(DEF_TITLE_X_POS, DEF_TITLE_Y_POS + i++, "____________________________________________________________________________________________");
	writeStr(DEF_TITLE_X_POS, DEF_TITLE_Y_POS + i++, "                                                                                            ");
	writeStr(DEF_TITLE_X_POS, DEF_TITLE_Y_POS + i++, "  *****   ******  *******  *******  *       ******    ******  *    *    *   ******  ******  ");
	writeStr(DEF_TITLE_X_POS, DEF_TITLE_Y_POS + i++, "  *    *  *    *     *        *     *       *         *       *    *    *   *    *  *       ");
	writeStr(DEF_TITLE_X_POS, DEF_TITLE_Y_POS + i++, "  *****   ******     *        *     *       ******    ******  ******    *   ******  ******  ");
	writeStr(DEF_TITLE_X_POS, DEF_TITLE_Y_POS + i++, "  *    *  *    *     *        *     *       *              *  *    *    *   *            *  ");
	writeStr(DEF_TITLE_X_POS, DEF_TITLE_Y_POS + i++, "  *****   *    *     *        *     ******  ******    ******  *    *    *   *       ******  ");
	writeStr(DEF_TITLE_X_POS, DEF_TITLE_Y_POS + i++, "                                                                                            ");
	writeStr(DEF_TITLE_X_POS, DEF_TITLE_Y_POS + i  , "____________________________________________________________________________________________");
}

void GameGraphics::drawBackground()
{
	setColor(BLUE, BLACK);

	for (int y = ZERO; y < DEF_CONSOLE_HEIGHT; y++)
	{
		for (int x = ZERO; x < DEF_CONSOLE_WIDTH; x++)
		{
			writeChar(x, y, ',');
		}
	}
}

void GameGraphics::drawGamefield()
{
	//User gamefield frame

	for (int y = ZERO; y <= (DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_Y_COEF); y++)
	{
		for (int x = ZERO; x <= (DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_X_COEF); x++)
		{
			//Game field cells
			if ((y % DEF_GAMEFIELD_Y_COEF != 0) && (x % DEF_GAMEFIELD_X_COEF != 0))
			{
				writeChar(DEF_USER_X_POS + x, DEF_GAMEFIELD_Y_POS + y, ' ');
				writeChar(DEF_ENEMY_X_POS + x, DEF_GAMEFIELD_Y_POS + y, ' ');
			}
			else if (y == 0 && (x % DEF_GAMEFIELD_X_COEF == 0))
			{
				writeChar(DEF_USER_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_MIDDLE_TOP);
				writeChar(DEF_ENEMY_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_MIDDLE_TOP);
			}
			else if ((y % DEF_GAMEFIELD_Y_COEF == 0) && x == 0)
			{
				writeChar(DEF_USER_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_LEFT_MIDDLE);
				writeChar(DEF_ENEMY_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_LEFT_MIDDLE);
			}
			else if ((y == DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_Y_COEF) && (x % DEF_GAMEFIELD_X_COEF == 0))
			{
				writeChar(DEF_USER_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_MIDDLE_BOTTOM);
				writeChar(DEF_ENEMY_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_MIDDLE_BOTTOM);
			}
			else if ((y % DEF_GAMEFIELD_Y_COEF == 0) && (x == DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_X_COEF))
			{
				writeChar(DEF_USER_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_RIGHT_MIDDLE);
				writeChar(DEF_ENEMY_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_RIGHT_MIDDLE);
			}
			else if ((y % DEF_GAMEFIELD_Y_COEF == 0) && (x % DEF_GAMEFIELD_X_COEF != 0))
			{
				writeChar(DEF_USER_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_HORIZONTAL);
				writeChar(DEF_ENEMY_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_HORIZONTAL);
			}
			else if ((y % DEF_GAMEFIELD_Y_COEF != 0) && (x % DEF_GAMEFIELD_X_COEF == 0))
			{

				writeChar(DEF_USER_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_VERTICAL);
				writeChar(DEF_ENEMY_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_VERTICAL);
			}
			else if ((y % DEF_GAMEFIELD_Y_COEF == 0) && (x % DEF_GAMEFIELD_X_COEF == 0))
			{
				writeChar(DEF_USER_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_INTERSECTION);
				writeChar(DEF_ENEMY_X_POS + x, DEF_GAMEFIELD_Y_POS + y, SINGLE_INTERSECTION);
			}
		}
	}
	//User corners
	writeChar(DEF_USER_X_POS, DEF_GAMEFIELD_Y_POS, SINGLE_LEFT_TOP);
	writeChar(DEF_USER_X_POS + DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_X_COEF, DEF_GAMEFIELD_Y_POS, SINGLE_RIGHT_TOP);
	writeChar(DEF_USER_X_POS, DEF_GAMEFIELD_Y_POS + DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_Y_COEF, SINGLE_LEFT_BOTTOM);
	writeChar(DEF_USER_X_POS + DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_X_COEF, DEF_GAMEFIELD_Y_POS + DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_Y_COEF, SINGLE_RIGHT_BOTTOM);
	//Enemy corners
	writeChar(DEF_ENEMY_X_POS, DEF_GAMEFIELD_Y_POS, SINGLE_LEFT_TOP);
	writeChar(DEF_ENEMY_X_POS + DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_X_COEF, DEF_GAMEFIELD_Y_POS, SINGLE_RIGHT_TOP);
	writeChar(DEF_ENEMY_X_POS, DEF_GAMEFIELD_Y_POS + DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_Y_COEF, SINGLE_LEFT_BOTTOM);
	writeChar(DEF_ENEMY_X_POS + DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_X_COEF, DEF_GAMEFIELD_Y_POS + DEF_GAMEFIELD_SIZE * DEF_GAMEFIELD_Y_COEF, SINGLE_RIGHT_BOTTOM);
}

void GameGraphics::gameRendering()
{
	drawBackground();
	drawTitle();
	drawGamefield();
	drawGamefieldInfo();
}
