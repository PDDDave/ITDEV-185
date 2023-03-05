#include "SlotMachine.h"
#include <iostream>
#include <iomanip>

//this function spins the reels and then outputs the faces to the console
bool SlotMachine::play() {
	bool win = false;

	SlotMachine::reels[0].spin();
	SlotMachine::reels[1].spin();
	SlotMachine::reels[2].spin();

	//formate and print output of each round of spinning
	cout << left << setw(20) << SlotMachine::reels[0].getFace() << left << setw(20) <<
	SlotMachine::reels[1].getFace() << " " << SlotMachine::reels[2].getFace() << "\n";

	//if all three faces match, return win
	if (reels[0].getFace() == reels[1].getFace() && reels[0].getFace() == reels[2].getFace()) {
		win = true;
	}
	
	return win;
}
