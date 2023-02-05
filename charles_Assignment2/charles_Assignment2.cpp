/*
* David Charles
* ITDEV 185-900
* Assignment #2
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//they getType function is used to gather input from the user and rout them to where they want to go
int getType() {
    string input;
    int result = 0;

    do
    {
        cout << "Enter 1 for Manual entry.\nEnter 2 to read from file.\nEnter 99 to quit.\n\n";
        cin >> input;

        if (input._Equal("1"))
        {
            result = 1;
        }
        else if (input._Equal("2"))
        {
            result = 2;
        }
        else if (input._Equal("99"))
        {
            result = 99;
        }
        else {
            cout << "\n\nInvalid entry. Try again\n\n";
        }

    } while (result != 1 && result != 2 && result != 99);


    system("cls");
    return result;
}

//print names is a simple method used to print the first and last student
void printNames(string highName, string lowName) {
    cout << "\n\nThe student first in Line is: " << highName << ".\n";
    cout << "The student last in Line is: " << lowName << ".\n";
}

//this function loops thorugh the number of students entered by the user.
void loopSort(int numStudents) {
    int remainStudents = numStudents;
    string tempName;
    string currentName;
    string highName = "M"; //M and N chosen as the middle of the alphabet
    string lowName = "N";  

    if (numStudents > 1) {
        while (remainStudents > 0) {
            cout << "Entries left: " << remainStudents << "\n";
            cout << "Student Name: ";
            cin >> currentName;
            cout << "\n";

            currentName[0] = toupper(currentName[0]); //use uppercase to ensure ASCII values are in the correct range

           //use the values of the strings in order to compare them to one another.  Normally I would use an array and then sort, but I realized I wasnt
           //sure how to do this without using a list of some sort, so I gave it a go.

            //structure similar other sorts
            if (currentName <= highName) {
                tempName = highName;
                highName = currentName;


                if (tempName >= lowName) {
                    lowName = tempName;
                }

            }
            else if (currentName >= lowName) {
                lowName = currentName;
            }

            remainStudents--;

        }

        printNames(highName, lowName);
    }
    else {
        //skip all of the above statments if only one student.
        cout << "Entries left: " << remainStudents << "\n";
        cout << "Student Name: ";
        cin >> currentName;
        currentName[0] = toupper(currentName[0]); //use uppercase for equal comparison
        printNames(currentName, currentName);
    }

    
}

void manualEntry() {
    string input;
    int numStudents;
    bool cont = true;

    do
    {
       cout << "How many students? (Enter whole number between 1-20)\n";
       cin >> input;

       numStudents = stoi(input);  //convert string to int

       if (numStudents > 0 && numStudents < 21)
       {
           cont = false;
       }
       else {
           cout << "Invalid entry. Number out of range: must be within 1-20.\n\n";
       }


    } while (cont);

    system("cls");  //clear console to make display cleaner

    loopSort(numStudents);
}

void fileRead() {
    ifstream inputFile;
    string name;
    string highName = "M"; 
    string lowName = "N";
    string tempName;

    inputFile.open("20names.txt");  //there is a 5, 10, and 20names.txt file available for testing

    if (inputFile) {
        while (inputFile >> name) {
            cout << name << endl;

            name[0] = toupper(name[0]); 


            //This is the same as the above sort statment, just modified to work with a txt file.  It would be better to remove this code and place it inside
            //of its own funciton, as it is written twice and doing pretty much the same thing.
            if (name <= highName) {
                tempName = highName;
                highName = name;


                if (tempName >= lowName) {
                    lowName = tempName;
                }

            }
            else if (name >= lowName) {
                lowName = name;
            }
        }

        printNames(highName, lowName);
    }
    else {
        cout << "***File Read error***";
    }

}

//function used to update the sentinel value of the primary loop in main.
bool again() {
    bool choice = false;
    string input;

    cout << "\n\nWould you like to run another batch of Students?    Y || N\n\n";
    cin >> input;

    if (input._Equal("y") || input._Equal("Y")) {
        choice = true;
    }
    
    system("cls");
    return choice;
}


//primary switch and navigation
int main()
{
    bool cont = true;
    int runType;

    cout << "Welcome to Student Lister!\n\n";

	do {
        runType = getType();

        switch (runType)
        {
        case 1:
            cout << "Manual Entry\n\n";
            manualEntry();
            cont = again();
            break;
        case 2:
            fileRead();
            cont = again();
            break;
        case 99:
            cont = false;
            break;
        default:
            cout << "Unknown Error. Exiting...";
            cont = again();
            break;
        }
    } while (cont);

    cout << "\n\nThank you for using Student Lister!";

}




