#include "Reel.h"
#include <random>
#include <iostream>


//Reel implementation file


//constuctor accepts the position of the reel
Reel::Reel(int pos) {
	position = pos;
}

Reel::Reel() {

}

//The spin method generates a random number using the <random> library
void Reel::spin() {
	std::random_device rd;  //random engine device
	std::uniform_int_distribution<int> dist(0, 19); //rang of values to be sleected 0-19 reflecting the subscript of the faces array.

	//the random generator is passed into the distribution object, and the value (0-19) becomes the subscript of the faces array.
	selectedFace = faces[dist(rd)];
}


//accessors for the Reel class
std::string Reel::getFace() {
	return selectedFace;
}

int Reel::getPosition() {
	return position;
}