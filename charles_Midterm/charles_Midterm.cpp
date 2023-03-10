/*
* David Charles
* ITDEV 185-900
* MidTerm
*/

//This is the main class of the Midterm application

#include <iostream>
#include <iomanip>
#include <vector>
#include "Item.h"
#include "FreshProduce.h"
#include "MeasuredProduct.h"
using namespace std;

//function prototypes
void menu1();		// first menu
bool menu2();   // second menu

//sub menus
void freshProduce();  
void meatSeafood();
void frozenFoods();

//global variables
string line = "*********************************";
string directions = "Enter one of the corresponding options below:\n";
bool pickup = false;  //if false, delivery
vector<Item*> cart;  //vector array of Item pointers



//functions
int main()
{
	bool cont = true;
	//launches first menu
	menu1();

	//loops through the next set of menus until checkout
	do { cont = menu2(); } while (cont);

	cout << "Thank you for shopping!" << endl;
	exit(0);
	
}

void menu1() {
	
	string response = "";
	
	do{
		//clear screen and print menu
		system("cls");
		cout << directions << endl;
		cout << line << endl;
		cout << "(1) Pickup" << endl;
		cout << "(2) Delivery \n\n" << endl;

		cout << "(5) Exit" << endl;
		cout << line << endl;

		cin >> response;
		
	} while (response != "1" && response != "2" && response != "5");  //loops until input is acceptable


	if (response == "1") {
		pickup = true;
		menu2();
	}
	else if (response == "2") {
		pickup = false;
		menu2();
	}
	else {
		cout << "Thank you for shopping!" << endl;
		exit(0);
	}
}

bool menu2() {
	std::string response = "";
	bool cont = true;

	do {
		//clear screen and print menu
		system("cls");
		cout << directions << endl;
		cout << line << endl;
		cout << "(1) Fresh Produce" << endl;
		cout << "(2) Meat and Seafood" << endl;
		cout << "(3) Frozen Foods" << endl;
		cout << "(4) Check Out" << endl;
		cout << line << endl;

		cin >> response;

	} while (response != "1" && response != "2" && response != "3" && response != "4");  //loops until input is acceptable

	if (response == "1") {
		freshProduce();
	}
	else if (response == "2") {
		meatSeafood();
	}
	else if (response == "3") {
		frozenFoods();
	}
	else {
		double total = 0.0;

		//if checkout is reached without items being added to the cart
		if (cart.empty()) {
			cout << "Sorry you didn't find what you're looking for.  Come back again!" << endl;
			exit(0);
		}
		//checkout
		system("cls");
		
		//print reciept
		cout << fixed << showpoint << setprecision(2);
		cout << "\t\tReciept" << endl;
		cout << line << endl;
		cout << left << setw(20) << "Item Name" << left << setw(30) << "Item Total" << endl;
		cout << line << endl;

		//process each item in cart
		for (int i = 0; i < cart.size(); i++) {
			cout << left << setw(20) << cart[i]->getName() << right << setw(5) << "$" << right << setw(6)<< cart[i]->getPrice() << endl;

			//add cost of item to toal
			total += cart[i]->getPrice();
		}

		if (cart.front()->getDelivery() > 0) { //if the fee was set to be higher than 0 (!pickup in constructor)
			cout << "\n" << endl;
			cout << right << setw(20) <<"TIP: $" << right << setw(5) << cart.front()->getTip() << endl;
			cout << right << setw(20) <<"DELIVERY: $" << right << setw(5) << cart.front()->getDelivery() << endl;

			//add tip and delivery fee to total
			total += cart.front()->getTip();
			total += cart.front()->getDelivery();
		}

		cout << line << endl;
		cout << right << setw(25) << "Total: $" << right << total << endl;

		cout << line << endl;
		cout << line << endl;

		cont = false;
	}

	return cont;
}

void frozenFoods() {
	std::string response = "";
	double quantity = 0.0;


	do {
		//clear screen and print menu
		system("cls");
		cout << directions << endl;
		cout << line << endl;
		cout << "(1) Waffles $6.99" << endl;
		cout << "(2) Pizza $4.99" << endl;
		cout << "(3) Popsicles $2.99" << endl;
		cout << "(4) Return to main menu" << endl;
		cout << line << endl;

		cin >> response;

	} while (response != "1" && response != "2" && response != "3" && response != "4");  

	cout << "How many would you like?" << endl;
	cin >> quantity;

	if (response == "1") {
		//create pointer object and assign memory then push pointer to end of cart vector
		MeasuredProduct* p = NULL;
		p = new MeasuredProduct("Waffles", 6.99, quantity, pickup);
		p->calcPrice();//update price from per pound to total price
		cart.push_back(p);

	}
	else if (response == "2") {

		MeasuredProduct* p = NULL;
		p = new MeasuredProduct("Pizza", 4.99, quantity, pickup);
		p->calcPrice();
		cart.push_back(p);
	}
	else if (response == "3") {
		MeasuredProduct* p = NULL;
		p = new MeasuredProduct("Popsicles", 2.99, quantity, pickup);
		p->calcPrice();
		cart.push_back(p);
	}
	else {
		return;
	}
}

void meatSeafood() {
	std::string response = "";
	double pounds = 0.0;


	do {
		//clear screen and print menu
		system("cls");
		cout << directions << endl;
		cout << line << endl;
		cout << "(1) Whole chicken $6.99/lb" << endl;
		cout << "(2) Ground beef $4.99/lb" << endl;
		cout << "(3) Salmon $9.99/lb" << endl;
		cout << "(4) Return to main menu" << endl;
		cout << line << endl;

		cin >> response;

	} while (response != "1" && response != "2" && response != "3" && response != "4");  //loops until input is acceptable

	cout << "How many pounds would you like?" << endl;
	cin >> pounds;

	if (response == "1") {

		//create pointer object and assign memory then push pointer to end of cart vector
		FreshProduce* p = NULL;
		p = new FreshProduce("Whole chicken", 6.99, pounds, pickup);
		p->calcPrice();  //update price from per pound to total price
		cart.push_back(p);
	}
	else if (response == "2") {
		FreshProduce* p = NULL;
		p = new FreshProduce("Ground beef", 4.99, pounds, pickup);
		p->calcPrice();
		cart.push_back(p);
	}
	else if (response == "3") {
		FreshProduce* p = NULL;
		p = new FreshProduce("Salmon", 9.99, pounds, pickup);
		p->calcPrice();
		cart.push_back(p);
	}
	else {
		//returns to previous menu (menu2)
		return;
	}
}

void freshProduce() {
	std::string response = "";
	double pounds = 0.0;


	do {
		//clear screen and print menu
		system("cls");
		cout << directions << endl;
		cout << line << endl;
		cout << "(1) Gala apples $3.99/lb" << endl;
		cout << "(2) Banana $0.48/lb" << endl;
		cout << "(3) Grapes $2.99/lb" << endl;
		cout << "(4) Return to main menu" << endl;
		cout << line << endl;

		cin >> response;

	} while (response != "1" && response != "2" && response != "3" && response != "4");

	cout << "How many pounds would you like?" << endl;
	cin >> pounds;

	if (response == "1") {
		//create pointer object and assign memory then push pointer to end of cart vector
		FreshProduce* p = NULL;
		p = new FreshProduce("Galla Apples", 3.99, pounds, pickup);
		p->calcPrice(); //update price from per pound to total price
		cart.push_back(p);
	}
	else if (response == "2") {
		FreshProduce* p = NULL;
		p = new FreshProduce("Banana", 0.48, pounds, pickup);
		p->calcPrice();
		cart.push_back(p);
	}
	else if (response == "3") {
		FreshProduce* p = NULL;
		p = new FreshProduce("Grapes", 2.99, pounds, pickup);
		p->calcPrice(); 
		cart.push_back(p);
	}
	else {
		//returns to previous menu (menu2)
		return;
	}
}




