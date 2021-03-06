#pragma once

#ifndef STORE_H
#define STORE_H

#include "CustomerList.h"
#include "MovieList.h"
#include "MovieFactory.h"

class Store
{

public:
	Store();
	~Store();

	void populateMovie(string fileName);
	void populateCustomer(string customerInfo);
	void populateCommandsFile(string fileName);
	void printCustomerHistory(Customer * customer);
	void printInventory(MovieList &movieList);
	void borrowMovie(Customer * customer, MovieInventory movieInventory);
	void returnMovie(Customer * customer, MovieInventory movieInventory);

private:

	CustomerList overallCustomerList;
	MovieList movieList;
};

#endif // !STORE_
