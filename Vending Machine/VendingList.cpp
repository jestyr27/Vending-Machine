#include "stdafx.h"
#include "VendingList.h"
#include "VendingSlot.h"
#include <vector>
#include <ctime>
#include <string>

using namespace std;


VendingList::VendingList()
{


	srand(time(NULL));
	itemListNumber = { 2,4,6,8,10,12,14,16,18,20,22,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40 };
	randomList = {};
	valueList = {};
	nameList = {};

	vector<VendingSlot> slots;


	for (int x = 0; x < 27; x++) {
		seed = (rand() % itemListNumber.size()) - 1;
		randomList.push_back(itemListNumber[seed]);
		itemListNumber.erase(itemListNumber.begin() + seed);
	};

	for (int x = 0; x < 27; x++) {
		VendingSlot slot; //slot1, slot2, slot3 | slot3.slotnumber
		slot.ID = x;
		slot.slotNumber = randomList[x];
		for (int j = 0; j < 27; j++) {
			if (slot.ID == j)
				slot.slotPrice = valueList[j];
		};
		for (int y = 0; y < 27; y++) {
			if (slot.ID == y)
				slot.slotQuantity = 10;
		};
		for (int k = 0; k < 27; k++) {
			if (slot.ID == k)
				slot.slotItem = nameList[k];
		};

		slots.push_back(slot);
	};
}


VendingList::~VendingList()
{
}
