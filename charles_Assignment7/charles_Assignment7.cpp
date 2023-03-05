/*
* David Charles
* ITDEV 185-900
* Assignment #7
*/

#include <iostream>
#include <iomanip>
#include "Nickel.h"
#include "Quarter.h"
#include "Dime.h"
using namespace std;

void evaluateToss(Coin* coin) {
    string const HEADS = "heads";
    string const TAILS = "tails";

    //returns if pointer is null
    if (coin == nullptr) return;

    //else
    coin -> toss();
    cout << fixed << showpoint << setprecision(2);

    //access memberfunctions by pointer
    if (coin -> getSideUp() == HEADS) {
        
        cout << coin -> getType() << " landed on heads! Plus $ " << coin -> getValue() << "!" << endl;
        coin -> addBalance(coin -> getValue());
    }
    else {
        cout << coin-> getType() << " landed on tails!  No Score." << endl;
    }

    
}

int main()
{

    int round = 1;

    //create the three coins
    Quarter quarter;
    Dime dime;
    Nickel nickel;

    do {
        //round information
        system("cls");
        cout << "\t\t\tRound " << round << "\n" << endl;


        //send the address of each coin to the evaluate toss method.
        evaluateToss(&quarter);
        evaluateToss(&dime);
        evaluateToss(&nickel);

        cout << endl << "Your balance is: $" << quarter.getBalance() << endl;
        system("pause");

        round++;

    } while (quarter.getBalance() < 1.00);  //check if static variable balance is over $1

    //using different coins to get the balance to demonstrate the behavior of the static variable balance.

    if (nickel.getBalance() == 1.00) {
        cout << "Congratulations!  You have won!  Your balance is exactly: " << dime.getBalance() << endl;
        system("pause");
    }
    else {
        cout << "\n\nOh no, you went bust! Your balance is: $" << quarter.getBalance() << endl;
        system("pause");
    }
}