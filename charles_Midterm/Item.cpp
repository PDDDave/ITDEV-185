#include "Item.h"

/*
* This is the implementation file for the item base  class.
*/

//Default constructor
Item::Item() {
	delivery = 0;
	tip = 0;
	name = "";
	price = 0.00;
}

//declare static variables outside of class definition, but inside of namespace.
double Item::delivery = 0;
double Item::tip = 0;


//Mutators
void Item::setDelivery(double delivery) {
	this->delivery = delivery;
}

void Item::setName(std:: string name) {
	this->name = name;
}

void Item::setPrice(double price) {
	this->price = price;
}

void Item::setTip(double tip) {
	this->tip = tip;
}

//Accessors
double Item::getDelivery() {
	return delivery;
}

 std::string Item::getName() {
	return name;
}

 double Item::getPrice() {
	 return price;
 }

 double Item::getTip() {
	 return tip;
 }