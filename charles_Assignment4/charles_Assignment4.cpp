// charles_Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Coin.h"
using namespace std;

int main()
{
    string const HEADS = "heads";
    string const TAILS = "tails";
    double balance = 0;
    int round = 1;

    //create the three coins
    Coin quarter(.25);
    Coin dime(.10);
    Coin nickel(.05);

    do {
        //round information
        system("cls");
        cout << "\t\t\tRound " << round << "\n" << endl;
              

        //toss coins
        quarter.toss();
        dime.toss();
        nickel.toss();

        //get and accumulate values

        //quarter
        cout << fixed << showpoint << setprecision(2);
        if (quarter.getSideUp() == HEADS) {
            cout << "Quarter landed on heads! Plus $0.25!\n";
            balance += 0.25;
        }
        else {
            cout << "Quarter landed on tails!  No Score.\n";
        }

        //dime
        if (dime.getSideUp() == HEADS) {
            cout << "Dime landed on heads! Plus $0.10!\n";
            balance += 0.10;
        }
        else {
            cout << "Dime landed on tails!  No Score.\n";
        }

        //nickel
        if (nickel.getSideUp() == HEADS) {
            cout << "Nickel landed on heads! Plus $0.05!\n";
            balance += 0.05;
        }
        else {
            cout << "Nickel landed on tails!  No Score.\n";
        }

        cout << "\n\nCurrent balance: $" << balance << endl;
        cout << "Press enter to continue...";
        cin.ignore();
        round++;
    } while (balance < 1.00);

    if (balance == 1.00) {
        cout << "Congratulations!  You have won!  Your balance is exactly: " << balance << endl;
    }
    else {
        cout << "\n\nOh no, you went bust! Your balance is: $" << balance << endl;
    }





}

