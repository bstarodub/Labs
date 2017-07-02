#ifndef __GAMEGRAPHOCS_H__
#define __GAMEGRAPHICS_H__


#include <Windows.h>
#include "GameConfig.h"
#include "ConsoleLib.h"
using namespace GameValues;

class GameGraphics
{
private:
	//HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD bufferSize;
	
public:
	GameGraphics();

	void drawGamefieldInfo();
	void drawBackground();
	void drawTitle();
	void drawGamefield();
	void gameRendering();

};

#endif
