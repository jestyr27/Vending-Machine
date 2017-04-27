#pragma once
#include <vector>

using namespace std;


class VendingList
{

	
public:


	VendingList();
	~VendingList();

private:
	int seed;

	vector<int>itemListNumber;
	vector<int>randomList;
	vector<double> valueList;
	vector<string> nameList;
};

