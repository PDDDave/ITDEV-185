#pragma once
#include "Reel.h"

//slot machin header file

class SlotMachine
{
	private:
		Reel reels[3];

	public:
		SlotMachine();
		void play();
};

