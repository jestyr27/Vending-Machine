// Vending Machine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "VendingSlot.h"
#include "VendingList.h"
#include <string>
using namespace std;

//constants
const int MAX_COLUMNS = 8;
const int MAX_ROWS = 5;
const int MAX_SLOTS = MAX_ROWS * MAX_COLUMNS;

//strings
string input;

//ints
int slotToGet;

//objects
VendingSlot slot[MAX_SLOTS];

//booleans
bool buying = true;

//prototypes
int calcIndex();
void getInput();
int calcChange();
void slotsOutput(vector<VendingSlot>&varry);

//food symbols
char one = int(185);

int _tmain(int argc, _TCHAR* argv[])
{
	//create vending slots
	//vector<VendingSlot> slots = VendingList slotCreate;


	//output slot info
	slotsOutput(slots);

	//Fill each slot with an item
	while (buying == true){
		getInput();
		slotToGet = calcIndex();
		cout << "\nInput: " << input << "\nSlot Number: " << slotToGet;
	}

	return 0;
}

//calculates and outputs user change
int calcChange() {

	//enter variables
	double moneySpent = 0.0;
	double moneyIn = 0.0;
	double change = 0.0;
	int changeINT = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;

	//enter input
	cout << "Enter money owed: $";
	cin >> moneySpent;
	cout << "Enter money paid: $";
	cin >> moneyIn;
	cout << endl;

	//calculation
	if (moneySpent > moneyIn){
		cout << "The amount that was given is not enough, please pay the full amount.";
		cout << endl;
		cout << endl;
	}
	else{
		cout << fixed << setprecision(2);

		change = moneyIn - moneySpent;
		cout << change << endl;
		changeINT = ceil(change * 100);
		cout << changeINT << endl;
		quarters = (changeINT / 25);

		changeINT -= quarters * 25;
		cout << changeINT << endl;
		dimes = changeINT / 10;

		changeINT -= dimes * 10;
		cout << changeINT << endl;
		nickels = changeINT / 05;

		changeINT -= nickels * 05;

		pennies = changeINT;

		//display

		cout << "Change due: $" << change << endl;
		cout << "Quarters: " << quarters << endl;
		cout << "Dimes: " << dimes << endl;
		cout << "Nickles: " << nickels << endl;
		cout << "Pennies: " << pennies << endl;
		cout << endl;
		cout << endl;
	}

	system("pause");

	return 0;
};

//takes user input and converts into array position
int calcIndex() {
	int left = input[0];
	int right = input[1];
	left -= 48;
	right -= 48;

	return(((left - 1) * MAX_COLUMNS + right - 1));


};

//gets user input
void getInput() {
	int left;
	int right;
	bool good = false;

	while (good == false) {
		cout << "\nWhich item would you like?";
		cin >> input;

		if (input.length() == 2) {
			left = input[0];
			right = input[1];
			left -= 48;
			right -= 48;

			if (left > 0 && left <= MAX_ROWS) {

				if (right > 0 && right <= MAX_COLUMNS) {

					good = true;
				}
			}
		}
	}
}

	void slotsOutput(vector<VendingSlot>&varry) {
		/*int ID;
		int slotNumber;
		double slotPrice;
		int slotQuantity;
		string slotItem;*/

		for (int x = 0; x < varry.size(); x++) {
			cout << varry[x].ID << endl;
			cout << varry[x].slotNumber << endl;
			cout << varry[x].slotPrice << endl;
			cout << varry[x].slotQuantity << endl;
			cout << varry[x].slotItem << endl;
		}
	}





