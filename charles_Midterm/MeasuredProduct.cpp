#include "MeasuredProduct.h"


//default constructor
MeasuredProduct::MeasuredProduct(std::string name, double price, int quantity, bool pickup) {
	//if order is not pickup set deliver fees
	if (!pickup) {
		delivery = 20.0;
		tip = 5.0;
	}

	this->name = name;
	this->price = price;
	this->quantity = quantity;
}

//This method calculates the price of the measured item.
void MeasuredProduct::calcPrice() {
	price = this->price * this->quantity;
}

void MeasuredProduct::setQuantity(int quantity) {
	this->quantity = quantity;
}

int MeasuredProduct::getQuantity() {
	return quantity;
}