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
	int element = id % 30;

		for (int j = 0; j < customerList[element].size(); j++) {
			if (customerList[element][j]->getId() == id)
				return customerList[element][j];
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
