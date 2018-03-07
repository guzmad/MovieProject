#include "stdafx.h"
#include "Store.h"
#include "Customer.h"
#include <fstream>
#include <sstream>

Store::Store()
{

}

Store::~Store()
{
}


void Store::populateMovie(string fileName)
{





}

void Store::populateCustomer(string customerInfo)
{
	fstream infile(customerInfo);

	if (infile.fail())
	{
		cout << "No file found" << endl;
	}
	else
	{
		int Id;
		string lastName;
		string firstName;

		ifstream fin;
		fin.open(customerInfo);

		while (!fin.eof()) {
			fin >> Id;
			fin >> lastName;
			fin >> firstName;
			Customer * temp = new Customer(Id, firstName, lastName);
			overallCustomerList.addCustomer(temp);
		}
	}
}

void Store::populateCommandsFile(string fileName)
{	
	string p;
	fstream infile(fileName);

	while (getline(infile, p))
	{
		char command;
		int customerId;
		char mediaType;
		char movieType;
		stringstream firstline(p);
		firstline >> command >> customerId >> mediaType >> movieType;

		if (command == 'B' || command == 'R' || command == 'I' || command == 'H')
		{	
			if () 
			{
			
			}
		}
				
	}


}



void Store::commandHandler(char command)
{

}

void Store::printCustomerHistory(Customer * customer)
{
	customer->printHistory();
}

void Store::printInventory(MovieList * movieList)
{
	movieList->printByGenre('F');
	movieList->printByGenre('D');
	movieList->printByGenre('C');
}

void Store::borrowMovie(Customer * customer, MovieList * movieList, MovieInventory movieInventory)
{
	movieList->checkOut(movieInventory);
	customer->addHistory("B " + movieInventory.getMovie()->getMovieTitle());
}

void Store::returnMovie(Customer * customer, MovieList * movieList, MovieInventory movieInventory)
{
	movieList->checkIn(movieInventory);
	customer->addHistory("R " + movieInventory.getMovie()->getMovieTitle());
}
