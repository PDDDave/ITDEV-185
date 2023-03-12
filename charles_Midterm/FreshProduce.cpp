#include "FreshProduce.h"

//This is the implementation file for the FreshProduce derived class.

//Default constructor
FreshProduce::FreshProduce(std::string name, double price, double pounds, bool pickup) {
	//if order is not pickup set deliver fees
	if (!pickup) {
		delivery = 20.0;
		tip = 5.0;
	}
	//set other attributes
	this->name = name;
	this->price = price;
	this->pounds = pounds;
}

/*
* FreshProduce::calcPrice() calculates the price of the produce Item.
* The parameter price is fist set to the cost of one lb.
* The product of the price and ammount purchased in lbs is 
* calculated to be the final price when this method is called.
*/
void FreshProduce::calcPrice() {
	this->price = price * pounds;
}

//Mutator
void FreshProduce::setPounds(double pounds) {
	this->pounds = pounds;
}

//Accessor
double FreshProduce::getPounds() {
	return pounds;
}