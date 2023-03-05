/*
* David Charles
* ITDEV 185-900
* Assignment #6
*/

#include <iostream>
#include "Player.h"
#include <array>
using namespace std;


//displays all players sums to the screen
void displayAllPlayersSums(Player players[]) {
	int line = 0;

	for(int i = 0; i < 100; i++){

		cout << players[i].getPlayerNumber() + 1 <<": " << "\t" << players[i].getSumOfDice() << "\t";
		line++;

				if (line > 4) {  //advances to next line after 5 player sums print
			cout << endl;
			line = 0;
		}
		
	}

	cout << endl;
	cout << endl;
}

void displayWinner(Player* ptr) {
	int line = 0;

	cout << "The winning player is player " << (ptr->getPlayerNumber()) +1 << ".  Winning ammount: " << ptr -> getSumOfDice() << endl;
	cout << endl;
	cout << endl;

	for (int i = 0; i < ptr -> getNumberOfDice(); i++) {

		cout << "dice " << (i + 1) << ":\t" << ptr -> getSingleDieValue(i) << "\t";
		line++;

		if (line > 4) {  //advances to next line after 5 player sums print
			cout << endl;
			line = 0;
		}
	}
}

Player* findWinner(Player players[]) {
	Player* ptr = &players[0]; //pointer variable, points to a Player, initialized with first array value
	Player highScore = players[0];  //variable to hold player with highest score, initialized with first array value

	for (int i = 1; i < 100; i++) { //starts at sub1 since sub0 is already in the highScore variable
		if ( players[i].getSumOfDice() > highScore.getSumOfDice() ) {
			//if the sum of the dice is higher than the previously sotred sum, they pointer and highscore holder are
			//updated to new values.
			highScore = players[i];
			ptr = &players[i];
		}
	}

	return ptr;  //returns Player pointer with highest sum player

}

//loops through the players array, assigning player numbers based on position in the array.
void initPlayers(Player players[]) {


	for (int i = 0; i < 100; i++) {
		players[i].setPlayerNumber(i);
		players[i].play();
	}

}

int main()
{
	Player players[100];
	initPlayers(players);
	displayAllPlayersSums(players);
	displayWinner(findWinner(players));

	return 0;
}

