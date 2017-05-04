#pragma once
#include <vector>
#include "VendingSlot.h"

using namespace std;


class VendingList
{

	
public:


	VendingList(vector<VendingSlot> &slots);
	~VendingList();

private:
	int seed;

	vector<int>itemListNumber;
	vector<int>randomList;
	vector<int>slotValue;
	vector<double> valueList;
	vector<string> nameList;
};

