#pragma once
#include <string>
class Coin
{
	private:
		std::string sideUp;
		bool heads;
		double value;
	public:
		Coin(double value);
		Coin(); //Default constructor, good practice per p.432
		bool getHeads();
		double getValue();
		std::string getSideUp();
		void toss();
};

