#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player
{
private:
	bool mPlayerField[10][10];
	bool mEnemyField[10][10];

	
public:
	virtual void move()		= 0;
	virtual void setShips() = 0;
};

#endif