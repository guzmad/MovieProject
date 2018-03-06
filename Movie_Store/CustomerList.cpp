#include "stdafx.h"
#include "CustomerList.h"
#include <algorithm>


CustomerList::CustomerList()
{
	for (int i = 0; i < 30; i++) {
		customerList[i].push_back(nullptr);
	}
}

void CustomerList::addCustomer(Customer * customer)
{
	customerList[hashFunction(customer->getId())].push_back(customer);
}

Customer * CustomerList::getCustomer(int id)
{
	
}

int CustomerList::hashFunction(int id)
{
	int element = id % 30;
	
	return element;
}


CustomerList::~CustomerList()
{
}
