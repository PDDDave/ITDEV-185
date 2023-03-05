#pragma once
#include <string>
using namespace std;

//Reel header file
class Reel
{
private:
	std::string selectedFace;
	std::string faces[20] = { "lemon", "cherry", "banana", "seven", "diamond", "bell", "heart", "star", "strawberry", "grape", "bell",
		"horeshoe", "heart", "pear", "orange", "10", "king", "queen", "jack", "joker" };
	int position = 0;

public:
	Reel(int);
	Reel();
	std::string getFace();
	int getPosition();
	void spin();
};

