#include "Die.h"
#include <random>

/*This is the implementation file for the Die Abstract class*/

//Constructors
Die::Die() {
	name = "";
	sides = 0;
}

Die::Die(std::string name, int sides) {
	this->name = name;
	this->sides = sides;
}

//Accessors
std::string Die::getName() {
	return name;
}

int Die::getSides() {
	return sides;
}


//Mutators
void Die::setName(std::string name) {
	this->name = name;
}

void Die::setSides(int sides) {
	this->sides = sides;
}