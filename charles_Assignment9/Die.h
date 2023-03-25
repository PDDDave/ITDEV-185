#pragma once
#include <string>
class Die
{

	/*This is the header for the Die abstract class*/

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
		virtual std::string roll() = 0;  //virtual method, will be overwritten in derrived class (pure virtual function)
		virtual std::string getFaces() = 0; //virtual method, will be overwritten in derrived class (pure virtual function)
};

