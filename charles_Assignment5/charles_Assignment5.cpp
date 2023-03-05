#include "SlotMachine.h"
#include <windows.h>
#include <iostream>


/*
* David Charles
* ITDEV 185-900
* Assignment #5
*/

int main()
{
	bool win = false;
	int round = 0;
	//create slot machine
	SlotMachine slotMachine =  SlotMachine();

	//gameplay loop
	while (win == false) {
		round++;
		win = slotMachine.play(); //adjust win for loop testing
	}

	cout << "\n\nCongrats!  You've won!\nIt took you " << round << " tries to win!\n\n";

	return 0;
}


