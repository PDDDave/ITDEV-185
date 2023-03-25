/*
* David Charles
* ITDEV 185-900
* Assignment 8
*/

#include <iostream>
#include<iomanip>
#include "Die.h"
#include "SpecialDie.h"
using namespace std;

//Dice objects

//numbered Dice
Die* die1 = new Die;
Die* die2 = new Die;
Die* die3 = new Die;
Die* die4 = new Die;
Die* die5 = new Die;
Die* die6 = new Die;
Die* die7 = new Die;

//dice with special symbols
Die* special1 = new SpecialDie;
Die* special2 = new SpecialDie;
Die* special3 = new SpecialDie;
Die* special4 = new SpecialDie;
Die* special5 = new SpecialDie;
Die* special6 = new SpecialDie;

//function prototypes
void initDice();
void playGame();
void nextRoll(Die*,Die*);
bool again();

/*The main method of the application, contains the gameplay loop*/
int main()
{	
	bool cont = true;
	initDice();

	do {

		playGame();
		cont = again();
		system("cls");

	} while (cont);
	
	return 0;  //application exits
}

/*The again function prompts the user if they would like to run through the program again, if the user does not elect to exit the main loop continues*/
bool again() {
	std::string response = "99";
	bool cont = true;

	cout << "Thanks for playing! \nWould you like to roll again? Y||N\n\n" << endl;
	cin >> response;

	if (response == "N" || response == "n") {
		cont = false;
	}

	return cont;
	
}
/*The playGame function starts with some specialized text to get things started.  After the first die, the next few calls are the same
/*so the nextRoll function is used to reduce code duplication*/
void playGame() {

	//the getFaces method is virtual function that is overridden by the derrived class: SpecialDie
	cout << "Possible faces for numbered dice: " << die1->getFaces() << endl;
	cout << "Possible faces for special dice: " << special1->getFaces() << endl;
	system("pause");
	cout << "\n\n" << endl;

	cout << "First up the " << die1->getName() << " die rolled: " << die1->roll() << endl;
	cout << "Followed by the " << special1->getName() << " die rolled: " << special1->roll() << endl;

	system("pause");
	cout << "\n\n" << endl;

	nextRoll(die2, special2);
	nextRoll(die3, special3);
	nextRoll(die4, special4);
	nextRoll(die5, special5);
	nextRoll(die6, special6);

}

/*The NextRoll function simply displays and calls the roll function for each die that is passed to it.  Polymorphism allows me to use the same method
even name in the function call, even though the two roll functions are different*/
void nextRoll(Die* normal, Die* special) {
	cout << "Next the " << normal->getName() << " die rolled: " << normal->roll() << endl;
	cout << "Followed by the " << special->getName() << " die rolled: " << special->roll()<< endl;

	system("pause");
	cout << "\n\n" << endl;
}


/*The initDice function sets the starting values to the dice objects.*/
void initDice() {
	//set D20s
	die1->setName("D20");
	die1->setSides(20);
	special1->setName("Special D20");
	special1->setSides(20);

	//set D12s
	die2->setName("D12");
	die2->setSides(12);
	special2->setName("Special D12");
	special2->setSides(12);

	//set D10s
	die3->setName("D10");
	die3->setSides(10);
	special3->setName("Special D10");
	special3->setSides(10);

	//set D8s
	die4->setName("D8");
	die4->setSides(8);
	special4->setName("Special D8");
	special4->setSides(8);

	//set D6s
	die5->setName("D6");
	die5->setSides(6);
	special5->setName("Special D6");
	special5->setSides(6);

	//set D4s
	die6->setName("D4");
	die6->setSides(4);
	special6->setName("Special D4");
	special6->setSides(4);
}


