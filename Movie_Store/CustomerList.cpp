#include "stdafx.h"
#include "CustomerList.h"


CustomerList::CustomerList()
{

}

void CustomerList::addCustomer(Customer * customer)
{
	customerList[hashFunction(customer->getId())].push_back(customer);
}

Customer * CustomerList::getCustomer(int id)
{
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < customerList[i].size(); i++) {
			if (customerList[i][j]->getId() == id)
				return customerList[i][j];
		}
	}

	cout << "Customer not found! " << endl;
	return nullptr;
}

int CustomerList::hashFunction(int id)
{
	int element = id % 30;
	
	return element;
}


CustomerList::~CustomerList()
{
}
