#pragma once
#include "Die.h"

//Player header file
class Player
{
	private:
		Die dice[20];
		int playerNum = 0;
		int sumOfDice = 0;
	public:
		void play();
		void setPlayerNumber(int);
		int getNumberOfDice();
		int getPlayerNumber();
		int getSingleDieValue(int);
		int getSumOfDice();

};

