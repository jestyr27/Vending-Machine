#pragma once
#ifndef VENDINGSLOT_H
#define VENDINGSLOT_H
#include <string>

using namespace std;

class VendingSlot
{

public:
	VendingSlot();

	int ID;
	int slotNumber;
	double slotPrice;
	int slotQuantity;
	string slotItem;
};

#endif