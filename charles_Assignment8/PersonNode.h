#pragma once
#include <string>
using namespace std;

/*
* This is the header LinkedList Class
*/

class PersonNode
{
	//private member variables
	private:
		std::string fName;
		std::string lName;
		std::string address;
		std::string phone;
		
		PersonNode *next;


	// function deffinitions
	public:

		//constructors
		PersonNode();
		PersonNode(string fName,string lName, string address, string phone);

		//accessors
		string getFName();
		string getLName();
		string getAddress();
		string getPhone();
		string getFullName();
		PersonNode* getNext();
		
		//mutators
		void setFName(string);
		void setLName(string);
		void setAddress(string);
		void setPhone(string);
		void setNext(PersonNode*);

		
};






