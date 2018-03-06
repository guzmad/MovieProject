#pragma once

#ifndef STORE_H
#define STORE_H

#include "CustomerList.h"
#include "MovieList.h"

class Store
{

public:
	Store();
	~Store();

	void populateMovie(string fileName);
	void populateCustomer(string customerInfo);
	void commandHandler(char command);
	void printCustomerHistory(Customer * customer);
	void printInventory(MovieList * movieList);
	void borrowMovie(Customer * customer);
	void returnMovie(Customer * customer);

private:

	CustomerList customerList;
	MovieList movieList;
};

#endif // !STORE_
