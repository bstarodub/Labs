#ifndef __GAME_H__
#define __GAME_H__

#include "Player.h"
#include "GameGraphics.h"

class Game
{
private:
	GameGraphics graphics;

public:
	void run();
};

#endif