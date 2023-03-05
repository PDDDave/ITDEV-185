#pragma once
#include "Reel.h"

//slot machine header file

class SlotMachine
{
private: Reel reels[3] = {Reel(1), Reel(2), Reel(3)};
	public: bool play();
};

