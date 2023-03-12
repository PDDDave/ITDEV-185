#pragma once
#include <string>
/*
* This is the header file for the Item abstact class.
*/
class Item
{
	//protected variables, child items may access
	protected:  
		static double delivery;
		static double tip;
		double price;
		std::string name;
	public:
		Item();
		double getDelivery();
		std::string getName();
		double getPrice();
		double getTip();
		void setDelivery(double);
		void setName(std::string);
		void setPrice(double);
		void setTip(double);
};

