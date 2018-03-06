#include "stdafx.h"
#include "Store.h"
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
		string s; // This string contains the first line in the file

		if (infile.good())  // it reads the first line of the file containing the 
		{
			getline(infile, s);
		}

		int customerId;
		string lastName;
		string firstName;

		stringstream firstline(s);
		firstline >> customerId>>lastName>>firstName;
		
		cout << customerId <<" "<<lastName<<" " <<firstName<< endl;


		//string p;



		//while (getline(infile, p))
		//{
		//	insertMazeValues(p, height, width, maze);
		//}


		//if (!found)
		//{
		//	cout << "No exit - Sartre was right" << endl;
		//}
		//else
		//{
		//	cout << endl;

		//	printMaze(maze);

		//	for (int i = moves.size() - 1; i >= 0; i--) {
		//	cout << moves[i];
		//	}
		//}

	}


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
