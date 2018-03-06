#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include "history.h"
#include "Movie.h"
#include "MovieInventory.h"
using namespace std;

class Customer
{
public:
	
	Customer(int id, string firstName, string LastName);
	~Customer();

	int getId() const;
	string getLastName() const;
	string getFirstName() const;
	void setId(int id);
	void setLastName(string lastName);
	void setFirstName(string firstName);
	void printHistory();

private:

	int id;
	string firstName;
	string lastName;
	History customerHistory;


};

#endif // !CUSTOMER_H

