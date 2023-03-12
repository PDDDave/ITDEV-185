#include "FreshProduce.h"

//Default constructor
FreshProduce::FreshProduce(std::string name, double price, double pounds, bool pickup) {
	//if order is not pickup set deliver fees
	if (!pickup) {
		delivery = 20.0;
		tip = 5.0;
	}

	this->name = name;
	this->price = price;
	this->pounds = pounds;
}

//This method calculates the price of the produce Item.
void FreshProduce::calcPrice() {
	this->price = price * pounds;
}

//Accessor and Mutator for private member variables
void FreshProduce::setPounds(double pounds) {
	this->pounds = pounds;
}

double FreshProduce::getPounds() {
	return pounds;
}