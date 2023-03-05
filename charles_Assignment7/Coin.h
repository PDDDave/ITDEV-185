#pragma once
#include <string>

class Coin
{
protected:  //access modifier changed to protected so that subclasses may access
	std::string type; //added type to get name of coin for output
	std::string sideUp;
	bool heads;
	static double balance;  //static double to hold balance during game
	double value;
public:
	Coin(double value, std::string type);
	Coin(double value);
	Coin(); //Default constructor, good practice per p.432
	bool getHeads();
	static double getBalance();
	double getValue();
	std::string getType();
	std::string getSideUp();
	void toss();
	void addBalance(double);
};