#include "stdafx.h"
#include "Customer.h"

using namespace std;

Customer::Customer(int id, string firstName, string LastName)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
}

Customer::~Customer()
{
}

int Customer::getId() const
{
	return id;
}

string Customer::getLastName() const
{
	return lastName;
}

string Customer::getFirstName() const
{
	return firstName;
}

void Customer::setId(int id)
{
	this->id = id;
}

void Customer::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Customer::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Customer::printHistory()
{
	customerHistory.print();
}
