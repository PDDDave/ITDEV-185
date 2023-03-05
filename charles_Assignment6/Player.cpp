#include "Player.h"
#include<array>
#include <iostream>


//Play method rolls dice and sums the value of dice
void Player::play() {
	
	for (int a = 0; a < 20; a++) {
		
		Player::dice[a].roll();
		Player::sumOfDice += Player::getSingleDieValue(a);
	}
}

//sets the players number
void Player::setPlayerNumber(int pNum) {
	Player::playerNum = pNum;
}

//returns the number of dice the player has in thier die array
int Player::getNumberOfDice() {
	return sizeof(Player::dice);
}

//returns player number
int Player::getPlayerNumber() {
	return Player::playerNum;
}

//returns the value of the die at dice[pos]
int Player::getSingleDieValue(int pos) {
	return Player::dice[pos].getValue();
}

//accumulates the value of the dice using the above method
int Player::getSumOfDice() {
	sumOfDice = 0;
	for (int i = 0; i < 20; i++) {
		Player::sumOfDice += Player::getSingleDieValue(i);
	}

	return Player::sumOfDice;
}