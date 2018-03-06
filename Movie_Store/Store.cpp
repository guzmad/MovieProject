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
