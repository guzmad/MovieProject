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
	void commandHandler(char command);
	void printCustomerHistory(Customer * customer);
	void printInventory(MovieList * movieList);
	void borrowMovie(Customer * customer, MovieList * movieList, MovieInventory movieInventory);
	void returnMovie(Customer * customer, MovieList * movieList, MovieInventory movieInventory);

private:

	CustomerList customerList;
	MovieList movieList;
};

#endif // !STORE_
