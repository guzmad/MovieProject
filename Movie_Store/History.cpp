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
	for (int i = 0; i < movieHistory.size() - 1; i++) {
		cout << (movieHistory[i]) << endl;
	}
}
