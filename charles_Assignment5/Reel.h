#pragma once
#include <string>
using namespace std;

/*Header file for the Reel Class*/
class Reel
{
	private: 
		std::string selectedFace;
		std::string faces[20] = {"lemon", "cherry", "banana", "seven", "diamond", "bell", "heart", "star", "strawberry", "grape", "bell",
			"horeshoe", "heart", "pear", "orange", "10", "king", "queen", "jack", "joker"};
		int position;

	public:
		Reel();
		std::string getFace();
		int getPosition();
		void spin();
};

