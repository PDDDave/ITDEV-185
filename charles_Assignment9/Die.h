#pragma once
#include <string>
class Die
{

	/*This is the header for the Die base class*/

	//protected member variables, child classes may access
	protected: 
		std::string name;
		int sides;

	//public member functions
	public:
		Die();
		Die(std::string, int);
		std::string getName();
		int getSides();
		void setName(std::string);
		void setSides(int);
		virtual std::string roll();  //virtual method, will be overwritten in derrived class
		virtual std::string getFaces(); //virtual method, will be overwritten in derrived class
};

