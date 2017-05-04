#include "stdafx.h"
#include "VendingList.h"
#include "VendingSlot.h"
#include <vector>
#include <ctime>
#include <string>

using namespace std;


VendingList::VendingList(vector<VendingSlot> &slots)
{

	//seed srand
	srand(time(NULL));

	//starting lists
	itemListNumber = { 2,4,6,8,10,12,14,16,18,20,22,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40 };
	randomList = {};
	valueList = {};
	nameList = {"CHIP", "DORI", };
	slotValue = {};


	for (int x = 0; x < itemListNumber.size(); x++) {
		seed = (rand() % itemListNumber.size()) - 1;
		randomList.push_back(itemListNumber[seed]);
		itemListNumber.erase(itemListNumber.begin() + seed);
	};

	for (int x = 0; x < itemListNumber.size(); x++) {
		VendingSlot slot; //slot1, slot2, slot3 | slot3.slotnumber
		slot.ID = x;
		slot.slotNumber = randomList[x];
		for (int j = 0; j < itemListNumber.size(); j++) {
			if (slot.ID == j)
				slot.slotPrice = valueList[j];
		};
		for (int y = 0; y < itemListNumber.size(); y++) {
			if (slot.ID == y)
				slot.slotQuantity = 10;
		};
		for (int k = 0; k < itemListNumber.size(); k++) {
			if (slot.ID == k)
				slot.slotItem = nameList[k];
		};

		slots.push_back(slot);
	};
}


VendingList::~VendingList()
{
}
