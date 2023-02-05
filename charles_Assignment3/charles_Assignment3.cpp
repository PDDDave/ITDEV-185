/*
* David Charles
* ITDEV 185-900
* Assignment #3
*/

#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
void gatherInfo();
void calculateCosts(int, int, double);
void shippingReport(int, int, int, int, double, double, double);
bool again();

//Constants
const int SPOOL_PRICE = 100;
const int SHIPPING_PRICE = 10;

//The main function is the primary process loop for the application
int main()
{
	bool cont = true;
		
	do
	{
		gatherInfo();
		cont = again();

	} while (cont);

}

//This function gathers input from user
void gatherInfo() {
	int inventory = 0;
	int ordered = 0;
	double shipMod = 0;

	cout << "Wholesale Copper Shipment\n\n";

	cout << " \nPlease enter the number of spools on hand: ";
	cin >> inventory;

	cout << " \n\nHow many spools have been ordered: ";
	cin >> ordered;

	cout << " \n\n Standard shipping rate is $10/spool.\nAdd any additional shipping costs (per spool): ";
	cin >> shipMod;

	calculateCosts(inventory, ordered, shipMod);

}

//all calculations done in this fucntion.
void calculateCosts(int inv, int ord, double shipMod = 10) {
	int backOrder = 0;
	int currentShipment = 0;
	double spoolCharge = 0;
	double shipCharge = 0;
	double totalCharge = 0;

	//calculate spoolCharge
	spoolCharge = ord * SPOOL_PRICE;

	//calculate shipCharge
	shipCharge = ord * SHIPPING_PRICE;

	//add shipping modifier to total shipping price
	shipCharge = shipCharge += (ord * shipMod);

	//calculate total
	totalCharge = spoolCharge + shipCharge;

	//caluclate backorder and current shipment
	backOrder = inv - ord;

	if (backOrder < 0) {
		backOrder = abs(backOrder);
		
		currentShipment = inv;
	}
	else {
		currentShipment = backOrder;
		backOrder = 0;
	}
	
	//calculate currentshipment
	

	shippingReport(inv, ord, backOrder, currentShipment, spoolCharge, shipCharge, totalCharge);
}

//This function takes the calculated totals and formats the output to console
void shippingReport(int inv, int ord, int backOrder, int currentShipment, double spoolCharge, double shipCharge, double totalCharge) {
	system("cls");  //clear console to make display cleaner

	cout << fixed << showpoint << setprecision(2);
	cout << "       ***ORDER SUMMARY***\n" << endl;
	cout << left << setw(25) << "Spools ordered:" << right << setw(10) << ord << endl;
	cout << left << setw(25) << "Spools in this shipment:" << right << setw(10) << currentShipment << endl;
	if (backOrder > 0) {
		cout << left << setw(25) << "Spools back ordered:" << right << setw(10) << backOrder << endl;
	}
	cout << "\n\n      Charges for this shipment   " << endl;
	cout << "   -------------------------------" << endl;
	cout << left << setw(25) << "Spool charges:" << right << setw(10) << "$" << spoolCharge << endl;
	cout << left << setw(25) << "Shipping charges:" << right << setw(10) << "$" << shipCharge << endl;
	cout << left << setw(25) << "Total charges:" << right << setw(10) << "$" << totalCharge << endl;

}

//This function updates the continueation flag from the main method.
bool again() {
	bool choice = false;
	string input;

	cout << "\n\nWould you like to Process another order?    Y || N\n\n";
	cin >> input;

	if (input._Equal("y") || input._Equal("Y")) {
		choice = true;
	}

	system("cls");
	return choice;
}

