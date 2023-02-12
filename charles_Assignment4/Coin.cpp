#include "Coin.h"
#include <time.h>
#include <windows.h>
/*
* This is the Implementation file of the Coin class
*/

/*The Coin constructor accepts the value of the coin as a double and
*assigns that value to the coin.  Then the toss method is called in
*order to set the inital side up.*/
Coin::Coin(double v) {
	value = v;
	Coin:: toss();
}

//Default constructor, good practice per p.432
Coin::Coin() {
}

/*The toss method generates a random number between 0-99 and tests
*if the number is even or odd.  If even sideUp is set to Heads, if
*odd the sideUp set to tails*/
void Coin::toss() {

	/*sleep for a moment during the coin toss, this increases the time
	*between the calls, increasing the desparity between random numbers.
	*i.e. better random spread (seems to work on my machine)*/
	Sleep(230);

	// Providing a seed value
	srand((unsigned) time(NULL));

	// Get a random number
	int random = rand() % 100;

	if (random % 2 == 0) {
		sideUp = "heads"; //positive test
	}
	else {
		sideUp = "tails"; //negative test
	}
}

/*The accessors for the Coin class */
std::string Coin::getSideUp() {
	return sideUp;
}
double Coin::getValue() {
	return value;
}
bool Coin::getHeads() {
	return heads;
}