#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // David Charles
    // ITDEV-185-900
    // Assignment #1

    double collected;
    double sales;
    double totalTax;
    double countyPaid;
    double statePaid;
    const double COUNTY_TAX = .02;
    const double STATE_TAX = .04;
    int year;
    string month;
    string line;

   
    //gather information
    line.assign(31, '*');
    cout << "Welcome to Sales Tax Calc.\n\n" << endl;
    cout << "Please enter the year: " << endl;
    cin >> year;
    cout << "Please enter the month: " << endl;
    cin >> month;
    cout << "Please enter the total amout collected: " << endl;
    cin >> collected;

    //calculations
    sales = collected / (1 + COUNTY_TAX + STATE_TAX);
    countyPaid = sales * COUNTY_TAX;
    statePaid = sales * STATE_TAX;
    totalTax = countyPaid + statePaid;

    

    //Format output

    cout << fixed << showpoint << setprecision(2);
    cout << "\nMonth: " + month +" " << year << endl;
    cout << line << endl;
    cout << left << setw(20) << "Total Collected: " << right << setw(10) << "$ " << collected << endl;
    cout << left << setw(20) << "Sales: " << right << setw(10) << "$ " << sales << endl;
    cout << left << setw(20) << "County Sales Tax: " << right << setw(10) << "$ " << countyPaid << endl;
    cout << left << setw(20) << "State Sales Tax: " << right << setw(10) << "$ " << statePaid << endl;
    cout << left << setw(20) << "Total Sales Tax: " << right << setw(10) << "$ " << totalTax << endl;

    return 0;
}


