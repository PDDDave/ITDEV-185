#include "Die.h"
#include <random>

//Die implementation file

Die::Die() {
	Die::roll();
}

void Die::roll(){
	std::random_device rd;  //random engine device
	std::uniform_int_distribution<int> dist(1, 6); // range of 6 numbers that correlate to faces on a d6

	Die::dieValue = dist(rd);  //sets dieValue to rolled face.
}

int Die::getValue() {
	return Die::dieValue;
}
