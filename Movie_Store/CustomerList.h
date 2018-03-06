#include "stdafx.h"
#include "Customer.h"
#include <vector>

#pragma once
class CustomerList
{
public:
	CustomerList();
	void addCustomer(Customer * customer);
	Customer * getCustomer(int id);
	int hashFunction(int id);
	~CustomerList();

private:
	vector<Customer *> customerList[30];
};

