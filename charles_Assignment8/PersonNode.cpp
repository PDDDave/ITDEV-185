#include "PersonNode.h"

/*
* This is the implementation file for the PersonNode class.
*/


//constructors
	
PersonNode::PersonNode() {
	PersonNode::next = NULL;
}
	
PersonNode::PersonNode(string fName,string lName, string address, string phone) {
	this->fName = fName;
	this->lName = lName;
	this->address = address;
	this->phone = phone;

	PersonNode::next = NULL;
}


//Accessors

string PersonNode::getFName() {
	return fName;
}

string PersonNode::getLName() {
	return lName;
}

string PersonNode::getAddress() {
	return address;
}

string PersonNode::getPhone() {
	return phone;
}

string PersonNode::getFullName() {
	string fullName = fName + " " + lName;

	return fullName;
}

PersonNode* PersonNode::getNext() {
	return next;
}

//Mutators
void PersonNode::setNext(PersonNode* nextNode) {
	next = &nextNode;
}

void PersonNode::setFName(string fName) {
	this->fName = fName;
}

void PersonNode::setLName(string lName) {
	this->lName = lName;
}

void PersonNode::setAddress(string address) {
	this->address = address;
}

void PersonNode::setPhone(string phone) {
	this->phone = phone;
}