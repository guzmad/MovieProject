#include "stdafx.h"
#include "History.h"


History::History()
{
}

History::~History()
{
}

void History::add(string & customerData)
{
	movieHistory.push_back(customerData);
}

void History::print()
{
	if (movieHistory.empty()) {
		cout << "No History " << endl;
		return;
	}

	for (int i = 0; i < movieHistory.size() - 1; i++) {
		cout << (movieHistory[i]) << endl;
	}
}
