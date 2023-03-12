#include "MeasuredProduct.h"

//This is the implementation file for the MeasuredProduct derived class.

//default constructor
MeasuredProduct::MeasuredProduct(std::string name, double price, int quantity, bool pickup) {
	//if order is not pickup set delivery fees
	if (!pickup) {
		delivery = 20.0;
		tip = 5.0;
	}

	//set other variables
	this->name = name;
	this->price = price;
	this->quantity = quantity;
}

/*
* MeasuredProduct::calcPrice() calculates the price of the measured Item.
* The parameter price is fist set to the cost of one unit.
* The product of the price and units purchased is
* calculated to be the final price when this method is called.
*/
void MeasuredProduct::calcPrice() {
	price = this->price * this->quantity;
}

//Mutator
void MeasuredProduct::setQuantity(int quantity) {
	this->quantity = quantity;
}

//Accessor
int MeasuredProduct::getQuantity() {
	return quantity;
}