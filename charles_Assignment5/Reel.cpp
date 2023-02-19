#include "Reel.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iostream>


//Reel implementation file


//default constructor
Reel::Reel() {

}

void Reel::spin() {
	unsigned seed = time(0);
	srand(seed);

	cout << rand() << " ";
}


//accessors for the Reel class
std::string Reel::getFace() {
	return selectedFace;
}

int Reel::getPosition() {
	return position;
}
