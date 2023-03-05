#include "Coin.h"
#include <random>

/*
* This is the Implementation file of the Coin class
*/

/*The Coin constructor accepts the value of the coin as a double and
*assigns that value to the coin.  Then the toss method is called in
*order to set the inital side up.*/

Coin::Coin(double v, std::string type) {
	value = v;
	this -> type = type;  
}

Coin::Coin(double v) {
	value = v;
	type = "";
	Coin::toss();
}

double Coin::balance = 0;  //declare static variable outside ofclass definition, but inside of namespace.

//Default constructor, good practice per p.432
Coin::Coin() {
}

/*The toss method generates a random number between 0-99 and tests
*if the number is even or odd.  If even sideUp is set to Heads, if
*odd the sideUp set to tails*/
void Coin::toss() {

	std::random_device rd;  //random engine device
	std::uniform_int_distribution<int> dist(1, 100); //range of values to be sleected 1-100.

	int random = dist(rd);  //generate random number

	if (random % 2 == 0) {
		sideUp = "heads"; //positive test
	}
	else {
		sideUp = "tails"; //negative test
	}
}

//adds passed double value to the static value of blanace
void Coin::addBalance(double value) {
	balance += value;
}

//void method returns tha value of static balance
double Coin::getBalance() {
	return balance;
}



/*The accessors for the Coin class */

std::string Coin::getType() {
	return type;
}
std::string Coin::getSideUp() {
	return sideUp;
}
double Coin::getValue() {
	return value;
}
bool Coin::getHeads() {
	return heads;
}