#include "stdafx.h"
#include "Store.h"


Store::Store()
{

}

Store::~Store()
{
}

void Store::readFile(string fileName)
{
	ifstream fin;
	int count = 0;
	fin.open(filename);
	int numEdges;
	string start;
	string end;
	int weight;

	fin >> numEdges;

	while (count < numEdges) {
		fin >> start;
		fin >> end;
		fin >> weight;

		add(start, end, weight);
		count++;
	}


}

void Store::populateMovie(string fileName)
{

}

void Store::populateCustomer(string customerInfo)
{
}

void Store::commandHandler(char command)
{
}

void Store::printCustomerHistory(Customer * customer)
{
}

void Store::printInventory(MovieList * movieList)
{
}

void Store::borrowMovie(Customer * customer)
{
}

void Store::returnMovie(Customer * customer)
{
}
