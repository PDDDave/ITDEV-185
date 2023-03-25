/*
* David Charles
* ITDEV 185-900
* Assignment 8
*/

//This is the main class of Assignment 8

#include <iostream>
#include "LinkedList.h"
using namespace std;

//function prototypes
void printMenu();
void printList();
void displayDirectory();
void addEntry();

LinkedList contacts;

int main()
{
    int input;
    bool cont = true;

    
    do {
        system("cls");

        //if list is not empty, print list
        if (contacts.getHead() != nullptr) {
            printList();
        }

        printMenu();

        cin >> input;

        switch (input)
        {
        case 1:
            addEntry();
            break;
        case 2:
            displayDirectory();
            break;

        default:
            break;
        }
    } while (cont == true);
}

void addEntry() {
    PersonNode* newNode; 
    string fName;
    string lName;
    string address;
    string phone;

    //gather informaiton for new contact
    cout << "Enter first name: ";
    cin >> fName;
    cout << "Enter last name: ";
    cin >> lName;
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter phone number: ";
    cin >> phone;

    //set gathered values to newly created PersonNode
    /*
    newNode->setFName(fName);
    newNode->setLName(lName);
    newNode->setAddress(address);
    newNode->setPhone(phone); */

    newNode = new PersonNode(fName,lName,address,phone);

    //add new node to contact list
    contacts.addLink(newNode);

}

void printMenu() {
    string line = "****************************";
    
    cout << line << endl;
    cout << "(1) Add to directory" << endl;
    cout << "(2) Display Directory" << endl;
    //cout << "(3) Search for name" << endl;
    //cout << "(4) Remove from directory" << endl;
    cout << "(3) Exit" << endl;
    cout << line << endl;
}

void printList() {
    PersonNode* nodePtr = contacts.getHead(); 

    while (nodePtr) {
        cout << "First name:\t" << nodePtr->getFName() << endl;
        cout << "Last name:\t" << nodePtr->getLName() << endl;
        cout << "Address:\t" << nodePtr->getAddress() << endl;
        cout << "Phone num:\t" << nodePtr->getPhone() << endl;
        cout << endl << endl;
    }
}

void displayDirectory() {
    system("cls");

    printList();

    system("pause");
}

